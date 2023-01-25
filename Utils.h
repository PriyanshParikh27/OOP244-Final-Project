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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
namespace sdds {
    class Utils
    {
    public:
        Utils() = delete;
        static void getChar(std::istream& is, char ch);
        static void getChar(std::istream& is);
        static int getInt(std::istream& is, int min, int max, const char* message = nullptr);
        static void copyStr(char*& org, const char* source);
        static char* readInput(std::istream& is, char delimeter = '\n');
    };
}
#endif
