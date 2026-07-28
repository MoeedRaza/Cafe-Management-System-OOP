#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Manager class for managing the cafe's operations
class Manager {
protected:
    string name;
    string password;
    string ItemName;
    float ItemPrice;
    int ItemQuantity;
    int OrderId;

public:
    Manager(string n, string p, string IN, float IP, int IQ, int OID);
    Manager();

    // Setters.
    void setName(const string& n);
    void setPassword(const string& p);
    void setItemName(const string& item);
    void setItemPrice(float price);
    void setItemQuantity(int quantity);
    void setOrderId(int id);

    // Getters.
    string getName() const;
    string getPassword() const;
    string getItemName() const;
    float getItemPrice() const;
    int getItemQuantity() const;
    int getOrderId() const;

    // Functions.
    void Admin();
    void ViewStock();
    void AddItems();
    void RemoveItems();
    void Revenue();
    void ChangePassword();
    void ViewFeedback();
    void UpdatePrice();
    void ViewCustomerInfo();
    void Addstock();
};

#endif