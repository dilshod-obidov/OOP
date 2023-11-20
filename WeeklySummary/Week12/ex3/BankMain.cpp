// BANK PROJECT 0.4
#include <iostream>
#include "BankCommon.h"
#include "AccountHandler.h"

using namespace std;

int main(void) {
	AccountHandler manager;
	int choice;
	bool run = true;

	while (run) {
		manager.ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;

		switch (bank(choice)) {
		case bank::MAKE:
			manager.MakeAccount();
			break;
		case bank::DEPOSIT:
			manager.DepositMoney();
			break;
		case bank::WITHDRAW:
			manager.WithdrawMoney();
			break;
		case bank::INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case bank::EXIT:
			return 0;
		case bank::DELETE:
			manager.DeleteAccount();
			break;
		case bank::DELETEALL:
			manager.DeleteAllAcc();
			break;
		case bank::SEARCHACC:
			manager.SearchAcc();
			break;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}