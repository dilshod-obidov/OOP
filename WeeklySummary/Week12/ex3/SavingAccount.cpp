#include "SavingAccount.h"

using namespace std;

void SavingAccount::Deposit(int money){
    if(money > 0){
        Account::Deposit(money*(100+m_InterestRate)*1.0/100);
    }
}