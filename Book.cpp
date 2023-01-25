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
#include "Book.h"
#include "Utils.h"
#include <cstring>
using namespace std;
namespace sdds
{
    Book::Book()
    {
        // safe empty state
    }
    Book::Book(const Book &src)
    {
        operator=(src);
    }
    Book &Book::operator=(const Book &src)
    {
        if (this != &src && src)
        {
            Publication::operator=(src);
            Utils::copyStr(author_name, src.author_name);
        }
        return *this;
    }
    Book::~Book()
    {
        delete[] author_name;
        author_name = nullptr;
    }
    char Book::type() const
    {
        return 'B';
    }
    void Book::set(int member_id)
    {
        Publication::set(member_id);
        Publication::resetDate();
    }
    void Book::setToDefault()
    {
        delete[] author_name;
        author_name = nullptr;
        Publication::setToDefault();
    }
    bool Book::conIO(std::ios &io) const
    {
        return Publication::conIO(io);
    }
    ostream &Book::write(ostream &ostr) const
    {

        Publication::write(ostr);
        if (conIO(ostr))
        {
            ostr << " ";
            ostr.setf(ios::left);
            if (strlen(author_name) > SDDS_AUTHOR_WIDTH)
            {
                int i = 0;
                while (i < SDDS_AUTHOR_WIDTH)
                {
                    ostr << author_name[i];
                    i++;
                }
            }
            else
            {
                ostr.width(SDDS_AUTHOR_WIDTH);
                ostr << author_name;
            }
            ostr << " |";
            ostr.unsetf(ios::left);
        }
        else
        {
            ostr << '\t' << author_name;
        }
        return ostr;
    }
    istream &Book::read(istream &istr)
    {
        char author[1000 + 1];
        setToDefault();
        Publication::read(istr);
        if (conIO(istr))
        {
            Utils::getChar(istr, '\n');
            cout << "Author: ";
            istr.getline(author, 1000 + 1);
        }
        else
        {
            Utils::getChar(istr, '\t');
            istr.get(author, 1000 + 1);
        }
        if (istr)
        {
            Utils::copyStr(author_name, author);
        }
        else
        {
            setToDefault();
        }
        return istr;
    }
    Book::operator bool() const
    {
        return (author_name && author_name[0] && Publication::operator bool());
    }
}

