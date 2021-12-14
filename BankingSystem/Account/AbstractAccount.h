#ifndef _ABSTRACT_ACCOUNT_H_
#define _ABSTRACT_ACCOUNT_H_

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <unordered_map>
#include "../Transaction/Transaction.h"

class Account
{
private:
    int accNo; // 8 digit number
    std::string type;
    std::shared_ptr<std::list<Transaction *>> transactions;

protected:
    double deposit;

public:
    Account(int, std::string, double);
    virtual void Deposit(double) = 0;
    virtual void Withdraw(double) = 0;
    virtual std::ostream & Print(std::ostream &) const = 0;
    virtual ~Account() noexcept = default;

    int GetAccNo() const;
    std::string GetType() const;
    std::shared_ptr<std::list<Transaction *>> GetTransaction() const;

    friend std::ostream & operator<<(std::ostream &, const Account &);
};

// Account id - key
// Shared pointer to Account - data
typedef std::unordered_map<int ,std::shared_ptr<Account *>> Accounts;

#endif