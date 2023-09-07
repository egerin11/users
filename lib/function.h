#ifndef USERS_SITE_FUNCTION_H
#define USERS_SITE_FUNCTION_H
#define LEN str.length() < 6

#include <string>
void check_choice(std::string& choice);
int check_length(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&));
int parse_password_file(std::string& str);
void check_password(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&));
#endif
