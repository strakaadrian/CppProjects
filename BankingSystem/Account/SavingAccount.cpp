#include "SavingAccount.h"

SavingAccount::SavingAccount(int _accNo, std::string _type, double _deposit, double _fee)
    : Account{_accNo, _type, _deposit}, fee {_fee}
{
}

void SavingAccount::Deposit(double amount)
{
    this->deposit += amount;
}

void SavingAccount::Withdraw(double amount) 
{
    this->deposit -= amount + this->fee;
}

std::ostream & SavingAccount::Print(std::ostream &os) const
{
    os << "Account number: " << this->GetAccNo() << '\n'
        << "Type: " << this->GetType() << '\n'
        << "Fee: " << this->fee << '\n'
        << "Money: " << this->deposit;

    return os;
}

double SavingAccount::GetFee() const
{
    return this->fee;
}

