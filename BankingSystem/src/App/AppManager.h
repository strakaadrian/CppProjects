#ifndef _APP_MANAGER_H_
#define _APP_MANAGER_H_

#include "../Account/AbstractAccount.h"

namespace AppManager
{
    void Run();
    void Menu(bool &, Accounts &);
}

#endif