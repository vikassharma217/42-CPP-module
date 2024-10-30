#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>


template <typename T>
class Array
{
    private:
        T* element;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& rhs);
        Array& operator=(const Array& rhs);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        unsigned int size() const;
};

# include "Array.tpp"

#endif