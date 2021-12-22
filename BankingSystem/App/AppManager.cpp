#include "./AppManager.h"


void AppManager::Run()
{
    Accounts accounts;
    bool running {true};

    while(running)
    {
        Menu(running, accounts);
    }
}

void AppManager::Menu(bool &running, Accounts &accounts)
{
    int option {};

    std::cout << std::endl << "**************************************" << std::endl;
    std::cout << "*************** MENU *****************" << std::endl << std::endl;
    
    std::cout << "1. Create account" << std::endl;
    std::cout << "2. Close application" << std::endl;

    do
    {
        std::cout << "Choose option: ";
        std::cin >> option;
        std::cout << std::endl;

        switch (option)
        {
        case 1:
            // Create account

            // TODO Create account
            
            break;
        
        case 2:
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