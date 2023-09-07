#ifndef USERS_SITE_FUNCTION_H
#define USERS_SITE_FUNCTION_H
#include "../lib/user.h"
#define LEN str.length() < 6

#include <string>
void check_choice(std::string& choice);
int check_length(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&));
int check_vector(std::string& str,std::vector<User>& users);
int parse_password_file(std::string& str);
int get_valid_int();
void check_login(std::string& str,std::vector<User>& users,std::istream& (*getline_func)(std::istream&, std::string&));
void check_password(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&));
#endif
