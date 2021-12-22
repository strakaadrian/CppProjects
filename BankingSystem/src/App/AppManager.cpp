#include <memory>

#include "./AppManager.h"
#include "../Account/AccountManager.h"

namespace AppManager
{
    void Run()
    {
        Accounts accounts;
        bool running {true};

        while(running)
        {
            Menu(running, accounts);
        }
    }

    void Menu(bool &running, Accounts &accounts)
    {
        int option {};

        std::cout << std::endl << "**************************************" << std::endl;
        std::cout << "*************** MENU *****************" << std::endl << std::endl;
        
        std::cout << "1. Create account" << std::endl;
        std::cout << "2. Deposit money" << std::endl;
        std::cout << "3. Withdraw money" << std::endl;
        std::cout << "4. Print account" << std::endl;
        std::cout << "5. Print all accounts" << std::endl;
        std::cout << "6. Close application" << std::endl << std::endl;

        do
        {
            std::cout << "Choose option: ";
            std::cin >> option;
            std::cout << std::endl;

            switch (option)
            {
            case 1:
                // Create account
                AccountManager::CreateAccount(accounts);
                
                break;
            
            case 2:
                // Deposit money
                AccountManager::Deposit(accounts);

                break;
            
            case 3:
                // Withdraw money
                AccountManager::Withdraw(accounts);

                break;

            case 4:
                // Print account based on account ID
                AccountManager::PrintAccount(&accounts, nullptr);

                break;

            case 5:
                // Print all accounts
                AccountManager::PrintAccounts(accounts);

                break;
            
            case 6:
                // Close application
                std::cout << "Application is closing" << std::endl;

                running = false;
                break;
            
            default:
                std::cout << "Wrong input, try again" << std::endl;
                break;
            }
        } while (option < 1 && option > 5);
    }
}
