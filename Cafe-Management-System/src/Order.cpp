#include<bits/stdc++.h>
#include "Order.h"
#include "customer.h"
using namespace std;

// This function allows the customer to order items from the menu.
void Order::placeOrder() {
    Customer CustObj;     // Instance of Customer class to access its functions.
    
    ifstream inFile("menu.txt");
    if (!inFile) {
        cout << "\033[31mError opening menu.txt!\n\033[0m";
        return;
    }

    vector<pair<string, double>> menu;
    string line;
    while (getline(inFile,line)) {
        stringstream ss(line);
        string item;
        double price;
        getline(ss, item, ',');
        ss >> price;
        menu.push_back({item, price});
    }
    inFile.close();

    vector<tuple<string, double, int>> cart;
    char choice;

    do {
        cout << "\n\033[36mAvailable Menu:\n\033[0m";
        for (const auto& menuItem : menu) {
            cout << menuItem.first << " - Rs." << fixed << setprecision(2) << menuItem.second << endl;
        }

        string selectedItem;
        int quantity;
        cout << "\033[33mEnter item to order: \033[0m";
        cin.ignore();
        getline(cin, selectedItem);
        cout << "\033[33mEnter quantity: \033[0m";
        cin >> quantity;

        bool found = false;
        for (const auto& menuItem : menu) {
            if (menuItem.first == selectedItem) {
                cart.push_back({menuItem.first, menuItem.second, quantity});
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\033[31mItem not found in menu.\n\033[0m";
        }

        cout << "\033[33mDo you want to add another item? (y/n): \033[0m";
        cin >> choice;

    } while (choice != 'n' && choice != 'N');

    cout << "\nProcessing your order...\nHere's your receipt!\n";
    CustObj.generateReceipt(cart);

    ofstream writerevenue("revenue.txt", ios::app);
    if(!writerevenue) {
        cout << "\033[31mError opening revenue.txt for writing!\n\033[0m";
        return;
    }

    double total = 0.0;

    for (const auto& [item, price, qty] : cart) {
        double itemtotal = price * qty;
        total += itemtotal;
        writerevenue << item << ", " << fixed << setprecision(2) << price << ", " << qty << ", " << fixed << setprecision(2) << itemtotal << endl;
    }
    cout << "Total Revenue: Rs." << fixed << setprecision(2) << total << endl;
    writerevenue.close();
}

// This function allows the customer to view their last order receipt.
void Order::viewOrder() {
    ifstream inFile("receipt.txt");
    if (!inFile) {
        cerr << "\033[31mError opening receipt.txt!\n\033[0m";
        return;
    }

    inFile.seekg(0, ios::end);
    if (inFile.tellg() == 0) {
        cerr << "\033[31mNo previous orders found.\n\033[0m";
        return;
    }

    inFile.seekg(0);
    cout << "\n\033[36m--- Last Receipt ---\n\033[0m";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

// This function tracks the order status.
void Order::trackOrder() {
    using namespace chrono;
    using namespace this_thread;

    auto loading = []() {
        for (int i = 0; i < 10; ++i) {
            cout << "#";
            cout.flush();
            sleep_for(milliseconds(200));
        }
        cout << endl;
    };

    cout << "\033[36mOrder Processing...\n\033[0m";
    sleep_for(seconds(2));
    loading();

    cout << "\033[36mPreparing for Delivery...\n\033[0m";
    sleep_for(seconds(2));
    loading();

    cout << "\033[36mOn your way...\n\033[0m";
    sleep_for(seconds(2));
    loading();

    cout << "\033[32mDelivered!\n\033[0m";
}