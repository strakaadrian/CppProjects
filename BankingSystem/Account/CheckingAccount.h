#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <string>
#include <iostream>

#include "AbstractAccount.h"

class CheckingAccount : public Account 
{
public:
    CheckingAccount(int, std::string, double);

    virtual void Deposit(double) override;
    virtual void Withdraw(double) override;
    virtual std::ostream & Print(std::ostream &) const override;
};

#endif