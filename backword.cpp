#include"backword.h"
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <vector>

backword::backword() : QObject() {
    // 初始化代码（如果需要）
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

bool backword::save_user_message()
{
	return save_user_message();
}
bool backword::can_change_password()
{
	return can_change_password();
}
std::vector<history> backword::get_borrow_message()
{
	return get_borrow_message();
}
std::vector<book> backword::get_book_message()
{
	return get_book_message();
}

/*#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

// 用户数据结构体
struct user {
    std::string user_name;
    std::string user_key;
    std::string user_id;       // 主键
    std::string user_tele_num;
    float fine;
};

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

// 检查表是否存在
bool tableExists(sqlite3* db, const std::string& tableName) {
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

// 获取所有用户信息
std::vector<user> usermessage() {
    sqlite3* db;
    std::vector<user> users;
    
    // 打开数据库
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
        return users;
    }
    
    // 检查user表是否存在
    if (!tableExists(db, "user")) {
        std::cerr << "错误：数据库中不存在user表！" << std::endl;
        sqlite3_close(db);
        return users;
    }
    
    // 执行查询
    const char* sql = "SELECT * FROM user;";
    char* zErrMsg = 0;
    
    rc = sqlite3_exec(db, sql, userCallback, &users, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL错误: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    
    // 关闭数据库
    sqlite3_close(db);
    return users;
}

// 打印用户信息
void printUsers(const std::vector<user>& users) {
    std::cout << "\n用户总数: " << users.size() << std::endl;
    for (const auto& u : users) {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "用户名: " << u.user_name << std::endl;
        std::cout << "密码: " << u.user_key << std::endl;
        std::cout << "身份证号: " << u.user_id << std::endl;
        std::cout << "手机号: " << u.user_tele_num << std::endl;
        std::cout << "欠款金额: " << u.fine << std::endl;
    }
}

int main() {
    // 获取所有用户信息
    std::vector<user> allUsers = usermessage();
    
    // 打印用户信息
    printUsers(allUsers);
    
    return 0;
}*/

// 构造函数


// 图书借出功能
bool backword::borrow_out() {
    // TODO: 实现图书借出逻辑
    return false;
}

// 图书归还功能
bool backword::return_success() {
    // TODO: 实现图书归还逻辑
    return false;
}

// 存储用户反馈
bool backword::store_feedback(std::string feed_back) {
    // TODO: 实现反馈存储逻辑
    return false;
}

// 查看反馈
std::vector<std::string> backword::examine_feedback() {
    // TODO: 实现反馈查看逻辑
    return {};
}

// 计算罚款
bool backword::calcu_fine(float fine) {
    // TODO: 实现罚款计算逻辑
    return false;
}

// 支付罚款
float backword::pay_fine() {
    // TODO: 实现支付罚款逻辑
    return 0.0f;
}

// 重置罚款
bool backword::restore_fine() {
    // TODO: 实现罚款重置逻辑
    return false;
}

// 保存用户信息
bool backword::save_user_message(user save_user) {
    // TODO: 实现用户信息保存
    return false;
}

// 数据备份
bool backword::Data_backups() {
    // TODO: 实现数据备份逻辑
    return false;
}

// 数据恢复
bool backword::Data_recovery() {
    // TODO: 实现数据恢复逻辑
    return false;
}

// 保存图书信息
bool backword::save_book(std::string book_name, std::string author_name,
    std::string cata, std::string ISBN, std::string book_id) {
    // TODO: 实现图书信息保存
    return false;
}

// 获取图书信息
std::vector<book> backword::Get_book_message() {
    // TODO: 实现图书信息获取
    return {};
}

// 修改图书信息
bool backword::change_book_message(std::string new_book_name, std::string new_author_name,
    std::string new_cata, std::string new_ISBN, std::string book_id) {
    // TODO: 实现图书信息修改
    return false;
}

// 删除图书
bool backword::delete_book(std::string book_id) {
    // TODO: 实现图书删除逻辑
    return false;
}