#include <iostream>
#include "AccountHandler.h"

using namespace std;

int AccountHandler::GetAccIdx(int id) const{
    for (int i = 0; i < m_accNum; i++) {
		if (m_accArr[i]->getAccID() == id) {
			return i;
		}
	}
	return -1;
}

void AccountHandler::ShowMenu(void) const{
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

void AccountHandler::MakeAccount(void) {
    int id;
	char name[NAME_LEN];
	int balance;

	if (m_accNum >= MAX_ACC_NUM) {
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

	m_accArr[m_accNum] = new Account(id, balance, name);
	m_accNum++;
}

void AccountHandler::DepositMoney(void){
    int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;

	for (int i = 0; i < m_accNum; i++) {
		if (m_accArr[i]->getAccID() == id) {
            m_accArr[i]->Deposit(money);
			cout << "Deposit completed" << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}

void AccountHandler::WithdrawMoney(void){
    int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;

	for (int i = 0; i < m_accNum; i++) {
		if (m_accArr[i]->getAccID() == id) {
			m_accArr[i]->Withdraw(money);
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const{
    for(int i=0; i<m_accNum; i++){
        m_accArr[i]->ShowAccInfo();
    }
}

void AccountHandler::DeleteAccount(void){
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
	cout << "Name: " << m_accArr[GetAccIdx(id)]->getName() << endl;
	cout << "Balance: " << m_accArr[GetAccIdx(id)]->getBalance() << endl;

	if (Confirm()) {
		// delete
		for (int i = GetAccIdx(id); i < m_accNum - 1; i++) {
			m_accArr[i] = m_accArr[i + 1];
		}
		m_accNum--;
		
		cout << "Delete completed" << endl << endl;
		return;
	}
	else {
		cout << "Delete canceled" << endl << endl;
		return;
	}
}

void AccountHandler::DeleteAllAcc(void){
	cout << "[Delete All Accounts]" << endl;
	if (Confirm()) {
		// delete
		m_accNum = 0;
		cout << "Delete completed" << endl << endl;
		return;
	}
	else {
		cout << "Delete canceled" << endl << endl;
		return;
	}
}
bool AccountHandler::Confirm(void) const{
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

void AccountHandler::SearchAcc(void) const{
		int id;
		cout << "[Search Account]" << endl;
		cout << "Account ID: ";
		cin >> id;
		int idx = GetAccIdx(id);
		if (idx == -1) {
			cout << "This ID is not valid." << endl << endl;
			return;
		}
		cout << "Name: " << m_accArr[idx]->getName() << endl;
		cout << "Balance: " << m_accArr[idx]->getBalance() << endl << endl;
}