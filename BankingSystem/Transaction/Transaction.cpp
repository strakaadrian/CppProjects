#include "Transaction.h"

Transaction::Transaction(double _currentBalance, double _deposit, double _withdraw, int _IBAN_from, int _IBAN_to, std::string _description)
    :   currentBalance {_currentBalance}, deposit {_deposit}, withdraw {_withdraw}, IBAN_from { _IBAN_from }, IBAN_to { _IBAN_to }, description { _description }
{
    time_t ttime = time(0);
    this->dateTime = localtime(&ttime);
}

tm * Transaction::GetDateTime()
{
    return this->dateTime;
}

double Transaction::GetCurrentBalacne()
{
    return this->currentBalance;
}

double Transaction::GetDeposit()
{
    return this->deposit;
}

double Transaction::GetWithdraw()
{
    return this->withdraw;
}

int Transaction::GetIBAN_from()
{
    return this->IBAN_from;
}

int Transaction::GetIBAN_to()
{
    return this->IBAN_to;
}

std::string Transaction::GetDescription()
{
    return this->description;
}

std::ostream& operator<<(std::ostream &os, Transaction &obj)
{
    os << "Date of creation: " << obj.dateTime->tm_hour << ":" << obj.dateTime->tm_min << ":"
        << obj.dateTime->tm_sec << '\n' 
        << "Balance: " << obj.currentBalance << '\n'
        << "Deposited: " << obj.deposit << '\n'
        << "Withdrawed: " << obj.withdraw << '\n'
        << "IBAN_FROM: " << obj.IBAN_from << '\n'
        << "IBAN_TO: " << obj.IBAN_to << '\n'
        << "Decription: " << obj.description;

        return os;
}
