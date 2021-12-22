#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int _accNo, std::string _type)
    : Account{_accNo, _type}
{
}

void CheckingAccount::Deposit(double amount)
{
    this->balance += amount;
}

bool CheckingAccount::Withdraw(double amount) 
{
    if ((this->balance - amount) > 0)
    {
        this->balance -= amount;

        return true;
    }
    return false;
}

std::ostream & CheckingAccount::Print(std::ostream &os) const
{
    os << "Account number: " << this->GetAccNo() << '\n'
        << "Type: " << this->GetType() << '\n'
        << "Balance: " << this->balance;

    return os;
}

