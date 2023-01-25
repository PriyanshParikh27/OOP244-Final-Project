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
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Book.h"
#include "Utils.h"
#include <cstring>
#include <fstream>
using namespace std;
namespace sdds
{
    LibApp::LibApp(const char *file, const char *Title, const char *exit, const char *type) : NOLP(0), LLRN(0), m_changed(false), m_mainMenu(Title), m_exitMenu(exit), m_publicationMenu(type)
    {
        strcpy(fileName, file);
        load();
        m_mainMenu << "Add New Publication" << "Remove Publication" 
                   << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        m_publicationMenu << "Book" << "Publication";
    }
    bool LibApp::exit() const
    {
        bool ok = false;
        if (m_changed)
        {
            switch (m_exitMenu.run())
            {
            case 1:
                save();
                break;
            case 2:
                ok = true;
                break;
            case 0:
                ok = !confirm("This will discard all the changes are you sure?");
                break;
            }
        }
        cout << endl;
        return ok;
    }
    void LibApp::run()
    {
        bool ok = true;
        do
        {
            switch (m_mainMenu.run())
            {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                ok = exit();
                break;
            }
        } while (ok);
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
    LibApp::~LibApp()
    {
        int i = 0;
        while (i < NOLP)
        {
            delete PPA[i];
            PPA[i] = nullptr;
            i++;
        }
    }
    void LibApp::load()
    {
        cout << "Loading Data" << endl;
        ifstream fistr(fileName);
        char c;
        int i;
        for (i = 0; fistr; i++)
        {
            fistr >> c;
            Utils::getChar(fistr, '\t');
            if (fistr)
            {
                if (c == 'P')
                    PPA[i] = new Publication;
                else if (c == 'B')
                    PPA[i] = new Book;
                if (PPA[i])
                {
                    fistr >> *PPA[i];
                    NOLP++;
                }
            }
        }
        LLRN = PPA[NOLP - 1]->getRef();
    }
    void LibApp::save() const
    {
        cout << "Saving Data" << endl;
        ofstream fostr(fileName);
        int i = 0;
        while (i < NOLP)
        {
            if (PPA[i]->getRef() != 0)
                fostr << *PPA[i] << endl;
            i++;
        }
    }
    int LibApp::search(int option) const
    {

        PublicationSelector selector("Select one of the following found matches:");
        char title[256]{};
        int a = 0;
        char type{};
        bool exit = false;

        switch (m_publicationMenu.run())
        {
        case 1:
            type = 'B';
            break;
        case 2:
            type = 'P';
            break;
        case 0:
            exit = true;
            cout << "Aborted!" << endl
                 << endl;
            break;
        }
        if (!exit)
        {

            cout << "Publication Title: ";
            cin.getline(title, 256, '\n');

            if (option == 1)
            {

                int i = 0;
                while (i < NOLP)
                {
                    (PPA[i]->getRef() != 0 && PPA[i]->type() == type &&
                     *PPA[i] == title) &&
                        selector << PPA[i];
                    i++;
                }
            }
            else if (option == 2)
            {
                int i = 0;
                while (i < NOLP)
                {
                    (PPA[i]->onLoan() && PPA[i]->getRef() != 0 &&
                     PPA[i]->type() == type && *PPA[i] == title) &&
                        selector << PPA[i];
                    i++;
                }
            }
            else if (option == 3)
            {
                int j = 0;
                while (j < NOLP)
                {
                    (!PPA[j]->onLoan() && PPA[j]->getRef() != 0 &&
                     PPA[j]->type() == type && *PPA[j] == title) &&
                        selector << PPA[j];
                    j++;
                }
            }
            if (selector)
            {
                selector.sort();
                a = selector.run();
                if (a != 0)
                    cout << *getPub(a) << endl;
                else
                    cout << "Aborted!" << endl
                         << endl;
            }
            else
                cout << "No matches found!" << endl
                     << endl;
        }
        return a;
    }
    bool LibApp::confirm(const char *message) const
    {
        Menu confirmM(message);
        confirmM << "Yes";
        return confirmM.run() == 1;
    }
    Publication *LibApp::getPub(int libRef) const
    {
        Publication *ptr{};
        for (int i = 0; i < NOLP && !ptr; i++)
        {
            if (PPA[i]->getRef() == libRef)
                ptr = PPA[i];
        }
        return ptr;
    }
    void LibApp::newPublication()
    {
        if (NOLP == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl
                 << endl;
        }
        else
        {
            cout << "Adding new publication to the library" << endl;
            Publication *newPub{};
            switch (m_publicationMenu.run())
            {
            case 1:
                newPub = new Book;
                break;
            case 2:
                newPub = new Publication;
                break;
            case 0:
                cout << "Aborted!" << endl
                     << endl;
                newPub = nullptr;
                break;
            }

            if (newPub)
            {
                cin >> *newPub;
                if (cin)
                {
                    if (confirm("Add this publication to the library?"))
                    {
                        if ((*newPub))
                        {
                            PPA[NOLP] = newPub;
                            PPA[NOLP]->setRef(++LLRN);
                            NOLP++;
                            m_changed = true;
                            cout << "Publication added" << endl
                                 << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!" << endl
                                 << endl;
                            delete newPub;
                        }
                    }
                    else
                    {
                        delete newPub;
                        cout << "Aborted!" << endl
                             << endl;
                    }
                }
                else
                {
                    delete newPub;
                    cin.ignore(1000, '\n');
                    cout << "Aborted!" << endl
                         << endl;
                }
            }
        }
    }
    void LibApp::checkOutPub()
    {
        int member = 0;
        cout << "Checkout publication from the library" << endl;
        int ref = search(3);
        if (ref != 0)
        {
            if (confirm("Check out publication?"))
            {
                cout << "Enter Membership number: ";
                member = Utils::getInt(cin, 10000, 99999, "Invalid membership number, try again: ");
                getPub(ref)->set(member);
                m_changed = true;
                cout << "Publication checked out" << endl
                     << endl;
            }
            else
            {
                cout << "Aborted!" << endl
                     << endl;
            }
        }
    }
    void LibApp::returnPub()
    {
        Date now;
        cout << "Return publication to the library" << endl;
        int a = search(2);
        if (a != 0)
        {
            if (confirm("Return Publication?"))
            {
                int lateDays = now - getPub(a)->checkoutDate();
                if (lateDays > SDDS_MAX_LOAN_DAYS)
                {
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << "Please pay $" << ((double)lateDays - (double)SDDS_MAX_LOAN_DAYS) * 0.5
                         << " penalty for being " << (lateDays - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
                }
                getPub(a)->set(0);
                m_changed = true;
                cout << "Publication returned" << endl
                     << endl;
            }
            else
            {
                cout << "Aborted!" << endl
                     << endl;
            }
        }
    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from the library" << endl;
        int a = search(1);
        if (a != 0)
        {
            if (confirm("Remove this publication from the library?"))
            {
                getPub(a)->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl
                     << endl;
            }
            else
            {
                cout << "Aborted!" << endl
                     << endl;
            }
        }
    }
}
