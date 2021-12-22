#include "./TransactionManager.h"

namespace TransactionManager
{

    //! \brief Create transaction and add it into list of transactions
    //! \param acc - Account 
    //! \return void
    bool CreateTransaction(Account &acc, std::string activity, double deposit, double withdraw, int accFrom, int accTo, std::string description)
    {
        double balance = acc.GetBalance();

        try
        {   
            acc.GetTransaction().push_front(std::make_shared<Transaction>(activity, balance, deposit, withdraw, accFrom, accTo, description));

            if (acc.GetTransaction().front() == nullptr)
                throw;
        }
        catch(...)
        {
            std::cout << "Unable to create transaction." << std::endl;

            return false;
        }
        return true;
    }
}

