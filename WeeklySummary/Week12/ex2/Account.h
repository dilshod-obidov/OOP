#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <cstring>

using namespace std;

class Account{
private:
    int m_accID;
    int m_balance;
    char* m_cusName ;

public:
    Account(int id, int balance, char* name)
        : m_accID{id}, m_balance{balance} {
            m_cusName = new char[NAME_LEN];
            strcpy(m_cusName, name); // for VScode on Linux
            // strcpy_s(m_cusName, NAME_LEN, name) // for Visual Studio on Windows
        }
    // Deep Copy
    Account(const Account& cp) 
        : m_accID{cp.m_accID}, m_balance{cp.m_balance} {
            m_cusName = new char[NAME_LEN];
            strcpy(m_cusName, cp.m_cusName); // for VScode on Linux
            // strcpy_s(m_cusName, NAME_LEN, cp.m_cusName) // for Visual Studio on Windows
    }

    ~Account() {
        delete[]m_cusName;
    }

    int getAccID() const;
    int getBalance() const;
    const char* getName() const;
    void SetBalance(int);
    
    void Deposit(int);
    void Withdraw(int);
    void ShowAccInfo(void);
};

#endif // _ACCOUNT_H_