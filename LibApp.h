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
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Publication.h"
#include "Menu.h"
namespace sdds
{
    class LibApp
    {
        char fileName[256]{};
        Publication *PPA[SDDS_LIBRARY_CAPACITY]{};
        int NOLP;
        int LLRN;
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        Menu m_publicationMenu;

    private:
        bool confirm(const char *message) const;
        void load();
        void save() const;
        Publication *getPub(int libRef) const;
        void newPublication();
        void checkOutPub();
        void returnPub();
        void removePublication();
        int search(int option = 1) const;
        bool exit() const;

    public:
        LibApp(const char *file, const char *Title = "Seneca Library Application", const char *exit = "Changes have been made to the data, what would you like to do?", const char *type = "Choose the type of publication:");
        void run();
        LibApp(const LibApp &src) = delete;
        LibApp &operator=(const LibApp &src) = delete;
        virtual ~LibApp();
    };
}
#endif
