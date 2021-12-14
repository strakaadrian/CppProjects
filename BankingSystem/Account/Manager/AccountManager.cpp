#include "Account/Manager/AccountManager.h"

bool AccountManager::Deposit(Account &acc, double amount)
{
    if (amount <= 0)
        return false;
    else
        acc.Deposit(amount);

    return true;
}

bool AccountManager::Withdraw(Account &acc, double amount)
{

}

