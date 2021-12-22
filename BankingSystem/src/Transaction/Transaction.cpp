#include "./Transaction.h"

Transaction::Transaction(std::string _activity, double _currentBalance, double _deposit, double _withdraw, int _AccFrom, int _AccTo, std::string _description)
    :  activity {_activity}, currentBalance {_currentBalance}, deposit {_deposit}, withdraw {_withdraw}, accFrom { _AccFrom }, accTo { _AccTo }, description { _description }
{
    time_t now = std::time(0);
    auto tm = std::localtime(&now);

    this->dateTime = std::make_shared<DateTime>(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_sec, tm->tm_min, tm->tm_hour);   
}

std::shared_ptr<DateTime> & Transaction::GetDateTime()
{
    return this->dateTime;
}

double Transaction::GetCurrentBalacne() const
{
    return this->currentBalance;
}

double Transaction::GetDeposit() const
{
    return this->deposit;
}

double Transaction::GetWithdraw() const
{
    return this->withdraw;
}

int Transaction::GetAccFrom() const
{
    return this->accFrom;
}

int Transaction::GetAccTo() const
{
    return this->accTo;
}

std::string Transaction::GetDescription() const
{
    return this->description;
}

std::ostream& operator<<(std::ostream &os, Transaction &obj)
{
    os << "Type: " << obj.activity << '\n'
        << *(obj.dateTime)
        << "Balance: " << obj.currentBalance << '\n'
        << "Deposited: " << obj.deposit << '\n'
        << "Withdrawed: " << obj.withdraw << '\n'
        << "IBAN_FROM: " << obj.accFrom << '\n'
        << "IBAN_TO: " << obj.accTo << '\n'
        << "Decription: " << obj.description;

        return os;
}
