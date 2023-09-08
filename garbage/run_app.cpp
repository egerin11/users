
#include <iostream>
#include "../lib/function.h"
#define ADD 1
#define VIEW_USERS 2
#define VIEW_USER 3
#define UPDATE 4
#define EXIT 0


void view_menu() {

	std::cout<<"\t\tMENU"<<std::endl;
	std::cout<<"ADD USER 1"<<std::endl;
	std::cout<<"VIEW USERS 2"<<std::endl;
	std::cout<<"VIEW USER 3"<<std::endl;
	std::cout<<"UPDATE USER 4"<<std::endl;
	std::cout<<"EXIT 0"<<std::endl;
	
}



void menu() {
	Site site;
	view_menu();
	int value;
	do{
		do {
			value = get_valid_int();
			if (value < EXIT || value > UPDATE) {
				std::cout << "invalid  value " << std::endl;
				continue;
			}
		} while (value < EXIT || value > UPDATE);
		switch (value) {
			case ADD: {
				site.add_data_of_users();
			}
				break;
			
			case VIEW_USERS: {
				site.view_data_of_users();
			}
				break;
			case VIEW_USER: {
				site.view_data_of_user();
			}
				break;
			case UPDATE: {
				site.update_user_information();
			}
				break;
			default: {
			}
			
		}
	} while (value!=EXIT);
	
}
	

