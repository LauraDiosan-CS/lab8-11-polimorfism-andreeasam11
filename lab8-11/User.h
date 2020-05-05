#pragma once
#include <string>

using namespace std;

class User {
	private:
		string userName, password;
	public:
		User();
		User(string, string);
		string getUserName();
		string getPassword();
		void setUserName(string);
		void setPassword(string);
		bool operator==(const User&);
		~User();
};