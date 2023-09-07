#include <iostream>
#include "user.h"
#define EXIT "n"
inline std::string User::get_login() const {
    return login;
}
inline std::string User::get_password() const {
    return password;
}
inline std::string User::get_mail() const {
    return mail_adds;
}


std::string& check_choice(std::string& choice){
    do {
        std::getline(std::cin,choice);
    }while(choice!="y"&&choice!="n");

}
std::string Site::add_data_of_users(std::string& password, std::string& login, std::string& mail_adss) {
    std::string choice;
   do {
        std::cout << "input login user" << std::endl;
        std::getline(std::cin, login);
        std::cout << "input password user" << std::endl;
        std::getline(std::cin, password);
        std::cout << "input mail address user" << std::endl;
        std::getline(std::cin, mail_adss);
        User user(login, password, mail_adss);
        users.push_back(user);
       std::cout<<"wish to continue[y/n]?"<<std::endl;
       check_choice(choice);
    } while (choice!=EXIT);
}
//std::string Site::add_data_of_users(std::string &password, std::string &login, std::string &mail_adss) {
//
//}

std::string Site::view_data_of_users() {
    std::string choice;
    if(users.empty()) {
        std::cout<<"no users"<<std::endl;
        return NULL;
    }
    do {
        for (int i = 0; i < users.size(); i++) {
            std::cout << "User " << i+1 << ": " << users[i].get_login() << ", " << users[i].get_password() << ", " << users[i].get_mail() << std::endl;
        }
        std::cout<<"wish to continue[y/n]?"<<std::endl;
        check_choice(choice);
    } while (choice!=EXIT);
}

std::string Site::view_data_of_user() {
    std::string choice;
    std::string login_user;
    if(users.empty())
    {
        std::cout<<"no users"<<std::endl;
        return NULL;
    }
    do {
        std::cout<<"input login user"<<std::endl;
        std::getline(std::cin,login_user);
        for (int i = 0; i < users.size(); i++) {
            if(login_user==get_login())
            std::cout << "User " << i+1 << ": " << users[i].get_login() << ", " << users[i].get_password() << ", " << users[i].get_mail() << std::endl;
        }
        std::cout<<"wish to continue[y/n]?"<<std::endl;
        check_choice(choice);
    }while(choice!=EXIT);
}



