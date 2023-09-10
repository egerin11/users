#ifndef USERS_SITE_FUNCTION_H
#define USERS_SITE_FUNCTION_H
#include "../lib/user.h"
#include "../lib/dymanic_array.h"
#define LEN str.length() < 6
#define SYMBOL '@'

#include <string>

void view_menu();
void print_user(const User& user);
void check_choice(std::string& choice);
int check_length(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&));
int parse_password_file(std::string& str);
int get_valid_int();
void check_mail(std::string& str);
void check_password(std::string& str);
bool check_array( const DynamicArray<User>& users, std::string& login);
void check_login(std::string& str,const DynamicArray<User>& users);
std::vector<std::string> extractWords(const std::string& input);
#endif
