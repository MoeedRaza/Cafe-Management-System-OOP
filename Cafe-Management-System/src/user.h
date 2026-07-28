#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
using namespace std;

// Employee class is a base class for Manager class.
class User {
    string name;
    string address;
    string phone;
    public:
    User(string n, string p, string a): name(n), phone(p), address(a) {}
    User() {}

    //setters
    void setName(string n) {
        name = n;
    }
    void setPhone(string p) {
        phone = p;
    }
    void setAddress(string a) {
        address = a;
    }

    //getters
    string getName() {
        return name;
    }
    string getPhone() {
        return phone;
    }
    string getAddress() {
        return address;
    }

    virtual void menu();
};

#endif