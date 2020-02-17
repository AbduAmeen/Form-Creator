#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class useraccess {
public:
	useraccess();
	~useraccess();
	
	//Functions:

	//Retrieves the name of user
	bool getName();
	//Retrieves password from the user
	bool getPass();
	//Signing process
	int checkForUser();
	//Creates a new txt file for the user
	bool makeNewUser();
	//Looks for their txt file
	bool lookForUser();
	//The function to create or log in users
	void decision();

private:
	//The user's name
	string name;
	//The user's password
	string password;
	//File object
	fstream file;
	//User wanting to start program
	char signup;
};

