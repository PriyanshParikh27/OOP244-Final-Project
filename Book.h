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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "Publication.h"
namespace sdds
{
    class Book : public Publication
    {
        char *author_name{};

    public:
        Book();
        Book(const Book &src);
        Book &operator=(const Book &src);
        virtual ~Book();
        char type() const;
        void set(int member_id);
        operator bool() const;
        bool conIO(std::ios &io) const;
        void setToDefault();
        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
    };
}
#endif