#include <iostream>
#include "user.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Site site;
    std::string login;
    std::string password;
    std::string mail_adds;
    site.add_data_of_users(password,login,mail_adds);
    return 0;
}
