//
// Created by egerin on 10.09.23.
//

#ifndef USERS_SITE_SITE_H
#define USERS_SITE_SITE_H

#include "site_data_model.h"
#include <iostream>
#include "function.h"
#include <fstream>
#include <sstream>
#include <vector>

class Site {
public:
	Site() {}
	
	void menu();
	
	void remove();
	
	void view_users();
	
	void view_user();
	
	void user_add();
	
	void update_user();
	
	void parse_user();

private:
	SiteDataModel siteDataModel;
};


void Site::view_user() {
	std::string choice;
	std::string login_user;
	
	if (siteDataModel.no_users()) {
		std::cout << "No users" << std::endl;
		return;
	}
	do {
		std::cout << "Input login user: ";
		std::getline(std::cin, login_user);
		
		try {
			print_user(siteDataModel.get_user(login_user));
		} catch (const std::exception &e) {
			std::cerr << "No such user" << std::endl;
		}
		
		std::cout << "Wish to continue (y/n)? ";
		check_choice(choice);
		
	} while (choice != "n");
}


void Site::menu() {
	int value;
	
	do {
		view_menu();
		do {
			value = get_valid_int();
			if (value < 0 || value > 7) {
				std::cout << "invalid  value " << std::endl;
				continue;
			}
		} while (value < 0 || value > 7);
		switch (value) {
			case 1: {
				user_add();
			}
				break;
			
			case 2: {
				view_users();
			}
				break;
			case 3: {
				view_user();
			}
				break;
			case 4: {
				update_user();
			}
				break;
			case 5: {
				remove();
			}
				break;
			case 6: {
				parse_user();
			}
				break;
			default: {
			}
			
		}
	} while (value != 0);
	
	
}
void Site::remove() {
	if (siteDataModel.no_users()) {
		std::cout << "No users" << std::endl;
		return;
	}
	
	view_users();
	int id;
	do {
		id = get_valid_int();
	} while (id <= 0 || id > siteDataModel.get_all_users().get_size());
	
	User user = siteDataModel.get_user(id);
	
	if (siteDataModel.delete_user(user)) {
		std::cout << "user deleted successfully." << std::endl;
	} else {
		std::cout << "user not found." << std::endl;
	}
}


void Site::user_add() {
	std::string choice;
	std::string login;
	std::string password;
	std::string mail_adds;
	
	do {
		DynamicArray<User> users = siteDataModel.get_all_users();
		std::cout << "input login user" << std::endl;
		check_login(login, users);
		std::cout << "input password user" << std::endl;
		check_password(password);
		std::cout << "input mail address user" << std::endl;
		check_mail(mail_adds);
		User user(login, password, mail_adds);
		siteDataModel.add_user(user);
		std::cout << "wish to continue[y/n]?" << std::endl;
		check_choice(choice);
	} while (choice != "n");
	
}

void Site::view_users() {
	if (siteDataModel.no_users()) {
		std::cout << "no users" << std::endl;
		return;
	}
	
	DynamicArray<User> users = siteDataModel.get_all_users();
	
	for (int i = 0; i < users.get_size(); i++) {
		print_user(users[i]);
	}
}

void Site::update_user() {
	view_users();
	int id;
	do { id = get_valid_int(); } while (id <= 0 || id > siteDataModel.get_all_users().get_size());
	
	User user = siteDataModel.get_user(id);
	std::string choice;
	std::string login;
	std::string password;
	std::string mail_adds;
	do {
		DynamicArray<User> users = siteDataModel.get_all_users();
		std::cout << "input login user" << std::endl;
		check_login(login, users);
		std::cout << "input password user" << std::endl;
		check_password(password);
		std::cout << "input mail address user" << std::endl;
		check_mail(mail_adds);
		user.set_login(login);
		user.set_password(password);
		user.set_mail(mail_adds);
		siteDataModel.update_user(user);
		std::cout << "wish to continue[y/n]?" << std::endl;
		check_choice(choice);
	} while (choice != "n");
	
	
}

void Site::parse_user() {
	std::string buffer;
	std::ifstream file("data_of_users.txt");
	
	if (!file.is_open()) {
		std::cout << "unable to open the file." << std::endl;
		return;
	}
	
	while (std::getline(file, buffer)) {
		std::vector<std::string> words = extractWords(buffer);
		if(!words.empty()){
			User user(words[0],words[1],words[2]);
			siteDataModel.add_user(user);
		}
	}
	
	file.close();
}


#endif //USERS_SITE_SITE_H
