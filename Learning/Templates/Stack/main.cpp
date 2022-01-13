#include <iostream>
#include "Stack.h"

#define STACK_SIZE 5

int main()
{   
    try 
    {
        Stack<int, STACK_SIZE> stack;

        for (size_t i = 0; i < STACK_SIZE; i++)
            stack.Push(i * 10);

        Stack<int, STACK_SIZE> stackTmp;
        stackTmp = std::move(stack);

        for (size_t j = 0; j < STACK_SIZE; j++)
            std::cout << stackTmp.Pop() << ' ';
        
        for (size_t k = 0; k < STACK_SIZE; k++)
            std::cout << stack.Pop() << ' ';
    }
    catch (StackException &e)
    {
        e.what();
    }

    return EXIT_SUCCESS;
}