#include "Manager.h"
#include <cstdio>
using namespace std;

// Constructors.
Manager::Manager(string n, string p, string IN, float IP, int IQ, int OID) {
    name = n;
    password = p;
    ItemName = IN;
    ItemPrice = IP;
    ItemQuantity = IQ;
    OrderId = OID;
}

// Default constructor.
Manager::Manager() {
    name = "";
    password = "";
    ItemName = "";
    ItemPrice = 0.0f;
    ItemQuantity = 0;
    OrderId = 0;
}

// Setters.
void Manager::setName(const string& n) {
    name = n;
}
void Manager::setPassword(const string& p) {
    password = p;
}
void Manager::setItemName(const string& item) {
    ItemName = item;
}
void Manager::setItemPrice(float price) {
    ItemPrice = price;
}
void Manager::setItemQuantity(int quantity) {
    ItemQuantity = quantity;
}
void Manager::setOrderId(int id) {
    OrderId = id;
}

// Getters.
string Manager::getName() const {
    return name;
}
string Manager::getPassword() const {
    return password;
}
string Manager::getItemName() const {
    return ItemName;
}
float Manager::getItemPrice() const {
    return ItemPrice;
}
int Manager::getItemQuantity() const 
{return ItemQuantity;
}
int Manager::getOrderId() const {
    return OrderId;
}

// Functions:

// This function allows the manager to log in and access the management portal.
void Manager::Admin() {
    ifstream manage("manager_info.txt");
    if (!manage) {
        cout << "\033[31mError opening manager file.\033[0m" << endl;
        return;
    }

    string stored_name, stored_password;
    manage >> stored_name >> stored_password;
    manage.close();
    
    while (true) {
        cout << "\033[36mManager Portal.\033[0m" << endl;
        cout << "\033[33mEnter your username (or 'back' to return): \033[0m";
        string input_name;
        cin >> input_name;
        
        if (input_name == "back") return;

        cout << "\033[33mEnter password: \033[0m";
        string inputpass;
        cin >> inputpass;

        if (input_name == stored_name && inputpass == stored_password) {
            cout << "\033[32mLogin successful!\033[0m\n";
            
            name = input_name;
            password = inputpass;
            while (true) {
                cout << "\n\033[36mWelcome back! " << name << " ,\033[0m\n";
                cout << "\033[36m1. View stock\n";
                cout << "2. Add stock\n";
                cout << "3. Add item\n";
                cout << "4. Remove item\n";
                cout << "5. Update prices\n";
                cout << "6. View Revenue\n";
                cout << "7. Change password\n";
                cout << "8. View feedback\n";
                cout << "9. View customer information\n";
                cout << "10. Back to main menu\n";
                cout << "11. Exit program\033[0m\n";
                cout << "\033[33mEnter your choice: \033[0m";

                int choice;
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1: ViewStock(); break;
                    case 2: Addstock(); break;
                    case 3: AddItems(); break;
                    case 4: RemoveItems(); break;
                    case 5: UpdatePrice(); break;
                    case 6: Revenue(); break;
                    case 7: ChangePassword(); break;
                    case 8: ViewFeedback(); break;
                    case 9: ViewCustomerInfo(); break;
                    case 10: return;
                    case 11:
                        cout << "\033[32mExiting program. Goodbye!\033[0m\n";
                        exit(0);
                    default:
                        cout << "\033[31mInvalid choice! Try again.\033[0m\n";
                }
            }
        } else {
            cout << "\033[31mIncorrect credentials!\033[0m\n";
        }
    }
}

// This function allows the manager to view the stock of items.
void Manager::ViewStock() {
    ifstream stock("stock.txt");
    if (!stock) {
        cout << "\033[31mError opening file.\033[0m" << endl;
        return;
    }

    string line;
    while (getline(stock, line)) 
    {
        stringstream ss(line);
        string itemName, itemQuantity;
        getline(ss, itemName, ',');
        ss >> itemQuantity;

        cout << "Item: " << itemName << " | Quantity: " << itemQuantity << " " << endl;
    }
    stock.close();
}

// This function allows the manager to add items to the menu.
void Manager::AddItems() {
    string new_item;
    float new_price;
    cout << "\033[33mEnter the item you want to add: \033[0m";
    getline(cin, new_item);
    cout << "\033[33mEnter the price of the item: \033[0m";
    cin >> new_price;

    ofstream add("menu.txt", ios::app);
    if (!add) {
        cout << "\033[31mError opening file.\033[0m" << endl;
        return;
    }

    add << new_item << ", " << new_price << endl;
    cout << "\033[32mItem successfully added to the menu.\033[0m\n";
    add.close();
}

// This function allows the manager to remove items from the menu.
void Manager::RemoveItems() {
    string itemName;
    cout << "\033[33mEnter the name of the item to remove: \033[0m";
    cin.ignore();
    getline(cin, itemName);

    ifstream del("menu.txt");
    ofstream rewrite("temp.txt");
    bool itemRemoved = false;

    if (!del || !rewrite) {
        cout << "\033[31mError opening file!\033[0m" << endl;
        return;
    }

    string file_itemName;
    while (getline(del, file_itemName)) {
        if (file_itemName.find(itemName) == string::npos) {
            rewrite << file_itemName << endl;
        } else {
            itemRemoved = true;
        }
    }

    del.close();
    rewrite.close();

    if (itemRemoved) {
        remove("menu.txt");
        rename("temp.txt", "menu.txt");
        cout << "\033[32mItem removed successfully!\033[0m\n";
    } else {
        remove("temp.txt");
        cout << "\033[31mItem not found!\033[0m\n";
    }
}

// This function allows the manager to view the revenue generated from sales.
void Manager::Revenue() {
    ifstream rev("revenue.txt");
    if (!rev) {
        cout << "\033[31mError opening file.\033[0m" << endl;
        return;
    }

    string line;
    while (getline(rev, line)) {
        stringstream ss(line);
        string item, price, quantity, total;
        getline(ss, item, ',');
        ss >> price >> quantity >> total;
        cout << "Item: " << item << " | Quantity: " << quantity << " | Price: " << price << " | Total: " << total << " " << endl;
    }
    rev.close();
}

// This function allows the manager to change their password.
void Manager::ChangePassword() {
    string new_pass, confirm_pass;
    cout << "\033[33mEnter new password: \033[0m";
    cin >> new_pass;
    cout << "\033[33mConfirm new password: \033[0m";
    cin >> confirm_pass;

    if (new_pass == confirm_pass) {
        ofstream update("manager_info.txt");
        if (!update) {
            cout << "\033[31mError opening file!\033[0m" << endl;
            return;
        }
        update << name << " " << new_pass << endl;
        cout << "\033[32mPassword changed successfully!\033[0m\n";
        update.close();
    } else {
        cout << "\033[31mPasswords do not match!\033[0m\n";
    }
}

// This function allows the manager to view customer feedback.
void Manager::ViewFeedback() {
    ifstream feed("feedback.txt");
    if (!feed) {
        cout << "\033[31mError opening file!\033[0m" << endl;
        return;
    }

    string complaint;
    while (getline(feed, complaint)) {
        cout << " " << complaint << " " << endl;
    }
    feed.close();
}

// This function allows the manager to update the price of an item in the menu.
void Manager::UpdatePrice() {
    string itemName;
    float new_price;
    bool found = false;

    cout << "\033[33mEnter the item you want to update: \033[0m";
    getline(cin, itemName);
    cout << "\033[33mEnter new price: \033[0m";
    cin >> new_price;

    ifstream menuIn("menu.txt");
    ofstream menuOut("temp.txt");

    string file_item;
    float file_price;

    while (menuIn >> ws && getline(menuIn, file_item, ',')) {
        menuIn >> ws >> file_price;
        if (file_item == itemName) {
            menuOut << itemName << ", " << new_price << endl;
            found = true;
        } else {
            menuOut << file_item << ", " << file_price << endl;
        }
    }

    menuIn.close();
    menuOut.close();

    if (found) {
        remove("menu.txt");
        rename("temp.txt", "menu.txt");
        cout << "\033[32mPrice updated successfully!\033[0m" << endl;
    } else {
        remove("temp.txt");
        cout << "\033[31mItem not found!\033[0m" << endl;
    }
}

// This function allows the manager to view customer information.
void Manager::ViewCustomerInfo() {
    ifstream info("customer_info.txt");

    if (!info) {
        cout << "\033[31mError opening file!\033[0m" << endl;
        return;
    }

    string line;
    while (getline(info, line)) {
        cout << " " << line << " " << endl;
    }

    info.close();
}

// This function allows the manager to add stock to the inventory.
void Manager::Addstock() {
    string itemName;
    int itemQuantity;

    cout << "\033[33mEnter the stock you want to add: \033[0m" << endl;
    getline(cin, itemName);
    cout << "\033[33mEnter the quantity: \033[0m" << endl;
    cin >> itemQuantity;

    ofstream add("stock.txt", ios::app);
    if (!add) {
        cout << "\033[31mError opening file!\033[0m" << endl;
        return;
    }

    add << itemName << ", " << itemQuantity << endl;
    cout << "\033[32mItem: " << itemName << " successfully added!\033[0m" << endl;
    add.close();
}