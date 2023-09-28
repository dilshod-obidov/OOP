#include <iostream>
#include "bank.h"
using namespace std;

int main(void) {
	int choice;

	while (1) {
		ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;

		switch (bank(choice)) {
		case bank::MAKE:
			MakeAccount();
			break;
		case bank::DEPOSIT:
			DepositMoney();
			break;
		case bank::WITHDRAW:
			WithdrawMoney();
			break;
		case bank::INQUIRE:
			ShowAllAccInfo();
			break;
		case bank::EXIT:
			return 0;
		case bank::DELETE:
			DeleteAccount();
			break;
		case bank::DELETEALL:
			DeleteAllAcc();
			break;
		case bank::SEARCHACC:
			SearchAcc();
			break;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}