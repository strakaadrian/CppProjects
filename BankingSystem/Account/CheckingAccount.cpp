#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int _accNo, std::string _type, double _deposit)
    : Account{_accNo, _type, _deposit}
{
}

void CheckingAccount::Deposit(double amount)
{
    this->deposit += amount;
}

void CheckingAccount::Withdraw(double amount) 
{
    this->deposit -= amount;
}

std::ostream & CheckingAccount::Print(std::ostream &os) const
{
    os << "Account number: " << this->GetAccNo() << '\n'
        << "Type: " << this->GetType() << '\n'
        << "Money: " << this->deposit;

    return os;
}

