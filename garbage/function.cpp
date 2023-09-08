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

static inline int check_vector_login(std::string& str, std::vector<User>& users){
    for(auto & user : users) {
        if (user.login == str)
        {
            std::cout<<"this login already exists"<<std::endl;
            return 0;
        }
    }
    return 1;
}

static int check_vector_password(std::string& str, std::vector<User>& users){
    for(auto & user : users) {
        if (user.password == str)
        {
            std::cout<<"this password already exists"<<std::endl;
            return 0;
        }
    }
    return 1;
}

void check_login(std::string& str,std::vector<User>& users,std::istream& (*getline_func)(std::istream&, std::string&))
{
    do {
        check_length(str,getline_func);
    } while (check_vector_login(str, users) != 1);
}

void check_password(std::string& str,std::vector<User>& users, std::istream& (*getline_func)(std::istream&, std::string&)) {
    do {
        check_length(str, getline_func);
    } while (parse_password_file(str) != 1|| check_vector_password(str,users)!=1);
}

int check_valid_mail(std::string& str){
    size_t pos=str.rfind(SYMBOL);
    if(pos != std::string::npos){
        std::string substr = str.substr(pos+1);
        std::istringstream iss(substr);
        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(iss,token,'.'))
        tokens.push_back(token);
        if(tokens.size() == 2 && tokens[0]=="gmail"&&tokens[1]=="com")
        {
            return 1;
        }else {
            std::cout<<"invalid mail"<<std::endl;
            return 0;
        }
    }else {
        std::cout<<"invalid mail"<<std::endl;
        return 0;
    }

}

void check_mail(std::string& str,std::vector<User>& users){

    do{
        std::getline(std::cin,str);
    } while ( check_valid_mail(str)!=1);
}
void input_number(int& value, int& user_index, std::vector<User>& users) {
    do {
        std::cout << "enter user index: ";
        user_index = get_valid_int();
        if (user_index <= 0 || user_index > users.size()) {
            std::cout << "invalid user index" << std::endl;
            continue;
        }
        std::cout << "enter user value: ";
        value = get_valid_int();
        if (value <= 0 || value > 3) {
            std::cout << "invalid user value" << std::endl;
            continue;
        }
    } while (user_index <= 0 || user_index > users.size() || value <= 0 || value > 3);
}
