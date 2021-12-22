#ifndef _ACCOUNT_MANAGER_H
#define _ACCOUNT_MANAGER_H

#include "Account/AbstractAccount.h"

class AccountManager
{
public:
    bool Deposit(Account &, double);
    bool Withdraw(Account &, double);
    bool SendMoney(Account &, Account &);
};

#endif