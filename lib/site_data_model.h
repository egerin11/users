
#ifndef USERS_SITE_SITE_DATA_MODEL_H
#define USERS_SITE_SITE_DATA_MODEL_H

#include <utility>

#include "user.h"
#include "dymanic_array.h"

class SiteDataModel {

public:
	SiteDataModel() : last_id(0), users() {}
	
	bool add_user(User user);
	
	bool update_user(const User &new_user);
	
	bool delete_user(const User &user);
	
	User get_user(const int &id) const;
	
	User get_user(const std::string &login) const;
	
	bool no_users() const {
		return users.get_size() == 0;
	}
	
	const DynamicArray<User> get_all_users() const {
		return users;
	}

private:
	DynamicArray<User> users;
	int last_id;
	
};

bool SiteDataModel::add_user(User user) {
	for (int i = 0; i < users.get_size(); i++) {
		if (user == users[i]) {
			return false;
		}
	}
	
	last_id++;
	user.set_id(last_id);
	users.add(user);
	return true;
}

bool SiteDataModel::delete_user(const User &user) {
	int index_to_remove = -1;
	for (int i = 0; i < users.get_size(); i++) {
		if (user == users[i]) {
			index_to_remove = i;
			break;
		}
	}
	if (index_to_remove != -1) {
		users.remove(index_to_remove);
		last_id--;
		
		for (int j = 0; j < users.get_size(); j++) {
			users[j].set_id(j + 1);
		}
		return true;
	}
	
	
	return false;
}


User SiteDataModel::get_user(const int &id) const {
	for (int i = 0; i < users.get_size(); i++) {
		if (users[i].get_id() == id)
			return users[i];
	}
	
	throw std::exception();
}

bool SiteDataModel::update_user(const User &new_user) {
	for (int i = 0; i < users.get_size(); i++) {
		if (new_user.get_id() == users[i].get_id()) {
			users[i] = new_user;
			return true;
		}
	}
	return false;
}

User SiteDataModel::get_user(const std::string &login) const {
	for (int i = 0; i < users.get_size(); i++) {
		if (users[i].get_login() == login) {
			return users[i];
		}
	}
	
	throw std::exception();
}


#endif //USERS_SITE_SITE_DATA_MODEL_H
