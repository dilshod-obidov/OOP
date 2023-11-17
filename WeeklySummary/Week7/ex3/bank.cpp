#include <iostream>
#include <string>
#include <cctype>
#include "bank.h"
#include "Account.h"

using namespace std;

Account* accArr[MAX_ACC_NUM]; // Account array
int accNum = 0;      // # of accounts

void ShowMenu(void) {
	cout << "-----Menu------" << endl;
	cout << "1. Make Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Exit program" << endl;
	cout << "6. Delete account" << endl;
	cout << "7. Delete all accounts" << endl;
	cout << "8. Search account" << endl;
}

void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	if (accNum >= MAX_ACC_NUM) {
		cout << "Sorry! cannot make an accout anymore." << endl;
		return;
	}

	cout << "[Make Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	cout << endl;

	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl;
		return;
	}

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void DepositMoney(void) {
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			accArr[i]->SetBalance(accArr[i]->getBalance() + money);
			cout << "Deposit completed" << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}

void WithdrawMoney(void) {
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			if (accArr[i]->getBalance() < money) {
				cout << "Not enough balance" << endl << endl;
				return;
			}

			accArr[i]->SetBalance(accArr[i]->getBalance() - money);
			cout << "Withdrawal completed" << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}

void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		cout << "Account ID: " << accArr[i]->getAccID() << endl;
		cout << "Name: " << accArr[i]->getName() << endl;
		cout << "Balance: " << accArr[i]->getBalance() << endl << endl;
	}
}

int GetAccIdx(int id) {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			return i;
		}
	}
	return -1;
}

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
