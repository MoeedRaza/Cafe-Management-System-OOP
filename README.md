```markdown
# ☕ Café Management System

[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/status-complete-brightgreen.svg)]()

A comprehensive Café Management System built using **Object-Oriented Programming (OOP)** principles in C++. This system provides complete functionality for both customers and managers to streamline café operations.

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Architecture](#-architecture)
- [Class Structure](#-class-structure)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
- [Usage Guide](#-usage-guide)
- [Sample Data](#-sample-data)
- [Screenshots](#-screenshots)
- [Technologies Used](#-technologies-used)
- [Team Members](#-team-members)
- [Acknowledgments](#-acknowledgments)

---

## 🎯 Overview

The **Café Management System** is a console-based application that demonstrates the practical implementation of Object-Oriented Programming concepts. It serves as a complete solution for managing café operations, including:

- Customer registration and authentication
- Order placement and tracking
- Inventory management
- Revenue tracking
- Feedback collection
- Menu management

---

## ✨ Features

### 👤 Customer Features

| Feature | Description |
|---------|-------------|
| **Register** | Create a new customer account with personal details |
| **Login** | Secure authentication using username and password |
| **Place Order** | Browse menu and place orders with quantity selection |
| **Track Order** | Real-time order status tracking with visual progress |
| **View Orders** | View previous order receipts |
| **Change Credentials** | Update username and password |
| **Submit Feedback** | Provide feedback and complaints |
| **Delete Account** | Permanently delete customer account |
| **Payment Options** | Cash or Card payment processing |
| **Generate Receipt** | Detailed receipt with itemized bill |

### 👨‍💼 Manager Features

| Feature | Description |
|---------|-------------|
| **Secure Login** | Manager authentication with credentials |
| **View Stock** | Check current inventory levels |
| **Add Stock** | Add new items to inventory |
| **Add Menu Items** | Introduce new items to the menu |
| **Remove Items** | Delete items from the menu |
| **Update Prices** | Modify item prices |
| **View Revenue** | Track total revenue and sales |
| **Change Password** | Update manager password |
| **View Feedback** | Read customer feedback |
| **View Customer Info** | Access customer database |

---

## 🏗️ Architecture

### 🏗️ Class Diagram

````markdown
## 🏗️ Class Diagram

```text
                    +----------------------+
                    |        User          |
                    +----------------------+
                    | - name              |
                    | - address           |
                    | - phone             |
                    +----------------------+
                    | + menu()            |
                    +----------^-----------+
                               |
                      Inheritance
                               |
                    +----------+-----------+
                    |      Customer        |
                    +----------------------+
                    | - username          |
                    | - password          |
                    | - email             |
                    | - Order orderObj    |
                    +----------------------+
                    | + Login()           |
                    | + Register()        |
                    | + Payment()         |
                    | + Receipt()         |
                    | + DeleteAccount()   |
                    | + Complaint()       |
                    +----------+-----------+
                               |
                      Composition (has-a)
                               |
                               v
                    +----------------------+
                    |        Order         |
                    +----------------------+
                    | + PlaceOrder()      |
                    | + ViewOrder()       |
                    | + TrackOrder()      |
                    +----------------------+

      +----------------------------------------------+
      |                  Manager                     |
      +----------------------------------------------+
      | - managerName                               |
      | - password                                  |
      | - itemName                                  |
      | - itemPrice                                 |
      | - itemQuantity                              |
      +----------------------------------------------+
      | + Login()                                   |
      | + AddStock()                                |
      | + ViewStock()                               |
      | + AddItem()                                 |
      | + RemoveItem()                              |
      | + UpdatePrice()                             |
      | + ViewRevenue()                             |
      | + ViewFeedback()                            |
      | + ViewCustomerInfo()                        |
      +----------------------------------------------+
```
````

### OOP Relationships

| Class              | Relationship                                     |
| ------------------ | ------------------------------------------------ |
| `Customer → User`  | Inheritance                                      |
| `Customer → Order` | Composition (Customer owns an Order object)      |
| `Manager`          | Independent class responsible for administration |


### 📂 Project Structure

Cafe-Management-System/
│
├── main.cpp                 # Application entry point
├── User.h                   # Base User class
├── Customer.h               # Customer class declaration
├── Customer.cpp             # Customer class implementation
├── Order.h                  # Order class declaration
├── Order.cpp                # Order class implementation
├── Manager.h                # Manager class declaration
├── Manager.cpp              # Manager class implementation
│
├── customer_info.txt        # Customer information
├── customeracc.txt          # Customer login credentials
├── feedback.txt             # Customer feedback
├── manager_info.txt         # Manager credentials
├── menu.txt                 # Menu items and prices
├── receipt.txt              # Generated receipts
├── revenue.txt              # Revenue records
├── stock.txt                # Inventory data
│
├── README.md
└── LICENSE
```
````

---

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler** (g++ 7.0 or higher recommended)
- **Operating System**: Windows, Linux, or macOS
- **Git** (optional, for version control)

### Installation

#### Method 1: Clone Repository (Recommended)

```bash
# Clone the repository
git clone https://github.com/YOUR_USERNAME/Cafe-Management-System-OOP.git

# Navigate to project directory
cd Cafe-Management-System-OOP
```

#### Method 2: Download ZIP

1. Download the ZIP file from GitHub
2. Extract to your desired location
3. Open terminal/command prompt in the extracted folder

### Compilation

#### Windows (MinGW)

```bash
g++ -o cafe_system.exe src/*.cpp
```

#### Linux/macOS

```bash
g++ -o cafe_system src/*.cpp
```

### Running the Program

#### Windows

```bash
cafe_system.exe
```

#### Linux/macOS

```bash
./cafe_system
```

---

## 📖 Usage Guide

### Customer Flow

1. **Main Menu**: Choose "Customer Login" or "Register"
2. **Registration**: Enter personal details and create credentials
3. **Login**: Enter username and password
4. **Dashboard**: Choose from available options:
   - Place Order
   - Change Credentials
   - View Order
   - Track Order
   - Register Feedback
   - Delete Account
   - Back to Main Menu
   - Exit
5. **Order Process**:
   - View available menu
   - Select items with quantities
   - Confirm order
   - Choose payment method (Cash/Card)
   - Receive receipt

### Manager Flow

1. **Main Menu**: Choose "Manager Login"
2. **Credentials**: Enter username: `Wasif!`, password: `124`
3. **Management Dashboard**: Access all management features:
   - View/Add Stock
   - Add/Remove Menu Items
   - Update Prices
   - View Revenue
   - Change Password
   - View Feedback
   - View Customer Information

---

## 📊 Sample Data

The system comes with pre-populated data for immediate testing:

### Customer Accounts

| Username | Password |
|----------|----------|
| Ali | 898 |
| dani | 12345 |
| Moeed | 777 |

### Menu Items

| Item | Price (Rs.) |
|------|-------------|
| Cappuccino | 251 |
| Zinger Burger | 450 |
| Beef Burger | 750 |
| Loaded Fries | 221 |
| Mango Shake | 180 |
| Pasta | 241 |

### Manager Credentials

| Username | Password |
|----------|----------|
| Wasif! | 124 |

---


## 🛠️ Technologies Used

- **Language**: C++17
- **Paradigm**: Object-Oriented Programming
- **Storage**: File-based (.txt files)
- **Concepts**: Inheritance, Polymorphism, Encapsulation, Abstraction
- **Libraries**: iostream, fstream, string, vector, tuple, iomanip, chrono, thread

---

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- **Air University** - For providing the platform and resources
- **Object-Oriented Programming Course** - For the knowledge and skills

---

## 🔮 Future Enhancements

- [ ] GUI Interface using Qt or FLTK
- [ ] Database integration (SQLite/MySQL)
- [ ] Online payment integration
- [ ] Delivery tracking system
- [ ] Loyalty program for customers
- [ ] Mobile application
- [ ] Employee management system
- [ ] Reports and analytics dashboard

---

## 📧 Contact

For any queries or suggestions, please contact the team:

- **Abdul Moeed**: https://github.com/MoeedRaza

---

## ⭐ Show Your Support

If you found this project helpful, please give it a ⭐ on GitHub!

---

<div align="center">

**Made with ❤️ by Team Café | Air University, Islamabad**

</div>
```

---
