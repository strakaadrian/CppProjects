#include "./AccountManager.h"
#include "./SavingAccount.h"
#include "./CheckingAccount.h"
#include "../Transaction/TransactionManager.h"

#include <random>
#include <algorithm>
#include <sstream>

namespace AccountManager
{
    //! \brief Check input amount correctness
    //! \return double
    double GetAmount()
    {
        std::string input;
        double amount {};
        
        std::cout << "Enter amount in format (123) or (123.123): ";
        // Read amount of money to deposit
        std::cin >> amount;
        // Read rest of input from stdin
        getline(std::cin, input);

        // Check whether double was correctly entered
        if (!input.empty())
        {
            std::cout << "Error: Wrong number entered, please use format 123 or 123.123 ." << std::endl;
            return 0;
        }
        else if (amount <= 0)
        {
            std::cout << "Error: Can not deposit negative number or zero." << std::endl;
            return 0;     
        }
        return amount;
    }

    //! \brief Deposit money to account
    //! \param accs - List of accounts
    //! \return void
    void Deposit(const Accounts &accs)
    {
        double amount {};
        auto account = FindAccount(accs);

        // Get account based on account ID
        if (account == nullptr)
            return;

        // Get amount from user
        amount = GetAmount();

        if (amount != 0)
        {   
            // Get deposit description
            std::string desc;
            
            std::cout << "Write deposit description: ";
            std::getline(std::cin, desc);
            std::cout << std::endl;

            // Create transaction - DEPOSIT
            TransactionManager::CreateTransaction(*account, "Deposit", amount, 0, 0, (*account).GetAccNo(), desc);

            // Deposit money
            (*account).Deposit(amount);

            std::cout << "Deposit was successfull." << std::endl;
        }
        return;
    }

    //! \brief Deposit money to account
    //! \param accs - List of accounts
    //! \return Void
    void Withdraw(const Accounts &accs)
    {
        double amount {};
        auto account = FindAccount(accs);

        // Get account based on account ID
        if (account == nullptr)
            return;

        // Get amount from user
        amount = GetAmount();

        if (amount != 0)
        {   
            std::cout << std::endl;
            if ((*account).Withdraw(amount))
            {
                // Get deposit description
                std::string desc;
                
                std::cout << "Write withdraw description: ";
                std::getline(std::cin, desc);
                std::cout << std::endl;

                // Create transaction - DEPOSIT
                TransactionManager::CreateTransaction(*account, "Withdraw", 0, amount, (*account).GetAccNo(), 0, desc);

                std::cout << "Withdraw was successfull." << std::endl;
            }
            else
                std::cout << "No enought money to withdraw, balance is low." << std::endl;            
        }
        return;
    }

    //! \brief Check whether is list of accounts empty
    //! \param accs - List of accounts
    //! \return boolean
    bool IsListEmpty(const Accounts &accs)
    {
        // Get first element
        auto it = accs.begin();

        // Check whether exists at least 1 element
        if (it == accs.end())
        {
            std::cout << "No account has been created yet." << std::endl;
            return true;
        }
        return false;
    }

    //! \brief Load and create account
    //! \param accId - Account id (8 digits)
    //! \return std::shared_ptr<Account>
    std::shared_ptr<Account> ChooseAccountType(int accId)
    {
        std::shared_ptr<Account> acc = nullptr;
        int option {};

        // Show menu to stdout
        std::cout << "**************************************" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Checking account" << std::endl;
        std::cout << "2. Saving account" << std::endl;
        std::cout << "3. EXIT" << std::endl << std::endl << std::endl;
        std::cout << "Choose account type: ";

        // Load account type from stdin
        do
        {
            std::cin >> option;

            switch (option)
            {
            case 1:
                // Create checking account
                acc = std::make_shared<CheckingAccount>(accId, "Checking account");
                break;
            
            case 2:
                // Create saving account
                acc = std::make_shared<SavingAccount>(accId, "Saving account", FEE);
                break;

            case 3:
                // Exit application
                break;

            default:
                std::cout << "Wrong input, try again!" << std::endl;
                break;
            }
        } while (option < 1 || option > 3);

        return acc;
    }

    //! \brief Check whether account with specific id exists
    //! \param accs - List of accounts
    //! \return std::shared_ptr<Account>
    std::shared_ptr<Account> FindAccount(const Accounts &accs)
    {
        std::string numb {};
        std::stringstream stringToInt;
        int accID {};

        // Check whether exists at least 1 element
        if (IsListEmpty(accs))
            return nullptr;
        else
        {
            // Read account ID and print account informations
            while (true)
            {    
                std::cout << "Enter account ID (8 digits) | 0 - exit: ";
                std::cin >> numb;
                std::cout << std::endl;

                if (numb == "0")
                    return nullptr;
                else if (numb.length() < 8)
                {
                    std::cout << "Too few digits, try again!" << std::endl << std::endl;
                    continue;
                }
                else if (numb.length() > 8)
                {
                    std::cout << "Too many digits, try again!" << std::endl << std::endl;
                    continue;
                }
                else if (std::all_of(numb.begin(), numb.end(), ::isdigit) == false)
                {
                    std::cout << "Input can contain only digits, try again!" << std::endl << std::endl;
                    continue;
                }
                break;
            }

            // Transform string to int
            stringToInt << numb;
            stringToInt >> accID;

            // Find account with given account ID
            auto it = accs.find(accID);
            
            if (it == accs.end())
            {
                std::cout << "Account with id: " << accID << "does not exists !" << std::endl;
                return nullptr;
            }
            return it->second;
        }
    }

    //! \brief Create account and add to list of accounts
    //! \param accs - List of accounts
    //! \return boolean
    bool CreateAccount(Accounts &accs)
    {
        int accId {};

        while (true)
        {
            // Generate number 8 digits
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist6(10000000,99999999);

            accId = dist6(rng);

            // Check whether acc no already exists
            auto it = accs.find(accId);

            if (it != accs.end())
                continue;
            else
            {
                // Load account type from stdin and create account
                auto acc = ChooseAccountType(accId);

                if (acc == nullptr)
                {
                    std::cout << std::endl << "Account was not created!" << std::endl;
                    return false;
                }
                else
                    std::cout << std::endl << "Account was successfully created with ID: " << accId << std::endl;

                // Add account to list of accounts
                accs[accId] = acc;

                break;
            }
        }
        return true;
    }

    //! \brief Print all accounts in list
    //! \param accs - List of accounts
    //! \return void
    void PrintAccounts(const Accounts &accs)
    {
        // Check whether is list empty
        if (IsListEmpty(accs))
            return;
        else
        {
            // Loop throught list and print all accounts
            for (auto it = accs.begin(); it != accs.end(); it++)
                PrintAccount(nullptr, it->second);
        }
    }

    //! \brief Print specific account
    //! \param accs - List of accounts
    //! \return void
    void PrintAccount(const Accounts *accs, std::shared_ptr<Account> account)
    {
        if (account == nullptr)
            // Check whether specific account with account id exists
            account = FindAccount(*accs);

        if (account != nullptr)
        {
            std::cout << std::endl << "******************** Account ********************" << std::endl << std::endl;

            std::cout << *account << std::endl << std::endl;

            if (!(*account).GetTransaction().empty())
            {
                std::cout << "Account " << (*account).GetAccNo() << " transactions: " << std::endl << std::endl;

                std::for_each((*account).GetTransaction().begin(), (*account).GetTransaction().end(), [](std::shared_ptr<Transaction> trans){
                    std::cout << *trans << std::endl << std::endl;
                });
            }
            std::cout << std::endl << "*************************************************" << std::endl;
        }
    }
    
}
