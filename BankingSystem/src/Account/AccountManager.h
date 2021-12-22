#ifndef _ACCOUNT_MANAGER_H
#define _ACCOUNT_MANAGER_H

#include <string>
#include "./AbstractAccount.h"

namespace AccountManager
{
    double GetAmount();
    void Deposit(const Accounts &);
    void Withdraw(const Accounts &);
    bool SendMoney(Account &, Account &);
    bool IsListEmpty(const Accounts &);
    std::shared_ptr<Account> ChooseAccountType(int);
    std::shared_ptr<Account> FindAccount(const Accounts &);
    bool CreateAccount(Accounts &);
    void PrintAccounts(const Accounts &);
    void PrintAccount(const Accounts *, std::shared_ptr<Account>);
}

#endif