#include "HighCreditAccount.h"

using namespace std;

void HighCreditAccount::Deposit(int money){
    if(money > 0){
        Account::Deposit(money*(100+m_SpecialRate)*1.0/100);
    }
}