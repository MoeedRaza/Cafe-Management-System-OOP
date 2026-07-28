#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "user.h"
#include "Order.h"

using namespace std;

// Customer class inherits from Employee class
class Customer: public User {
    string password;
    string email;
    string username;
    Order orderObj;      // Instance of order class to access its functions
public:
    Customer(string n, string p, string a): User(n, p, a) {}
    Customer() {}

    // Setters.
    void setUsername(string u) {
        username = u;
    }
    void setPassword(string p) {
        password = p;
    }
    void setEmail(string e) {
        email = e;
    }

    // Getters.
    string getUsername() {
        return username;
    }
    string getPassword() {
        return password;
    }
    string getEmail() {
        return email;
    }

    // Functions.
    void Login();
    void Register();
    void changeCredentials(string u, string p);
    void RegisterComplaint();
    void deleteAccount();
    void generateReceipt(const vector<tuple<string, double, int>>& cart);
    void Payment(double Total_Bill);
};

#endif