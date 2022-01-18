#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <iostream>
#include <string>
#include <exception>

class StackException : public std::runtime_error
{
public:
    StackException(const char* message)
        : std::runtime_error(message) 
    {
    }
};

#endif