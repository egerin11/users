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
        std::cout << "enter number" << std::endl;
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
bool check_array(const  DynamicArray<User>& users, std::string& login) {
	for (int i=0;i<users.get_size();i++) {
		if (users[i].get_login() == login) {
			std::cout << "this login already exists." << std::endl;
			return false;
		}
	}
	return true;
}
void check_login(std::string& str,const DynamicArray<User>& users){
	do{
		check_length(str,std::getline);
	} while (!check_array(users, str));
	
}


void check_password(std::string& str){
	do {
		check_length(str,std::getline);
	}while(parse_password_file(str)!=1);
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
std::vector<std::string> extractWords(const std::string& input) {
	std::vector<std::string> words;
	std::istringstream iss(input);
	std::string word;
	
	while (iss >> word) {
		words.push_back(word);
	}
	
	return words;
}
void check_mail(std::string& str){

    do{
        std::getline(std::cin,str);
    } while ( check_valid_mail(str)!=1);
}

void print_user(const User& user){
	std::cout << "User: " << user.get_id() << "\t" << user.get_login() << "\t" << user.get_mail() << "\t" << user.get_password() << std::endl;
}