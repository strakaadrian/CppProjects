#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <iostream>
#include <string>

class StackException
{
private:
    std::string exc;
    
public:
    // Constructor
    StackException(std::string _exc)
        : exc {_exc} 
    {
    }

    // Get exception description
    void what() { std::cout << '\n' << this->exc << '\n'; }
};

#endif