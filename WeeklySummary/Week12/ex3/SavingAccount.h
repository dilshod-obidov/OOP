#ifndef _SAVINGACCOUNT_H_
#define _SAVINGACCOUNT_H_

#include <iostream>
#include "Account.h"

using namespace std;

class SavingAccount : public Account{
private:
    int m_InterestRate;

public:
    SavingAccount(int id, int balance, char* name, int rate)
        : Account(id, balance*(100+rate)*1.0/100, name), m_InterestRate{rate} {}

    virtual void Deposit(int) override;
};

#endif // _SAVINGACCOUNT_H_