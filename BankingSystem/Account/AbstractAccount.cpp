#include "AbstractAccount.h"

Account::Account(int _accNo, std::string _type, double _deposit)
    :   accNo { _accNo }, type { _type }, deposit { _deposit }, transactions { std::make_shared<std::list<Transaction *>> () }
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

std::shared_ptr<std::list<Transaction *>> Account::GetTransaction() const
{
    return this->transactions;
}

std::ostream & operator<<(std::ostream &os, const Account &obj)
{
    obj.Print(os);

    return os;
}