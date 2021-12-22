#ifndef _TRANSACTION_MANAGER_H
#define __TRANSACTION_MANAGER_H

#include "Account/AbstractAccount.h"

class TransactionManager
{
public:
    bool CreateTransaction(Account &, double, double, double, int, int, std::string);
};

#endif