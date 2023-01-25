/*
*****************************************************************************
                  Final Project Milestone 5
Full Name  : Priyansh Parikh
Student ID#: 158341214
Email      : pparikh8@myseneca.ca
Section    : NKK
Date       : 04/08/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Streamable.h"
using namespace std;
namespace sdds
{
    std::ostream &operator<<(std::ostream &os, const Streamable &src)
    {
        if (src) 
        {
            src.write(os);
        }
        return os;
    }
    std::istream &operator>>(std::istream &is, Streamable &src)
    {
        return src.read(is);
    }
    Streamable::~Streamable()
    {
        //This is an empty virtual destructor
    }
}