
#ifndef USERS_SITE_USER_H
#define USERS_SITE_USER_H


#include <string>
#include <utility>
#include <vector>
class User {
public:
    User()= default;;
    User(std::string login, std::string password, std::string mail_adds) {
        this->login=std::move(login);
        this->password=std::move(password);
        this->mail_adds=std::move(mail_adds);
    }
    [[nodiscard]] inline std::string get_login() const;
    [[nodiscard]] inline std::string get_password() const;
    [[nodiscard]] inline std::string get_mail() const;
    std::string login;
    std::string password;
    std::string mail_adds;;

};
class Site: User
{public:
    std::string add_data_of_users(std::string& password, std::string& login, std::string& mail_adss);
private:
    std::vector<User> users;
    std::string view_data_of_users();

   // std::string view_data_of_users(const std::vector<User>& users);
    std::string  view_data_of_user();
};
#endif
