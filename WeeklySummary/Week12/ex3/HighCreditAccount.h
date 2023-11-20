#include <iostream>
#include "SavingAccount.h"

using namespace std;

class HighCreditAccount : public SavingAccount{
private:
    int m_SpecialRate;

public:
    HighCreditAccount(int ID, int balance, char* name, int rate, int special);
    virtual void Deposit(int) override;
};