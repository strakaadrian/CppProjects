#ifndef _STACK_H_
#define _STACK_H_

#include "Exception.h"

#define MAX_CAPACITY 2048 // BYTES

// Stack with memory allocated on heap
template<typename T, int size>
class Stack
{
private:
    int top;
    int capacity;
    T *data;

public:
    // Constructor
    Stack();

    // Copy constructor
    Stack(const Stack<T, size> &);

    // Move constructor
    Stack(Stack<T, size> &&) noexcept;

    // Copy assign operator
    Stack<T, size> & operator=(const Stack<T, size> &);

    // Move assign operator
    Stack<T, size> & operator=(Stack<T, size> &&) noexcept;

    // Destructor
    ~Stack();

    // Check whether is stack empty
    bool IsEmpty();

    // Check whether is stack full
    bool IsFull();

    // Push element to stack
    void Push(T);

    // Pop element from stack
    T Pop();

    // Return top element
    T & Peek();
};

template<typename T, int size>
Stack<T, size>::Stack()
    : capacity {0}, top {-1}
{
    // Allocate memory for stack
    if (size < 0 || size*sizeof(T) > MAX_CAPACITY)
        throw StackException("Wrong stack size.");
    else
    {
        if (size == 0)
            this->data = nullptr;
        else
        {
            // Allocate memory
            this->data = new T[size];

            if (!this->data)
                throw StackException("Unable to allocate memory for stack.");
        }
    }        
}

template<typename T, int size>
Stack<T, size>::Stack(const Stack<T, size> &rhs)
{
    // Allocate memory for stack
    this->data = new T[size];

    if (!this->data)
        throw StackException("Unable to allocate memory for stack.");

    this->capacity = rhs.capacity;
    this->top = rhs.top;

    // Copy values
    for (size_t i = 0; i < this->capacity; i++)
        this->data[i] = rhs.data[i];
}

template<typename T, int size>
Stack<T, size>::Stack(Stack<T, size> &&rhs) noexcept
{
    this->capacity = rhs.capacity;
    this->top = rhs.top;
    this->data = rhs.data;

    rhs.data = nullptr;
    rhs.capacity = 0;
}

template<typename T, int size>
Stack<T, size> & Stack<T, size>::operator=(const Stack<T, size> &rhs)
{
    // Assign only when stack are different
    if (&rhs != this)
    {
        T *tmpData = new T[size];

        if (!tmpData)
            throw StackException("Unable to allocate memory for stack.");
        
        this->capacity = rhs.capacity;
        this->top = rhs.top;
        this->data = tmpData;

        // Copy data
        for (size_t i = 0; i < rhs.capacity; i++)
            this->data[i] = rhs.data[i];        
    }
    return *this;
}

template<typename T, int size>
Stack<T, size> & Stack<T, size>::operator=(Stack<T, size> &&rhs) noexcept
{
    if (&rhs != this)
    {
        this->capacity = rhs.capacity;
        this->top = rhs.top;
        this->data = rhs.data;

        rhs.data = nullptr;
        rhs.capacity = 0; 
    }
    return *this;
}

template<typename T, int size>
Stack<T, size>::~Stack()
{
    if (this->data)
        delete [] this->data;
}

template<typename T, int size>
bool Stack<T, size>::IsEmpty()
{
    return (capacity == 0) ? true : false;
}

template<typename T, int size>
bool Stack<T, size>::IsFull()
{
    return (capacity == size) ? true : false;
}

template<typename T, int size>
void Stack<T, size>::Push(T element)
{
    if (IsFull())
    {
        std::cout << "Stack is full\n";
        return;
    }

    // Add element to stack
    this->data[++top] = element;
    capacity++;
}

template<typename T, int size>
T Stack<T, size>::Pop()
{
    if (IsEmpty())
        throw StackException("Stack is empty.");
    else
    {
        capacity--;

        return this->data[top--];
    }
}

template<typename T, int size>
T & Stack<T, size>::Peek()
{
    if (IsEmpty())
        throw StackException("Stack is empty.");
    
    return this->data[top];
}

#endif