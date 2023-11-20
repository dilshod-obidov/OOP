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
    
}
void AccountHandler::DeleteAllAcc(void){

}
bool AccountHandler::Confirm(void) const{

}
void AccountHandler::SearchAcc(void) const{

}