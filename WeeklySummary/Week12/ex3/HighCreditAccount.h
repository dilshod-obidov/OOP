#ifndef _HIGHCREDITACCOUNT_H_
#define _HIGHCREDITACCOUNT_H_

#include <iostream>
#include "SavingAccount.h"

using namespace std;

class HighCreditAccount : public SavingAccount{
private:
    int m_SpecialRate;

public:
    HighCreditAccount(int id, int balance, char* name, int rate, int special)
        : SavingAccount(id, balance, name, rate+special), m_SpecialRate{rate+special} {}

    virtual void Deposit(int) override;
};

#endif // _HIGHCREDITACCOUNT_H_