#include <iostream>
#include <string>
#include <cctype>
#include "bank.h"
#include "Account.h"

using namespace std;

// delete account 
void DeleteAccount(void) {
	int id;

	cout << "[Delete Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	
	// check if the account exists
	if (GetAccIdx(id) == -1) {
		cout << "This ID is not valid." << endl << endl;
		return;
	}

	// confirm
	cout << "Name: " << accArr[GetAccIdx(id)]->getName() << endl;
	cout << "Balance: " << accArr[GetAccIdx(id)]->getBalance() << endl;

	if (Confirm()) {
		// delete
		
		for (int i = GetAccIdx(id); i < accNum - 1; i++) {
			accArr[i] = accArr[i + 1];
		}
		accNum--;
		
		cout << "Delete completed" << endl << endl;
		return;
	}
	else {
		cout << "Delete canceled" << endl << endl;
		return;
	}
	
	cout << "Invalid input" << endl << endl;
	return;
}

// delete all accounts
void DeleteAllAcc() {
	cout << "[Delete All Accounts]" << endl;
	if (Confirm()) {
		// delete
		accNum = 0;
		cout << "Delete completed" << endl << endl;
		return;
	}
	else {
		cout << "Delete canceled" << endl << endl;
		return;
	}
}
// confirm function
bool Confirm() {
	string ans;
	cout << "Are you sure? (y/n) ";
	cin >> ans;
	if (ans == "y") {
		return true;
	}
	else {
		return false;
	}
}

	void SearchAcc() {
		int id;
		cout << "[Search Account]" << endl;
		cout << "Account ID: ";
		cin >> id;
		int idx = GetAccIdx(id);
		if (idx == -1) {
			cout << "This ID is not valid." << endl << endl;
			return;
		}
		cout << "Name: " << accArr[idx]->getName() << endl;
		cout << "Balance: " << accArr[idx]->getBalance() << endl << endl;
	}
