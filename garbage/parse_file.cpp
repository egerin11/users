#include <fstream>
#include<iostream>
#include <sstream>
#include <vector>
#include "../lib/function.h"

int parse_password_file(std::string &str) {
	std::string buffer;
	std::ifstream file;
	file.open("commonplace_passwords.txt");
	if (file.is_open()) {
		while (getline(file, buffer)) {
			if (str == buffer) {
				std::cout << "your password is commonplace" << std::endl;
				file.close();
				return 0;
			}
		}
		file.close();
		return 1;
	} else {
		std::cout << "unable to open file" << std::endl;
	}
	return 0;
}

