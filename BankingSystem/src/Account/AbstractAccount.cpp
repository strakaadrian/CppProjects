#include "AbstractAccount.h"

Account::Account(int _accNo, std::string _type)
    :   accNo { _accNo }, type { _type }
{
}

int Account::GetAccNo() const
{
    return this->accNo;
}

std::string Account::GetType() const
{
    return this->type;
}

Transactions & Account::GetTransaction()
{
    return this->transactions;
}

double Account::GetBalance() const
{
    return this->balance;
}

std::ostream & operator<<(std::ostream &os, const Account &obj)
{
    obj.Print(os);

    return os;
}