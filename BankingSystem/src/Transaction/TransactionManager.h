#ifndef _TRANSACTION_MANAGER_H
#define __TRANSACTION_MANAGER_H

#include "../Account/AbstractAccount.h"

namespace TransactionManager
{
    bool CreateTransaction(Account &, std::string, double, double, int, int, std::string);
}

#endif