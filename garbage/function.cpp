#include<iostream>
#include "../lib/function.h"
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
void check_password(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&)) {
    do {
        check_length(str, getline_func);
    } while (parse_password_file(str) != 1);
}
//void check_mail(std::string& str, std::istream& (*getline_func)(std::istream&, std::string&)){
//
//}