#include <iostream>
#include "../lib/user.h"
#include "../lib/function.h"
#define EXIT "n"
#define LOG 1
#define PAS 2
#define MAIL 3
inline std::string User::get_login() const {
    return login;
}
inline std::string User::get_password() const {
    return password;
}
inline std::string User::get_mail() const {
    return mail_adds;
}

void Site::add_data_of_users() {
    std::string choice;
    do {
        std::cout << "input login user" << std::endl;
        check_login(login,users,std::getline);
        std::cout << "input password user" << std::endl;
        check_password(password, users,std::getline);
		std::cout << "input mail address user" << std::endl;
        check_mail(mail_adds,users);
        User user(login, password, mail_adds);
        users.push_back(user);
        std::cout << "wish to continue[y/n]?" << std::endl;
        check_choice(choice);
    } while (choice != EXIT);
}
void Site::view_data_of_users() {
    if(users.empty()) {
        std::cout<<"no users"<<std::endl;
        return;
    }
    for (int i = 0; i < users.size(); i++) {
        std::cout << "User " << i+1 << ": " << users[i].get_login() << ", " << users[i].get_password() << ", " << users[i].get_mail() << std::endl;
        }
}

void Site::view_data_of_user() {
    std::string choice;
    std::string login_user;
    if(users.empty())
    {
        std::cout<<"no users"<<std::endl;
        return;
    }
    do {
        std::cout<<"input login user"<<std::endl;
        std::getline(std::cin,login_user);
        int i=0;
        while (i < users.size() && login_user != users[i].get_login()){
            i++;
        }
        if (i <= users.size()){
            std::cout << "User " << i + 1 << ": " << users[i].get_login() << ", " << users[i].get_password() << ", "
                      << users[i].get_mail() << std::endl;
        }
        else{
            std::cout << "User not found" << std::endl;
        }
        std::cout<<"wish to continue[y/n]?"<<std::endl;
        check_choice(choice);
    }while(choice!=EXIT);
}

void Site::update_user_information() {
    std::string str;
    int user_index;
    int value;
    input_number(value,user_index,users);
    switch (value) {
        case LOG:
        {

            std::cout<<"input new login"<<std::endl;
            std::getline(std::cin,str);
            check_login(str,users,std::getline);
            users[user_index-1].login=str;
        }
            break;
        case PAS:{
            std::cout<<"input new password"<<std::endl;
            std::getline(std::cin,str);
            check_password(str,users,std::getline);
            users[user_index-1].password=str;
        }
            break;
        case MAIL:{
            std::cout<<"input new mail"<<std::endl;
			check_mail(str,users);
            users[user_index-1].mail_adds=str;
        }
            break;
        default:{}


    }
}



