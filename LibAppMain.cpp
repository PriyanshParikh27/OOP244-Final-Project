// Final Project Milestone 5
// LipApp Main
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
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
#include "LibApp.h"
#include "Date.h"
int main() {
   sdds::sdds_day = 10;
   sdds::sdds_mon = 12;
   sdds::sdds_year = 2021;
   sdds::sdds_test = true;
   sdds::LibApp theApp("LibRecs.txt");
   theApp.run();
   return 0;
}