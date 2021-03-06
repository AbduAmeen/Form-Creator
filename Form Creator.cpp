#include "pch.h"
#include "useraccess.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

//If you want to quit or restart the program
//return@ - true will close the program | false will restart
void restartEsc(bool& quit);

//The amount of times a function is called
void count();

//Close a program
void esc();


int main() {
	
	bool escv = false;
	
	useraccess *user = new useraccess();

	while (escv == false) {
		user->decision();
		restartEsc(escv);
	}
	delete user;
	esc();
}

void restartEsc(bool& quit) {
	char yorn = 'a';
	
	while ((yorn != 'N') || (yorn != 'n') || (yorn != 'Y') || (yorn != 'y')) {
		cout << "\n\nDo you want to restart?	[Y/N]\n";
		cin >> yorn;

		if ((yorn == 'y') || (yorn == 'Y')) {
			cout << "\nRestarting...\n";
			Sleep(500);
			cout << "3\t";
			Sleep(500);
			cout << "2\t";
			Sleep(500);
			cout << "1\t\n";
			Sleep(500);
			system("cls");
			return;
		}
		else if ((yorn == 'n') || (yorn == 'N')) {
			system("cls");
			quit = true;
			return;
		}
		else {
			cout << "Enter a valid answer";
			continue;
		}
	}
}

void esc() {
	cout << "Press ESC to close the program";

	while (GetAsyncKeyState(VK_ESCAPE) == 0); {
		exit(0);
	}
}

void count() {

}