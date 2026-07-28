#include "customer.cpp"
#include "user.h"
#include "manager.cpp"
#include "customer.h"
#include "manager.h"
#include "Order.h"
#include "Order.cpp"
#include <bits/stdc++.h>

using namespace std;
// This function displays the main menu and allows the user to choose between customer and manager functionalities.
void User::menu() {
    int choice;
    do {
        cout << "\033[36m";
        cout << "========================================\n";
        cout << "Welcome to the Cafe deLange!\n";
        cout << "1. Customer Login\n";
        cout << "2. Manager Login\n";
        cout << "3. Register for customer\n";
        cout << "4. Exit\n";
        cout << "\033[33m";
        cout << "Enter your choice: ";
        cout << "\033[0m";
        cin >> choice;

        switch (choice) {
            case 1: {
                Customer customerObj;
                Customer* customer = &customerObj;
                customer->Login();
                break;
            }
            case 2: {
                Manager managerObj;
                Manager* manager = &managerObj;
                manager->Admin();
                break;
            }
            case 3: {
                Customer registerObj;
                Customer* customer = &registerObj;
                customer->Register();
                customer->Login();
                break;
            }
            case 4:
                cout << "\033[32m"; 
                cout << "Thank you for visiting Cafe deLange!\n";
                cout << "\033[0m";
                exit(0);
                break;
            default:
                cout << "\033[31m";
                cout << "Invalid choice! Please try again.\n";
                cout << "\033[0m";
        }
    } while (choice != 4);
}

int main() {
    User usrObj;
    User* u = &usrObj;
    u->menu();

    return 0;
}