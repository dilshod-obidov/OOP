#include <iostream>
#include "bank.h"
#include "Account.h"

using namespace std;

int Account::getAccID() const{
    return m_accID;
}
int Account::getBalance() const{
    return m_balance;
}
const char* Account::getName() const{
    return m_cusName;
}
void Account::SetBalance(int money){
    m_balance = money;
}
