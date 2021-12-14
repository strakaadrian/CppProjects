#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_

#include <string>
#include <iostream>

#include "AbstractAccount.h"

class SavingAccount : public Account 
{
private:
    double fee;
public:
    SavingAccount(int, std::string, double, double);

    virtual void Deposit(double) override;
    virtual void Withdraw(double) override;
    virtual std::ostream & Print(std::ostream &) const override;
    double GetFee() const;

};

#endif