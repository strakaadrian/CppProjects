#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include <iostream>
#include <string>
#include <ctime>
#include <memory>

#include "../Date/DateTime.h"

class Transaction
{
private:
    std::shared_ptr<DateTime> dateTime;
    std::string activity;
    double currentBalance;
    double deposit;
    double withdraw;
    int accFrom;
    int accTo;
    std::string description;

public:
    Transaction(std::string, double, double, double, int, int, std::string);
    
    // Getters
    std::shared_ptr<DateTime> & GetDateTime();
    std::string GetActivity() const;
    double GetCurrentBalacne() const;
    double GetDeposit() const;
    double GetWithdraw() const;
    int GetAccFrom() const;
    int GetAccTo() const;
    std::string GetDescription() const;

    friend std::ostream& operator<<(std::ostream &, Transaction &);
};

#endif