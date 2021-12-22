#include "SavingAccount.h"

SavingAccount::SavingAccount(int _accNo, std::string _type, double _fee)
    : Account{_accNo, _type}, fee {_fee}
{
}

void SavingAccount::Deposit(double amount)
{
    this->balance += amount;
}

bool SavingAccount::Withdraw(double amount) 
{
    if ((this->balance - amount - (amount * this->fee)) > 0)
    {
        this->balance -= amount + (amount * this->fee);

        return true;
    }
    return false;
}

std::ostream & SavingAccount::Print(std::ostream &os) const
{
    os << "Account number: " << this->GetAccNo() << '\n'
        << "Type: " << this->GetType() << '\n'
        << "Fee: " << this->fee << '\n'
        << "Balance: " << this->balance;

    return os;
}

double SavingAccount::GetFee() const
{
    return this->fee;
}

