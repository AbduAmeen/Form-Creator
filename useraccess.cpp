#include "pch.h"
#include "useraccess.h"


useraccess::useraccess() {}

bool useraccess::getName() {
	getchar();
	cout << "Enter your name: ";
	getline(cin, name);
	return true;
}

bool useraccess::getPass() {
	cout << "Enter your password: ";
	cin >> password;
	return true;
}

int useraccess::checkForUser() {
	bool x = false, z = false, y1 = false, a = false;
	char yorn = 'a',  y = 'a', input, input2;

	do {
		do {
			a = false;
			cout << "Do you want to sign up or log in? [Y/N] \n";
			cin >> yorn;

			switch (yorn) {
			case 'y':
				cout << "Press S for Sign up or press L for log in\n";
				cin >> input;
				y1 = true;
				break;
			case 'n':
				cout << "Are you sure?  [Y/N]\n";
				cin >> yorn;

				if (yorn == 'n') {
					system("cls");
					yorn = 'y';
					break;
				}
				else if (yorn == 'y') {
					exit(0);
				}
				else {
					cout << "Enter a valid choice\n";
				}
			case 'a':
				break;
			default:
				cout << "Enter a valid choice\n";
			}
		} while (!y1);

		do {

			switch (input) {
			case 's':
				cout << "Are you sure you want to sign up?  [Y/N]\n";
				cin >> input2;
				
				if ((input2 == 'y') || (input2 == 'y')) {
					y1 = false, a = true;
					break;
				}
				else if ((input2 == 'N') || (input2 == 'n')) {
					system("cls");
					y1 = false, a = true;
					break;
				}
				else {
					cout << "Enter a valid choice\n";
				}
			case 'S':
				cout << "Are you sure you want to sign up?  [Y/N]\n";
				cin >> input2;
			
				if ((input2 == 'y') || (input2 == 'y')) {
					z = true, a = true;
					break;
				}
				else if ((input2 == 'N') || (input2 == 'n')) {
					system("cls");
					y1 = false, a = true;
					break;
				}
				else {
					cout << "Enter a valid choice\n";
				}
				
			case 'l':
				cout << "Are you sure you want to log in?  [Y/N]\n";
				cin >> input2;
				
				if ((input2 == 'y') || (input2 == 'y')) {
					z = true, a = true;
					break;
				}
				else if ((input2 == 'N') || (input2 == 'n')) {
					system("cls");
					y1 = false, a = true;
					break;
				}
				else {
					cout << "Enter a valid choice\n";
				}
			case 'L':
				cout << "Are you sure you want to log in?  [Y/N]\n";
				cin >> input2;
				
				if ((input2 == 'y') || (input2 == 'y')) {
					z = true, a = true;
					break;
				}
				else if ((input2 == 'N') || (input2 == 'n')) {
					system("cls");
					y1 = false, a = true;
					break;
				}
				else {
					cout << "Enter a valid choice\n";
				}

			default: 
				cout << "Enter a valid choice\n";
				a = true;
			}
		} while (!a);
	} while (!z);

	do {
		if (yorn != 'n') {
			switch (input) {
			case 's':
				x = true;
				system("cls");
				return 1;
			case 'S':
				x = true;
				system("cls");
				return 1;
			case 'L':
				x = true;
				system("cls");
				return 2;
			case 'l':
				x = true;
				system("cls");
				return 2;
			default:
				cout << "Enter a valid choice/n";
				yorn = 'a';
			}
		}
		else {

		}
	} while (!x);
}

bool useraccess::makeNewUser() {
	getName();
	getPass();
	cout << "Creating user\n";
	file.open(name + ".txt", ios::in | ios::out | ios::app);
	
	if (!file.is_open()) {
		cout << "Error creating file\n";
	}
	else {
		cout << "File opened\n";
		file << password << endl;
		file.close();
		cout << "Created user\n";
	}
	return true;
}

bool useraccess::lookForUser()
{

	getName();
	getPass();
	string comp;
	char the;
	
	file.open(name + ".txt", ios::in | ios::out );
	
	if (!file.is_open()) {
		
		cout << "You have either entered you username or password incorrectly." << "\n\nWould you like to try again?  [Y/N]";
		do{
			cin >> the;

			if ((the == 'Y') || (the == 'y')) {
				system("cls");
				lookForUser();
			}
			else if ((the == 'N') || (the == 'n')) {
				return true;
			}
			else {
				cout << "Enter a valid choice";
				continue;
			}
		} while ((the != 'Y') || (the != 'y') || (the != 'N') || (the != 'n'));
	}
	else {
		cout << "File opened\n";
		getline(file, comp);
		if (password == comp) {
			cout << "You have successfully logged in.";
			return true;
		}
		else {
			cout << "You have either entered you username or password incorrectly." << "\n\nWould you like to try again?  [Y/N]";
			do {
			cin >> the;

			if ((the == 'Y') || (the == 'y')) {
				system("cls");
				lookForUser();
			}
			else if ((the == 'N') || (the == 'n')) {
				return true;
			}
			else {
				cout << "Enter a valid choice\n";
				continue;
				}
			} while ((the != 'Y') || (the != 'y') || (the != 'N') || (the != 'n'));	
		}
	}	
}

void useraccess::decision()
{
	int check = checkForUser();

	if (check == 1) {
		makeNewUser();
	}
	else if (check == 2) {
		lookForUser();
	}
	else {
		exit(0);
	}
}

useraccess::~useraccess() {
	file.close();
}