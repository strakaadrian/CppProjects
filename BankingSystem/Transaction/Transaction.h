#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include <iostream>
#include <string>
#include <ctime>

class Transaction
{
private:
    tm *dateTime;
    double currentBalance;
    double deposit;
    double withdraw;
    int IBAN_from;
    int IBAN_to;
    std::string description;

public:
    Transaction(double, double, double, int, int, std::string);
    
    // Getters
    tm *GetDateTime();
    double GetCurrentBalacne();
    double GetDeposit();
    double GetWithdraw();
    int GetIBAN_from();
    int GetIBAN_to();
    std::string GetDescription();

    friend std::ostream& operator<<(std::ostream &, Transaction &);
};

#endif