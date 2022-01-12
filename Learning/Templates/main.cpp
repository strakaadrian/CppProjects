#include <iostream>
#include <cassert>
#include <string>
#include <initializer_list>

/////// Example 1

// Basic template class
template <typename T, int size>
class Array
{
protected:
    T data[size];
public:
    // Constructor
    Array(std::initializer_list<T> list)
    {
        int counter {};

        assert(size >= list.size());
        // Get all elements
        for (auto element : list)
        {
            this->data[counter] = element;
            counter++;
        }
    }

    T * GetArray() { return this->data; }
    T & operator[](int index) { return this->data[index]; }
};

// Defining non-member function template
template<typename T, int size>
void Print(Array<T, size> &arr)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << '\n';
    }
}

// Defining full function template specialization
template<>
void Print(Array<int, 10> &arr)
{
    std::cout << "Full function template specialization\n";
    for (size_t i = 0; i < 10; i++)
        std::cout << arr[i];
    std::cout << '\n';
}

// Defining partial specialized function template where size differs but type is always INT
template<int size>
void Print(Array<int, size> &arr)
{
    std::cout << "Partial function template specialization\n";
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
}

/////// Example 1 END

/////// Example 2

// Class specialization - storing 8 objects

template<class T>
class Storage 
{
private:
    T data[8];
public:
    // Set element to index
    void Set(int index, const T &value)
    {
        assert(index <= 8 && index >= 0);
        this->data[index] = value;
    }

    const T& GetElement(int index) const
    {
        assert(index <= 8 && index >= 0);
        return this->data[index];
    }
};

// Bool will be specialized, we dont need to store bool in 8 bits
template<>
class Storage<bool>
{
private:
    unsigned char data {};
public:
    // Set element to index
    void Set(int index, bool value)
    {
        unsigned char mask {static_cast<unsigned char>(1 << index)};
        
        assert(index <= 8 && index >= 0);

        // Check whether set or unset value
        if (value)
            // Set bit value
            this->data |= mask;
        else
            // Unset bit value
            this->data &= ~mask;
    }

    bool GetElement(int index) const
    {
        unsigned char mask {static_cast<unsigned char>(1 << index)};
        
        assert(index <= 8 && index >= 0);

        return this->data & mask;
    }

    unsigned char & GetData()
    {
        return this->data;
    }
};

/////// Example 2 END


/////// Example 3

// Partial template specialization for member function
// We can not specialize functons directly
// 1 - Use inheritence
// 2 - Specialize inherited class

template<class T>
class DataStorage_Base
{
protected:
    T data; // Very important data

public:
    // Constructor
    DataStorage_Base(T _data)
        : data {_data}
    {
    }

    T & GetName() const
    {
        return this->data;
    }

    void SetData(const T &newData)
    {
        this->data = newData;
    }

    // Print data
    void Print() const
    {
        std::cout << this->data << '\n';
    }
};

// Option will also be to specialize whole class, but then we are wasting code
// Create inheritance

// Nothing to do here
template<class T>
class DataStorage : public DataStorage_Base<T>
{
public:
    DataStorage(T _data)
        : DataStorage_Base<T>(_data)
    {
    }
};

// Make full specialization of inherited class
template<>
class DataStorage<int> : public DataStorage_Base<int>
{
public:
    DataStorage(int _data)
        : DataStorage_Base<int>(_data)
    {
    }

    void Print() const
    {
        std::cout << "Int number is: " << this->data << '\n';
    }
};

template<>
class DataStorage<char> : public DataStorage_Base<char>
{
public:
    DataStorage(char _data)
        : DataStorage_Base<char>(_data)
    {
    }

    void Print() const
    {
        std::cout << "Char value is: " << this->data << '\n';
    }
};

template<>
class DataStorage<bool> : public DataStorage_Base<bool>
{
public:
    DataStorage(bool _data)
        : DataStorage_Base<bool>(_data)
    {
    }

    void Print() const
    {
        std::cout << "Bool value is: " << this->data << '\n';
    }
};

/////// Example 3 END

int main()
{
    std::cout << "\nEXAMPLE 1\n\n";

    // EXAMPLE 1
    Array<int, 10> arrI {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<double, 10> arrD {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};

    Print<int>(arrI);
    Print(arrD);

    // Example 2
    std::cout << "\nEXAMPLE 2\n\n";

    // Test class specification for boolean
    Storage<bool> stB;
    stB.Set(1, true);
    stB.Set(3, true);

    std::cout << static_cast<int>(stB.GetData()) << '\n';

    // Test class with integer 
    Storage<int> stI;
    
    // Set values
    for (size_t i = 0; i < 8; i++)
        stI.Set(i, 10*i);
    
    // Print values
    for (size_t j = 0; j < 8; j++)
        std::cout << stI.GetElement(j) << ' ';

    // Example 3
    std::cout << "\n\nEXAMPLE 3\n\n";

    DataStorage<int> dsI {11};
    dsI.Print();

    DataStorage<char> dsCh {'C'};
    dsCh.Print();

    DataStorage<bool> dsB {true};
    dsB.Print();

    // Default data storage print will be used
    DataStorage<double> dsD {10.5};
    dsD.Print();

    return EXIT_SUCCESS;
}