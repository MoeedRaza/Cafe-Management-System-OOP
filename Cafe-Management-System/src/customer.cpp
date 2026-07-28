#include <bits/stdc++.h>
#include "customer.h"
#include "user.h"
#include "Order.h"

using namespace std;

// This function allows the customer to log in by checking their credentials against the stored data.
void Customer::Login() {
    ifstream inFile("customeracc.txt");
    if (!inFile) {
        cout << "\033[31mError opening customeracc.txt!\n\033[0m";
        return;
    }

    string u, p;
    cout << "\033[33mEnter Username (or 'back' to return): \033[0m";
    cin >> u;
    if (u == "back") return;

    cout << "\033[33mEnter Password: \033[0m";
    cin >> p;

    string fileU, fileP;
    bool found = false;
    while (inFile >> fileU >> fileP) {
        if (fileU == u && fileP == p) {
            this->username = u;
            this->password = p;
            cout << "\033[32mLogin successful.\n\033[0m";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\033[31mInvalid username or password.\n\033[0m";
        cout << "\033[36mWant to register!!\n\033[0m";
        char choice;
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            Register();
            Login();
        } else {
            cout << "\033[36mTry again!!\n\033[0m";
            Login();
        }
    }

    inFile.close();
    if(found) {
        int choice;
        do {
            cout << "\n\n\033[36mWelcome, " << username << "!\n\n\033[0m";
            cout << "\033[36mWhat would u like!!?\n";
            cout << "1. Order.\n";
            cout << "2. Change Credentials.\n";
            cout << "3. View Order.\n";
            cout << "4. Track Order.\n";
            cout << "5. Register a feedback.\n";
            cout << "6. Delete Account.\n";
            cout << "7. Back to main menu.\n";
            cout << "8 Exit.\n\033[0m";
            cout << "\033[33m";
            cin >> choice;
            cout << "\033[0m";

            switch (choice) {
                case 1:
                    orderObj.placeOrder();
                    break;
                case 2: {
                    string newU, newP, newE;
                    cout << "\033[33mEnter new username: \033[0m";
                    cin >> newU;
                    cout << "\033[33mEnter new password: \033[0m";
                    cin >> newP;
                    changeCredentials(newU, newP);
                    break;
                }
                case 3:
                    orderObj.viewOrder();
                    break;
                case 4:
                    orderObj.trackOrder();
                    break;
                case 5:
                    RegisterComplaint();
                    break;
                case 6:{
                    deleteAccount();
                    return;
                    break;
                }
                case 7:
                    break;
                case 8:{
                    cout << "\033[32mThank you for visiting Cafe deLange!\n\033[0m";
                    exit(0);
                    break;
                }
                default:
                    cout << "\033[31mInvalid choice.\n\033[0m";
            }
        } while(choice != 7);
    }
}

// This function registers a new customer by taking their details and saving them to the respective files.
void Customer::Register(){
    string newU, newP, newE, newN, newA, newPh;

    cout << "\033[33mEnter your name: \033[0m";
    getline(cin, newN);

    cout << "\033[33mEnter your phone: \033[0m";
    cin >> newPh;
    cin.ignore();

    cout << "\033[33mEnter your address: \033[0m";
    getline(cin, newA);

    cout << "\033[33mEnter new username: \033[0m";
    cin >> newU;
    cin.ignore();

    cout << "\033[33mEnter new password: \033[0m";
    getline(cin, newP);  

    cout << "\033[33mEnter email: \033[0m";
    getline(cin, newE); 


    ofstream info("customer_info.txt", ios::app);
    if(!info) {
        cout << "\033[31mError opening customerinfo.txt for writing!\n\033[0m";
        return;
    }
    info << newN << " " << newPh << " " << newA << " " << newE <<  endl;
    info.close();

    ofstream outFile("customeracc.txt", ios::app);
    if (!outFile) {
        cout << "\033[31mError opening customeracc.txt for writing!\n\033[0m";
        return;
    }
    outFile << newU << " " << newP << endl;
    outFile.close();
    cout << "\033[32mRegistration successful.\n\033[0m";
}

// This function deletes the customer's account by removing their credentials from the file.
void Customer::deleteAccount() {
    ifstream inFile("customeracc.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cerr << "\033[31mError opening files for account deletion.\n\033[0m";
        return;
    }

    string fileU, fileP;
    bool deleted = false;

    while (inFile >> fileU >> fileP) {
        if (fileU == this->username && fileP == this->password) {
            deleted = true;
            continue;
        }
        tempFile << fileU << " " << fileP << endl;
    }

    inFile.close();
    tempFile.close();

    if (deleted) {
        remove("customeracc.txt");
        rename("temp.txt", "customeracc.txt");
        cout << "\033[32mAccount deleted successfully.\n\033[0m";
    } else {
        remove("temp.txt");
        cout << "\033[31mAccount not found.\n\033[0m";
    }
}

// This function generates a receipt for the customer's order and writes it to a file.
void Customer::generateReceipt(const vector<tuple<string, double, int>>& cart) {
    string deliveryMan = "Ali Raza";
    double total = 0.0;

    cout << "\n\033[36m========== Cafe deLange ==========\n\033[0m";
    cout << "Delivery Man: " << deliveryMan << "\n\n";
    cout << left << setw(20) << "Item"
         << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(10) << "Total" << endl;

    cout << string(50, '-') << endl;

    for (const auto& [name, price, qty] : cart) {
        double itemTotal = price * qty;
        cout << left << setw(20) << name
             << setw(10) << fixed << setprecision(2) << price
             << setw(10) << qty
             << setw(10) << fixed << setprecision(2) << itemTotal << endl;
        total += itemTotal;
    }

    cout << string(50, '-') << endl;
    cout << left << setw(40) << "Subtotal:" << "Rs." << fixed << setprecision(2) << total << endl;
    cout << left << setw(40) << "Discount:" << "Rs.0.00" << endl;
    cout << left << setw(40) << "Total:" << "Rs." << fixed << setprecision(2) << total << endl;
    cout << "========================================\n";

    ofstream receiptFile("receipt.txt");
    if (!receiptFile) {
        cout << "\033[31mError writing to receipt.txt\n\033[0m";
        return;
    }

    receiptFile << "\n========== Cafe deLange ==========\n";
    receiptFile << "Delivery Man: " << deliveryMan << "\n\n";
    receiptFile << left << setw(20) << "Item"
                << setw(10) << "Price"
                << setw(10) << "Qty"
                << setw(10) << "Total" << endl;
    receiptFile << string(50, '-') << endl;

    for (const auto& [name, price, qty] : cart) {
        double itemTotal = price * qty;
        receiptFile << left << setw(20) << name
                    << setw(10) << fixed << setprecision(2) << price
                    << setw(10) << qty
                    << setw(10) << fixed << setprecision(2) << itemTotal << endl;
    }

    receiptFile << string(50, '-') << endl;
    receiptFile << left << setw(40) << "Subtotal:" << "Rs." << fixed << setprecision(2) << total << endl;
    receiptFile << left << setw(40) << "Discount:" << "Rs.0.00" << endl;
    receiptFile << left << setw(40) << "Total:" << "Rs." << fixed << setprecision(2) << total << endl;
    receiptFile << "========================================\n";

    receiptFile.close();

    Payment(total);
}

// This function allows the customer to change their credentials.
void Customer::changeCredentials(string u, string p) {
    ifstream infile("customeracc.txt");
    if (!infile) {
        cout << "\033[31mError opening customercc.txt for reading!\n\033[0m";
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cout << "\033[31mError creating temporary file!\n\033[0m";
        return;
    }

    string name, pass;
    bool updated = false;

    while (infile >> name >> pass) {
        if (name == this->username && pass == this->password) {
            tempFile << u << " " << p << endl;
            this->username = u;
            this->password = p;
            updated = true;
        } else {
            tempFile << name << " " << pass << endl;
        }
    }

    infile.close();
    tempFile.close();

    // Replace original file with updated temp file
    if (updated) {
        remove("customeracc.txt");
        rename("temp.txt", "customeracc.txt");
        cout << "\033[32mCredentials updated successfully.\n\033[0m";
    } else {
        remove("temp.txt");
        cout << "\033[31mNo matching credentials found.\n\033[0m";
    }
}

// This function allows the customer to register a complaint.
void Customer::RegisterComplaint() {
    ofstream complaintFile("feedback.txt", ios::app);
    if (!complaintFile) {
        cout << "\033[31mError opening feedback.txt!\n\033[0m";
        return;
    }

    cout << "Enter your name: ";
    string name;
    cin.ignore();
    getline(cin,name);

    cout << "\033[33mEnter your feedback:\n\033[0m";
    string complaint;
    getline(cin, complaint);
    complaintFile << name << ":\n   " << complaint << endl;
    complaintFile.close();
    cout << "\033[32mFeedback registered successfully.\n\033[0m";
}

// This function handles the payment process for the customer's order.
void Customer::Payment(double Total_Bill) {
    int paymentMethod;
    int account, pin;

    cout << "\033[33mEnter your payment method:\n";
    cout << "1. Cash\n";
    cout << "2. Card\n\033[0m";

    cin >> paymentMethod;

    if (paymentMethod == 1) {
        cout << "\033[32mYour total bill is Rs." << Total_Bill << " only.\n";
        cout << "Payment successful.\n";
        cout << "Thank You!\n\033[0m";
    } else if (paymentMethod == 2) {
        cout << "\033[32mYour total bill is Rs." << Total_Bill << " only.\n\033[0m";
        cout << "\033[33mEnter your account number (10 digits): \033[0m";
        cin >> account;
        cout << "\033[33mEnter your PIN (4 digits): \033[0m";
        cin >> pin;
        cout << "\033[32mPayment successful.\n";
        cout << "Thank You!\n\033[0m";
    } else {
        cout << "\033[31mInvalid Option!\n\033[0m";
    }
}