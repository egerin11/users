#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "../lib/function.h"
int get_valid_int() {
    std::string input;
    int value;
    bool is_valid = false;
    while (!is_valid) {
        std::cout << "enter number";
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (iss >> value && iss.eof()) {
            if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
                is_valid = true;
            } else {
                std::cout << "invalid input" << std::endl;
            }
        } else {
            std::cout << "invalid input" << std::endl;
        }
    }
    return value;
}
void check_choice(std::string& choice){
    do {
        std::getline(std::cin,choice);
    }while(choice!="y"&&choice!="n");
}
int check_length(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&)){

    do {
        getline_func(std::cin, str);
        if (LEN)
        std::cout<<"input correct string"<<std::endl;
    } while (LEN);
    return 1;
}
int check_vector(std::string& str,std::vector<User>& users){
    for(auto & user : users) {
        if (user.login == str)
        {
            std::cout<<"this login already exists"<<std::endl;
            return 0;
        }
    }
    return 1;
}
void check_login(std::string& str,std::vector<User>& users,std::istream& (*getline_func)(std::istream&, std::string&))
{
    do {
        check_length(str,getline_func);
    } while (check_vector(str,users)!=1);
}
void check_password(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&)) {
    do {
        check_length(str, getline_func);
    } while (parse_password_file(str) != 1);
}

//void check_mail(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&)){
//
//}