#ifndef _BANK_H_
#define _BANK_H_

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT, DELETE, DELETEALL, SEARCHACC};
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

void ShowMenu(void);
void MakeAccount(void) ;
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);
int GetAccIdx(int);
void DeleteAccount(void);
void DeleteAllAcc(void);
bool Confirm(void);
void SearchAcc(void);

#endif // _BANK_H_