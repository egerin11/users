#ifndef USERS_SITE_USER_H
#define USERS_SITE_USER_H


#include <string>
#include <utility>
#include <vector>

class User {
public:
	User() = default;
	
	User(const std::string& login, const std::string& password, const std::string& mail_adds)
	: m_login(login), m_password(password), m_mail_adds(mail_adds),
        m_id_setted(false) {}
	
	void set_login(const std::string& new_item) {
		m_login = new_item;
	}

	void set_password(const std::string& new_item) {
		m_password = new_item;
	}

	void set_mail(const std::string& new_item) {
		m_mail_adds = new_item;
	}

	std::string get_login() const {
		return m_login;
	}
	
	std::string get_password() const {
		return m_password;
	}
	
	std::string get_mail() const {
		return m_mail_adds;
	}

	int get_id() const {
		return m_id;
	}
	
	void set_id(int id) {
		//if (m_id_setted) return;
		m_id_setted = true;
		m_id = id;
	}
	
	bool operator==(const User& other) const {
		return m_login == other.m_login && m_password == other.m_password && m_mail_adds == other.m_mail_adds;
	}
	
	User& operator=(const User& other) {
		if (this != &other) {
			this->m_login = other.m_login;
			this->m_password = other.m_password;
			this->m_mail_adds = other.m_mail_adds;
			this->m_id = other.m_id;
            this->m_id_setted = other.m_id_setted;
		}
		return *this;
	}


private:
	bool m_id_setted;
	int m_id;
	std::string m_login;
	std::string m_password;
	std::string m_mail_adds;
};

#endif