#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <string>
#include <iostream>

#include "AbstractAccount.h"

#define FEE 0.05

class CheckingAccount : public Account 
{
public:
    CheckingAccount(int, std::string);

    virtual void Deposit(double) override;
    virtual bool Withdraw(double) override;
    virtual std::ostream & Print(std::ostream &) const override;
};

#endif