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
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include <iostream>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"
namespace sdds
{
    class Publication : public Streamable
    {
        char *m_title{};
        char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        Publication(const Publication &src);
        Publication &operator=(const Publication &src);
        virtual ~Publication();
        virtual void setToDefault();
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
        bool conIO(std::ios &io) const;
        operator bool() const;
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char *title) const;
        operator const char *() const;
        int getRef() const;
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &istr);
    };
}
#endif