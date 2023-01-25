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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
namespace sdds {
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"
    };
    const int  MIN_YEAR = 1500;
    class Date {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;

        bool validate();                  
        void errCode(int);                  // sets the error code
        int systemYear()const;              // returns the current system year
        bool bad()const;                    // return true if
        int mdays()const;                   // returns the number of days in current month

    public:
        Date();                             // creates a date with current date
        Date(int year, int mon, int day);                                       
        int errCode()const;                  // returns the error code or zero if date is valid
        const char* dateStatus()const;       // returns a string corresponding the current status of the date
        int currentYear()const;             // returns the m_CUR_YEAR value;
        void setToToday();                  // sets the date to the current date (system date)
        int daysSince0001_1_1()const;       // returns number of days passed since the date 0001/1/1
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
        operator bool() const;

    };
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);

    bool operator==(const Date& left, const Date& right);
    int operator-(const Date& left, const Date& right);
    bool operator<=(const Date& left, const Date& right);
    bool operator>=(const Date& left, const Date& right);
    bool operator>(const Date& left, const Date& right);
    bool operator!=(const Date& left, const Date& right);
    bool operator<(const Date& left, const Date& right);
    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;
}
#endif
