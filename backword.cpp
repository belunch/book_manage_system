#include"backword.h"
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <vector>

backword::backword()
{

}

// 回调函数，用于收集用户数据
static int userCallback(void* data, int argc, char** argv, char** azColName) {
    std::vector<user>* users = static_cast<std::vector<user>*>(data);
    user u;
    for(int i = 0; i < argc; i++) {
        std::string colName = azColName[i];
        const char* value = argv[i] ? argv[i] : "NULL";
        if (colName == "user_name") u.user_name = value;
        else if (colName == "user_key") u.user_key = value;
        else if (colName == "user_id") u.user_id = value;
        else if (colName == "user_tele_num") u.user_tele_num = value;
        else if (colName == "fine") u.fine = atof(value);
    }
    users->push_back(u);
    return 0;
}

// 回调函数，用于收集借阅记录数据
static int recordCallback(void* data, int argc, char** argv, char** azColName) {
    std::vector<history>* records = static_cast<std::vector<history>*>(data);
    history h;
    for(int i = 0; i < argc; i++) {
        std::string colName = azColName[i];
        const char* value = argv[i] ? argv[i] : "NULL";
        if (colName == "recode_num") h.recode_num = value;
        else if (colName == "book_id") h.book_id = value;
        else if (colName == "user_name") h.user_name = value;
        else if (colName == "user_id") h.user_id = value;
        else if (colName == "boorow_day") {
            int y, m, d;
            sscanf_s(value, "%d-%d-%d", &y, &m, &d);
            h.boorow_day.year = y;
            h.boorow_day.month = m;
            h.boorow_day.day = d;
        }
        else if (colName == "return_day") {
            int y, m, d;
            sscanf_s(value, "%d-%d-%d", &y, &m, &d);
            h.return_day.year = y;
            h.return_day.month = m;
            h.return_day.day = d;
        }
    }
    records->push_back(h);
    return 0;
}

// 检查表是否存在
static bool tableExists(sqlite3* db, const std::string& tableName) {
    const char* sql = "SELECT 1 FROM sqlite_master WHERE type='table' AND name=?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "准备语句失败: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    sqlite3_bind_text(stmt, 1, tableName.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    bool exists = (rc == SQLITE_ROW);
    sqlite3_finalize(stmt);
    return exists;
}

std::vector<user> backword::usermessage()
{
    sqlite3* db;
    std::vector<user> users;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
        return users;
    }
    if (!tableExists(db, "user")) {
        std::cerr << "错误：数据库中不存在user表！" << std::endl;
        sqlite3_close(db);
        return users;
    }
    const char* sql = "SELECT * FROM user;";
    char* zErrMsg = 0;
    rc = sqlite3_exec(db, sql, userCallback, &users, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL错误: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return users;
}

bool backword::save_user_message(std::vector<user> users)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // 检查user表是否存在
    if (!tableExists(db, "user")) {
        std::cerr << "错误：数据库中不存在user表！" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // 预处理SQL语句
    const char* sql = "INSERT OR REPLACE INTO user (user_name, user_key, user_id, user_tele_num, fine) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "准备插入语句失败: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    for (const auto& u : users) {
        sqlite3_bind_text(stmt, 1, u.user_name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, u.user_key.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, u.user_id.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, u.user_tele_num.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 5, u.fine);
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            std::cerr << "插入用户信息失败: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return false;
        }
        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}

bool backword::can_change_password(std::string user_id, std::string new_key)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // 检查user表是否存在
    if (!tableExists(db, "user")) {
        std::cerr << "错误：数据库中不存在user表！" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // 更新用户密码
    const char* sql = "UPDATE user SET user_key = ? WHERE user_id = ?;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "准备更新语句失败: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, new_key.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, user_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "更新密码失败: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}

std::vector<history> backword::get_borrow_message()
{
    sqlite3* db;
    std::vector<history> records;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
        return records;
    }
    if (!tableExists(db, "record")) {
        std::cerr << "错误：数据库中不存在record表！" << std::endl;
        sqlite3_close(db);
        return records;
    }
    const char* sql = "SELECT * FROM record;";
    char* zErrMsg = 0;
    rc = sqlite3_exec(db, sql, recordCallback, &records, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL错误: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return records;
}

std::vector<book> backword::get_book_message()
{
    return get_book_message();
}
bool backword::borrow_out()
{
    // 实现借书逻辑
    return true;
}
bool backword::return_success()
{
    // 实现还书逻辑
    return true;
}
bool store_feedback(std::string feedback)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // 检查feed_back表是否存在
    if (!tableExists(db, "feed_back")) {
        std::cerr << "错误：数据库中不存在feed_back表！" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // 预处理SQL语句
    const char* sql = "INSERT INTO feed_back (user_feedback) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    // 生成唯一back_num，可以用时间戳或UUID等，这里简单用当前时间戳
    std::string back_num = std::to_string(static_cast<long long>(time(nullptr)));
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "准备插入语句失败: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, back_num.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, feedback.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "插入反馈信息失败: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}
bool backword::store_feedback(std::string feedback)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // 检查feed_back表是否存在
    if (!tableExists(db, "feed_back")) {
        std::cerr << "错误：数据库中不存在feed_back表！" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // 预处理SQL语句
    const char* sql = "INSERT INTO feed_back (back_num, back_message) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    std::string back_num = std::to_string(static_cast<long long>(time(nullptr)));
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "准备插入语句失败: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, back_num.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, feedback.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "插入反馈信息失败: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}
