#include"backword.h"
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <vector>

backword::backword()
{

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
        std::cerr << "�������ݿ��в�����user��" << std::endl;
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

// �û����ݽṹ��
struct user {
    std::string user_name;
    std::string user_key;
    std::string user_id;       // ����
    std::string user_tele_num;
    float fine;
};

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

// �����Ƿ����
bool tableExists(sqlite3* db, const std::string& tableName) {
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

// ��ȡ�����û���Ϣ
std::vector<user> usermessage() {
    sqlite3* db;
    std::vector<user> users;
    
    // �����ݿ�
    int rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        std::cerr << "�޷������ݿ�: " << sqlite3_errmsg(db) << std::endl;
        return users;
    }
    
    // ���user���Ƿ����
    if (!tableExists(db, "user")) {
        std::cerr << "�������ݿ��в�����user��" << std::endl;
        sqlite3_close(db);
        return users;
    }
    
    // ִ�в�ѯ
    const char* sql = "SELECT * FROM user;";
    char* zErrMsg = 0;
    
    rc = sqlite3_exec(db, sql, userCallback, &users, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL����: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    
    // �ر����ݿ�
    sqlite3_close(db);
    return users;
}

// ��ӡ�û���Ϣ
void printUsers(const std::vector<user>& users) {
    std::cout << "\n�û�����: " << users.size() << std::endl;
    for (const auto& u : users) {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "�û���: " << u.user_name << std::endl;
        std::cout << "����: " << u.user_key << std::endl;
        std::cout << "���֤��: " << u.user_id << std::endl;
        std::cout << "�ֻ���: " << u.user_tele_num << std::endl;
        std::cout << "Ƿ����: " << u.fine << std::endl;
    }
}

int main() {
    // ��ȡ�����û���Ϣ
    std::vector<user> allUsers = usermessage();
    
    // ��ӡ�û���Ϣ
    printUsers(allUsers);
    
    return 0;
}*/