/*
    Title: ArrayHelper.h
    Date: 2/1/2018
    Author: Will Westrich
    Purpose: Define the template class ArrayHelper.
*/
#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>

template<typename Type>
class ArrayHelper{
    private:
        Type* array;
        std::size_t arraySize;

    public:
        ArrayHelper();
        ArrayHelper(Type[], std::size_t);
        ArrayHelper(const ArrayHelper<Type>&); // copy constructor
        ArrayHelper<Type>& operator=(ArrayHelper<Type>); // copy assignment operator
        ~ArrayHelper();
        std::size_t getMax();
        std::size_t getMin();
        Type getTotal(Type[], std::size_t);
        Type getAverage();
        Type getValue(std::size_t) const;
};
#endif
