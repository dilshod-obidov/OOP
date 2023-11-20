#include <iostream>
#include "Account.h"

using namespace std;

class SavingAccount : public Account{
private:
    int m_InterestRate;

public:
    SavingAccount(int ID, int balance, char* name, int rate);
    virtual void Deposit(int) override;
};