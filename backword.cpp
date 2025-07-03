#include"backword.h"
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <vector>
#include <fstream>

backword::backword() : QObject() {
    // ��ʼ�����루�����Ҫ��
}

// �ص������������ռ��û�����
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

// �ص������������ռ����ļ�¼����
static int recordCallback(void* data, int argc, char** argv, char** azColName) {
    std::vector<history>* records = static_cast<std::vector<history>*>(data);
    history h;
    for(int i = 0; i < argc; i++) {
        std::string colName = azColName[i];
        const char* value = argv[i] ? argv[i] : "0";
        if (colName == "recode_num") h.recode_num = value;
        else if (colName == "book_id") h.book_id = value;
        else if (colName == "user_name") h.user_name = value;
        else if (colName == "user_id") h.user_id = value;
        else if (colName == "boorow_year") h.borrow_day.year = atoi(value);
        else if (colName == "boorow_month") h.borrow_day.month = atoi(value);
        else if (colName == "boorow_day") h.borrow_day.day = atoi(value);
        else if (colName == "return_year") h.return_day.year = atoi(value);
        else if (colName == "return_month") h.return_day.month = atoi(value);
        else if (colName == "return_day") h.return_day.day = atoi(value);
    }
    records->push_back(h);
    return 0;
}

// �ص������������ռ�ͼ������
static int bookCallback(void* data, int argc, char** argv, char** azColName) {
    std::vector<book>* books = static_cast<std::vector<book>*>(data);
    book b;
    for(int i = 0; i < argc; i++) {
        std::string colName = azColName[i];
        const char* value = argv[i] ? argv[i] : "";
        if (colName == "in_library") b.in_library = atoi(value);
        else if (colName == "book_name") b.book_name = value;
        else if (colName == "author") b.author = value;
        else if (colName == "category") b.category = value;
        else if (colName == "ISBN") b.ISBN = value;
        else if (colName == "id") b.id = value;
    }
    books->push_back(b);
    return 0;
}


// �����Ƿ����

// �ص������������ռ�����Ա����
static int adminCallback(void* data, int argc, char** argv, char** azColName) {
    std::vector<admin>* admins = static_cast<std::vector<admin>*>(data);
    admin a;
    for(int i = 0; i < argc; i++) {
        std::string colName = azColName[i];
        const char* value = argv[i] ? argv[i] : "NULL";
        if (colName == "admin_name") a.admin_name = value;
        else if (colName == "admin_key") a.admin_key = value;
        else if (colName == "admin_id") a.admin_id = value;
        else if (colName == "admin_tele_num") a.admin_tele_num = value;
    }
    admins->push_back(a);
    return 0;
}

// �����Ƿ����
static bool tableExists(sqlite3* db, const std::string& tableName) {
    const char* sql = "SELECT 1 FROM sqlite_master WHERE type='table' AND name=?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼�����ʧ��: " << sqlite3_errmsg(db) << std::endl;
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
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return users;
    }
    if (!tableExists(db, "user")) {
        std::cerr << "�������ݿ��в�����user����" << std::endl;
        sqlite3_close(db);
        return users;
    }
    const char* sql = "SELECT * FROM user;";
    char* zErrMsg = 0;
    rc = sqlite3_exec(db, sql, userCallback, &users, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL����: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return users;
}

std::vector<admin> backword::adminmessage()
{
    sqlite3* db;
    std::vector<admin> admins;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return admins;
    }
    if (!tableExists(db, "admin")) {
        std::cerr << "�������ݿ��в�����admin����" << std::endl;
        sqlite3_close(db);
        return admins;
    }
    const char* sql = "SELECT * FROM admin;";
    char* zErrMsg = 0;
    rc = sqlite3_exec(db, sql, adminCallback, &admins, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL����: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return admins;
}

bool backword::save_user_message(std::vector<user> users)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���user���Ƿ����
    if (!tableExists(db, "user")) {
        std::cerr << "�������ݿ��в�����user����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // Ԥ����SQL���
    const char* sql = "INSERT OR REPLACE INTO user (user_name, user_key, user_id, user_tele_num, fine) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
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
            std::cerr << "�����û���Ϣʧ��: " << sqlite3_errmsg(db) << std::endl;
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

bool backword::save_admin_message(std::vector<admin> admins)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���admin���Ƿ����
    if (!tableExists(db, "admin")) {
        std::cerr << "�������ݿ��в�����admin����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // Ԥ����SQL���
    const char* sql = "INSERT OR REPLACE INTO admin (admin_name, admin_key, admin_id, admin_tele_num) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    for (const auto& a : admins) {
        sqlite3_bind_text(stmt, 1, a.admin_name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, a.admin_key.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, a.admin_id.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, a.admin_tele_num.c_str(), -1, SQLITE_STATIC);
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            std::cerr << "�������Ա��Ϣʧ��: " << sqlite3_errmsg(db) << std::endl;
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
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���user���Ƿ����
    if (!tableExists(db, "user")) {
        std::cerr << "�������ݿ��в�����user����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // �����û�����
    const char* sql = "UPDATE user SET user_key = ? WHERE user_id = ?;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, new_key.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, user_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "��������ʧ��: " << sqlite3_errmsg(db) << std::endl;
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
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return records;
    }
    if (!tableExists(db, "record")) {
        std::cerr << "�������ݿ��в�����record����" << std::endl;
        sqlite3_close(db);
        return records;
    }
    const char* sql = "SELECT * FROM record;";
    char* zErrMsg = 0;
    rc = sqlite3_exec(db, sql, recordCallback, &records, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL����: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return records;
}

std::vector<book> backword::get_book_message() {
    sqlite3* db = nullptr;
    std::vector<book> books;

    // 打开数据库
    int rc = sqlite3_open("your_database.db", &db);
    if (rc != SQLITE_OK) {
        if (db) {
            std::cerr << "无法打开数据库: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }
        return books;
    }

    // 检查表是否存在
    if (!tableExists(db, "book")) {
        std::cerr << "错误: 数据库中不存在book表" << std::endl;
        sqlite3_close(db);
        return books;
    }

    // 执行查询
    const char* sql = "SELECT * FROM book;";
    char* zErrMsg = nullptr;
    rc = sqlite3_exec(db, sql, bookCallback, &books, &zErrMsg);

    // 错误处理
    if (rc != SQLITE_OK) {
        std::cerr << "SQL错误: " << (zErrMsg ? zErrMsg : "未知错误") << std::endl;
    }

    // 清理资源
    if (zErrMsg) sqlite3_free(zErrMsg);
    sqlite3_close(db);

    return books;
}


//std::vector<book> backword::get_book_message()//0���ڹݣ�1�ڹ�
//{
//    sqlite3* db;
//    std::vector<book> books;
//    int rc = sqlite3_open("your_database.db", &db);
//    if (rc) {
//        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
//        return books;
//    }
//    if (!tableExists(db, "book")) {
//        std::cerr << "�������ݿ��в�����book����" << std::endl;
//        sqlite3_close(db);
//        return books;
//    }
//    const char* sql = "SELECT * FROM book;";
//    char* zErrMsg = 0;
//    rc = sqlite3_exec(db, sql, bookCallback, &books, &zErrMsg);
//    if (rc != SQLITE_OK) {
//        std::cerr << "SQL����: " << zErrMsg << std::endl;
//        sqlite3_free(zErrMsg);
//    }
//    sqlite3_close(db);
//    return books;
//}

bool backword::borrow_out(std::string book_id, std::string user_id)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���book���Ƿ����
    if (!tableExists(db, "book")) {
        std::cerr << "�������ݿ��в�����book����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // �������Ƿ��ڹ�
    const char* check_sql = "SELECT in_library FROM book WHERE id = ?;";
    sqlite3_stmt* check_stmt;
    rc = sqlite3_prepare_v2(db, check_sql, -1, &check_stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼����ѯ���ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(check_stmt, 1, book_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(check_stmt);
    if (rc != SQLITE_ROW || sqlite3_column_int(check_stmt, 0) != 1) {
        // ���ڹݻ�δ�ҵ�
        sqlite3_finalize(check_stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(check_stmt);
    // ����book��in_libraryΪ0
    const char* update_sql = "UPDATE book SET in_library = 0 WHERE id = ?;";
    sqlite3_stmt* update_stmt;
    rc = sqlite3_prepare_v2(db, update_sql, -1, &update_stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(update_stmt, 1, book_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(update_stmt);
    sqlite3_finalize(update_stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "����ͼ��״̬ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    // ��ȡ��ǰϵͳʱ��
    time_t t = time(nullptr);
    struct tm now;
#ifdef _WIN32
    localtime_s(&now, &t);
#else
    localtime_r(&t, &now);
#endif
    int year = now.tm_year + 1900;
    int month = now.tm_mon + 1;
    int day = now.tm_mday;
    // ����record��
    const char* insert_sql = "INSERT INTO record (recode_num, book_id, user_name, user_id, boorow_year, boorow_month, boorow_day, return_year, return_month, return_day) VALUES (?, ?, ?, ?, ?, ?, ?, NULL, NULL, NULL);";
    sqlite3_stmt* insert_stmt;
    rc = sqlite3_prepare_v2(db, insert_sql, -1, &insert_stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    // recode_numʼ��Ϊ"1"
    sqlite3_bind_text(insert_stmt, 1, "1", -1, SQLITE_STATIC);
    sqlite3_bind_text(insert_stmt, 2, book_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(insert_stmt, 3, user_id.c_str(), -1, SQLITE_STATIC); // user_name�ֶκ��油��
    sqlite3_bind_text(insert_stmt, 4, user_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(insert_stmt, 5, year);
    sqlite3_bind_int(insert_stmt, 6, month);
    sqlite3_bind_int(insert_stmt, 7, day);
    rc = sqlite3_step(insert_stmt);
    sqlite3_finalize(insert_stmt);
    sqlite3_close(db);
    if (rc != SQLITE_DONE) {
        std::cerr << "������ļ�¼ʧ��: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

bool backword::return_success(std::string book_id, std::string user_id)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ��ѯδ�黹�Ľ��ļ�¼
    const char* select_sql = "SELECT recode_num FROM record WHERE book_id = ? AND user_id = ? AND return_year IS NULL AND return_month IS NULL AND return_day IS NULL ORDER BY boorow_year DESC, boorow_month DESC, boorow_day DESC LIMIT 1;";
    sqlite3_stmt* select_stmt;
    rc = sqlite3_prepare_v2(db, select_sql, -1, &select_stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼����ѯ���ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(select_stmt, 1, book_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(select_stmt, 2, user_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(select_stmt);
    if (rc != SQLITE_ROW) {
        // û��δ�黹��¼
        sqlite3_finalize(select_stmt);
        sqlite3_close(db);
        return false;
    }
    std::string recode_num = reinterpret_cast<const char*>(sqlite3_column_text(select_stmt, 0));
    sqlite3_finalize(select_stmt);
    // ��ȡ��ǰϵͳʱ��
    time_t t = time(nullptr);
    struct tm now;
#ifdef _WIN32
    localtime_s(&now, &t);
#else
    localtime_r(&t, &now);
#endif
    int year = now.tm_year + 1900;
    int month = now.tm_mon + 1;
    int day = now.tm_mday;
    // ����record���黹����
    const char* update_record_sql = "UPDATE record SET return_year = ?, return_month = ?, return_day = ? WHERE recode_num = ?;";
    sqlite3_stmt* update_record_stmt;
    rc = sqlite3_prepare_v2(db, update_record_sql, -1, &update_record_stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼�����½��ļ�¼���ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_int(update_record_stmt, 1, year);
    sqlite3_bind_int(update_record_stmt, 2, month);
    sqlite3_bind_int(update_record_stmt, 3, day);
    sqlite3_bind_text(update_record_stmt, 4, recode_num.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(update_record_stmt);
    sqlite3_finalize(update_record_stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "���½��ļ�¼ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    // ����book��in_libraryΪ1
    const char* update_book_sql = "UPDATE book SET in_library = 1 WHERE id = ?;";
    sqlite3_stmt* update_book_stmt;
    rc = sqlite3_prepare_v2(db, update_book_sql, -1, &update_book_stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼������ͼ��״̬���ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(update_book_stmt, 1, book_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(update_book_stmt);
    sqlite3_finalize(update_book_stmt);
    sqlite3_close(db);
    if (rc != SQLITE_DONE) {
        std::cerr << "����ͼ��״̬ʧ��: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

bool backword::store_feedback(std::string user_name, std::string feedback)
{
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���feedback���Ƿ����
    if (!tableExists(db, "feedback")) {
        std::cerr << "�������ݿ��в�����feedback����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // Ԥ����SQL���
    const char* sql = "INSERT INTO feedback (user_name, user_feedback) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, user_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, feedback.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "���뷴����Ϣʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}

std::vector<std::string> backword::examine_feedback(){
    sqlite3* db;
    std::vector<std::string> feedbacks;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return feedbacks;
    }
    // ���feedback���Ƿ����
    if (!tableExists(db, "feedback")) {
        std::cerr << "�������ݿ��в�����feedback����" << std::endl;
        sqlite3_close(db);
        return feedbacks;
    }
    const char* sql = "SELECT user_feedback FROM feedback;";
    char* zErrMsg = 0;
    rc = sqlite3_exec(db, sql, [](void* data, int argc, char** argv, char** azColName) -> int {
        auto feedbacks = static_cast<std::vector<std::string>*>(data);
        if (argc > 0 && argv[0]) {
            feedbacks->push_back(argv[0]);
        }
        return 0;
    }, &feedbacks, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL����: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return feedbacks;
}

bool backword::calcu_fine(float fine, std::string user_id) {
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���user���Ƿ����
    if (!tableExists(db, "user")) {
        std::cerr << "�������ݿ��в�����user����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // ֱ������ָ���û��ķ�����
    const char* sql = "UPDATE user SET fine = ? WHERE user_id = ?;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_double(stmt, 1, fine);
    sqlite3_bind_text(stmt, 2, user_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "���·�����ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}
bool backword::restore_fine(string user_id){
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���user���Ƿ����
    if (!tableExists(db, "user")) {
        std::cerr << "�������ݿ��в�����user����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // ��ָ���û��ķ���������Ϊ0
    const char* sql = "UPDATE user SET fine = 0 WHERE user_id = ?;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, user_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "���·�����ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}
bool backword::Data_backups() {
    std::ifstream src("your_database.db", std::ios::binary);
    std::ofstream dst("your_database_backup.db", std::ios::binary);
    if (!src || !dst) return false;
    dst << src.rdbuf();
    return src && dst;
}

bool backword::Data_recovery() {
    std::ifstream src("your_database_backup.db", std::ios::binary);
    std::ofstream dst("your_database.db", std::ios::binary);
    if (!src || !dst) return false;
    dst << src.rdbuf();
    return src && dst;
}
bool backword::save_book(std::string book_name, std::string author_name, std::string category, std::string ISBN, std::string book_id) {
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���book���Ƿ����
    if (!tableExists(db, "book")) {
        std::cerr << "�������ݿ��в�����book����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // Ԥ����SQL���
    const char* sql = "INSERT INTO book (book_name, author, category, ISBN, id, in_library) VALUES (?, ?, ?, ?, ?, 1);";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, book_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, author_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, category.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, ISBN.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, book_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "����ͼ����Ϣʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}
bool backword::change_book_message(std::string new_book_name, std::string new_author_name, std::string new_category, std::string new_ISBN, std::string book_id) {
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���book���Ƿ����
    if (!tableExists(db, "book")) {
        std::cerr << "�������ݿ��в�����book����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // ����ͼ����Ϣ
    const char* sql = "UPDATE book SET book_name = ?, author = ?, category = ?, ISBN = ? WHERE id = ?;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼���������ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, new_book_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, new_author_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, new_category.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, new_ISBN.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, book_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "����ͼ����Ϣʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}
bool backword::delete_book(std::string book_id) {
    sqlite3* db;
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    // ���book���Ƿ����
    if (!tableExists(db, "book")) {
        std::cerr << "�������ݿ��в�����book����" << std::endl;
        sqlite3_close(db);
        return false;
    }
    // ɾ��ͼ���¼
    const char* sql = "DELETE FROM book WHERE id = ?;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "׼��ɾ�����ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    sqlite3_bind_text(stmt, 1, book_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "ɾ��ͼ���¼ʧ��: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}
