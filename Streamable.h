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
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds
{
    class Streamable
    {
    public:
        virtual std::ostream &write(std::ostream &os) const = 0;
        virtual std::istream &read(std::istream &is) = 0;
        virtual bool conIO(std::ios &io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable();
    };
    std::ostream &operator<<(std::ostream &os, const Streamable &src);
    std::istream &operator>>(std::istream &is, Streamable &src);
}
#endif