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
void Account::Deposit(int money){
    if(money > 0){
        m_balance += money;
    }
}
void Account::Withdraw(int money){
    if(money < 0 || money > m_balance){
        cout << "Not enough balance" << endl << endl;
    }
    else{
        m_balance -= money;
        cout << "Withdrawal completed" << endl << endl;
    }
}
void Account::ShowAccInfo(void){
    cout << "Account ID: " << m_accID << endl;
    cout << "Name: " << m_cusName << endl;
    cout << "Balance: " << m_balance << endl << endl;
}
