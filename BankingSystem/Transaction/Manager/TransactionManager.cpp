#include "Transaction/Manager/TransactionManager.h"

bool TransactionManager::CreateTransaction(Account &acc, double balance, double deposit, double withdraw, int IBAN_from, int IBAN_to, std::string description)
{
    Transaction *trans = nullptr;

    try
    {   
        trans = new Transaction { balance, deposit, withdraw, IBAN_from, IBAN_to, description };
        acc.GetTransaction().get()->push_front(trans);   
    }
    catch(...)
    {
        if (trans != nullptr)
            delete trans;
        
        std::cout << "Unable to create transaction." << std::endl;

        return false;
    }
    return true;
}