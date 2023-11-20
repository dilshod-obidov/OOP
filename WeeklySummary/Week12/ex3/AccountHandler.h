#ifndef _ACCOUNTHANDLER_H_
#define _ACCOUNTHANDLER_H_

#include <iostream> 
#include "Account.h"
#include "BankCommon.h"

using namespace std;

class AccountHandler{
private:
    Account* m_accArr[MAX_ACC_NUM];
    int m_accNum = 0;

    int GetAccIdx(int id) const;
    bool Confirm(void) const;
    
public:
    ~AccountHandler(){
        for(int i=0; i<m_accNum; i++){
            delete m_accArr[i];
        }
    }

    void ShowMenu(void) const;
    void MakeAccount(void) ;
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    void DeleteAccount(void);
    void DeleteAllAcc(void);
    void SearchAcc(void) const;

};

#endif // _ACCOUNTHANDLER_H_