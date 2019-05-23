/*
 * Title: ArrayHelper.cpp
 * Date: 2/1/2018
 * Author: Will Westrich
 * Purpose: Define class functions for ArrayHelper.
 *          Functions will perform common array tasks.
*/

#include "ArrayHelper.h"

// Default constructor beacuse why not?
template<typename Type>
ArrayHelper<Type>::ArrayHelper() : arraySize(0), array(nullptr){}

template<typename Type>
ArrayHelper<Type>::ArrayHelper(Type oArray[], std::size_t size) : arraySize(size), array(new Type[size]){

    for(std::size_t i=0; i < size; ++i)
        array[i] = oArray[i];
}

// Copy constructor is defined because destructor was also defined.
template<typename Type>
ArrayHelper<Type>::ArrayHelper(const ArrayHelper<Type>& other){

    array = new Type[other.arraySize];

    for(std::size_t i=0; i < other.arraySize; ++i)
        array[i] = other.array[i];
}

// Copy assignment operator was defined because destructor was defined.
template<typename Type>
ArrayHelper<Type>& ArrayHelper<Type>::operator=(ArrayHelper<Type> other){

    Type* tempArray = new Type[other.arraySize];
    tempArray = other.array;
    delete[] array;
    array = tempArray;

    arraySize = other.arraySize;

    return *this;
}

template<typename Type>
ArrayHelper<Type>::~ArrayHelper(){

    delete[] array;
}

template<typename Type>
std::size_t ArrayHelper<Type>::getMax(){

    Type tempMax = array[0];
    std::size_t index = 0;

    for(std::size_t i = 1; i < arraySize; ++i)
        if(array[i] > tempMax){
            tempMax = array[i];
            index = i;
        }

    return index;
}

template<typename Type>
std::size_t ArrayHelper<Type>::getMin(){

    Type tempMin = array[0];
    std::size_t index = 0;

    for(std::size_t i = 1; i < arraySize; ++i)
        if(array[i] < tempMin){
            tempMin = array[i];
            index = i;
        }

    return index;
}

template<typename Type>
Type ArrayHelper<Type>::getTotal(Type arr[], std::size_t s){

    Type total = 0;

    for(std::size_t i = 0; i < s; ++i)
        total += arr[i];

    return total;
}

template<typename Type>
Type ArrayHelper<Type>::getAverage(){

    return (getTotal(array, arraySize) / arraySize);
}

template<typename Type>
Type ArrayHelper<Type>::getValue(std::size_t i) const{

    return array[i];
}

// Explicitly instantiate template class.
template class ArrayHelper<int>;
template class ArrayHelper<double>;
