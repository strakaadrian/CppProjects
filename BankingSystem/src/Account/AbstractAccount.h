#ifndef _ABSTRACT_ACCOUNT_H_
#define _ABSTRACT_ACCOUNT_H_

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <unordered_map>
#include "../Transaction/Transaction.h"

class Account;

// Account id - key
// Shared pointer to Account - data
typedef std::unordered_map<int ,std::shared_ptr<Account>> Accounts;
typedef std::list<std::shared_ptr<Transaction>> Transactions;

class Account
{
private:
    int accNo; // 8 digit number
    std::string type;
    Transactions transactions;

protected:
    double balance {}; // Default 0

public:
    Account(int, std::string);
    virtual void Deposit(double) = 0;
    virtual bool Withdraw(double) = 0;
    virtual std::ostream & Print(std::ostream &) const = 0;
    virtual ~Account() noexcept = default;

    int GetAccNo() const;
    std::string GetType() const;
    Transactions & GetTransaction();
    double GetBalance() const;

    friend std::ostream & operator<<(std::ostream &, const Account &);
};

#endif