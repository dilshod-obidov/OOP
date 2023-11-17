#include <iostream>
#include <cstring>
#include "bank.h"

using namespace std;

class Account{
private:
    int m_accID;
    int m_balance;
    char m_cusName[NAME_LEN];

public:
    Account(int id, int balance, char* name)
        : m_accID{id}, m_balance{balance} {
            strcpy(m_cusName, name);
        }
    int getAccID() const;
    int getBalance() const;
    const char* getName() const;
    void SetBalance(int);

};