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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{
    const int MAX_MENU_ITEMS = 20;
    class Menu;

    class MenuItem
    {
        char *menuItem{};

    private:
        friend class Menu;
        MenuItem(const char *items = nullptr);
        ~MenuItem();
        // Copy constructor and Copy assignment are deleted
        MenuItem(const MenuItem &src) = delete;
        MenuItem &operator=(const MenuItem &src) = delete;
        operator bool() const;
        operator const char *() const;
        std::ostream &display(std::ostream &ostr) const;
    };

    class Menu
    {
        MenuItem menuTitle;
        int menuNumItems;
        MenuItem *menuListofItems[MAX_MENU_ITEMS]{};

    public:
        Menu(const char *title = nullptr);
        ~Menu();
        // Copy constructor and Copy assignment are deleted
        Menu(const Menu &src) = delete;
        Menu &operator=(const Menu &src) = delete;
        std::ostream &displayOfTitle(std::ostream &ostr) const;
        std::ostream &displayOfMenu(std::ostream &ostr) const;
        unsigned int run() const;
        int operator~() const;
        Menu &operator<<(const char *menuitemConent);
        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        char *operator[](int index) const;
    };
    std::ostream &operator<<(std::ostream &ostr, const Menu &ro);
}
#endif