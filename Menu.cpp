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
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds
{

    MenuItem::MenuItem(const char *items)
    {
        if (items != nullptr)
        {
            Utils::copyStr(menuItem, items);
        }
        else
            menuItem = nullptr;
    }
    MenuItem::~MenuItem()
    {
        delete[] menuItem;
    }
    MenuItem::operator bool() const
    {
        return (menuItem != nullptr);
    }
    MenuItem::operator const char *() const
    {
        return menuItem;
    }
    std::ostream &MenuItem::display(std::ostream &ostr) const
    {
        if (*this)
            ostr << menuItem;
        return ostr;
    }
    Menu::Menu(const char *title) : menuTitle(title), menuNumItems(0)
    {
    }
    Menu::~Menu()
    {
        for (int i = 0; i < menuNumItems; i++)
        {
            delete menuListofItems[i];
        }
    }
    std::ostream &Menu::displayOfTitle(std::ostream &ostr) const
    {
        return menuTitle.display(ostr);
    }
    std::ostream &Menu::displayOfMenu(std::ostream &ostr) const
    {
        if (menuTitle)
        {
            displayOfTitle(ostr);
            ostr << "";
            ostr << endl;
        }
        if (!(menuNumItems < 0))
        {
            int i = 0;
            while (i < menuNumItems)
            {
                cout.width(2);
                cout.setf(ios::right);
                cout << i + 1;
                cout << "- ";
                cout << menuListofItems[i]->menuItem << endl;
                i++;
            }
            cout << " 0- Exit" << endl;
            cout << "> ";
        }
        return ostr;
    }
    unsigned int Menu::run() const
    {
        displayOfMenu(cout);
        return Utils::getInt(cin, 0, menuNumItems);
    }
    int Menu::operator~() const
    {
        displayOfMenu(cout);
        return Utils::getInt(cin, 0, menuNumItems);
    }
    Menu &Menu::operator<<(const char *menuitemConent)
    {
        if (menuNumItems < MAX_MENU_ITEMS)
        {
            menuListofItems[menuNumItems] = new MenuItem(menuitemConent);
            menuNumItems++;
        }
        return *this;
    }
    Menu::operator int() const
    {
        return menuNumItems;
    }
    Menu::operator unsigned int() const
    {
        return menuNumItems;
    }
    Menu::operator bool() const
    {
        return (menuNumItems > 0);
    }
    char *Menu::operator[](int index) const
    {
        if (index >= menuNumItems)
        {
            index = index % menuNumItems;
        }
        return menuListofItems[index]->menuItem;
    }
    std::ostream &operator<<(std::ostream &ostr, const Menu &ro)
    {
        return ro.displayOfTitle(ostr);
    }
} 