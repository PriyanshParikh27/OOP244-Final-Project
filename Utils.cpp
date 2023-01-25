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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include "Utils.h"
namespace sdds
{
    void Utils::getChar(std::istream& is, char ch)
    {
        if (is.peek() == ch)
            is.get();
    }
    void Utils::getChar(std::istream& is)
    {
        if (isdigit(is.peek()))
        {
            is.setstate(std::ios::failbit);
        }
        else
        {
            is.get();
        }
    }
    int Utils::getInt(std::istream& is, int min, int max, const char* message)
    {
        int res;
        bool flag = false;
        while (!flag)
        {
            is >> res;
            if (is && is.peek() == '\n')
            {
                if (res >= min && res <= max)
                {
                    flag = true;
                }
                else
                {
                    if (message)
                        std::cout << message;
                }
            }
            else
            {
                is.clear();
                if (message)
                    std::cout << message;
            }
            is.ignore(1000, '\n');
        }
        return res;
    }
    void Utils::copyStr(char*& org, const char* source)
    {
        delete[] org;
        org = new char[strlen(source) + 1];
        strcpy(org, source);
    }
    char* Utils::readInput(std::istream& is, char delimeter)
    {
        char* str{};
        std::string toRead;
        getline(is, toRead, delimeter);
        if (is)
        {
            str = new char[strlen(toRead.c_str()) + 1];
            strcpy(str, toRead.c_str());
        }
        return str;
    }
}
