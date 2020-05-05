#include "User.h"

User::User() {
}

User::User(string userName, string password) {
	this->userName = userName;
	this->password = password;
}

string User::getUserName() {
	return userName;
}

string User::getPassword() {
	return password;
}

void User::setUserName(string newUserName) {
	userName = newUserName;
}

void User::setPassword(string newPassword) {
	password = newPassword;
}

bool User::operator==(const User& u) {
	return (userName == u.userName) and (password == u.password);
}

User::~User() {
}