# 🏦 C++ Banking System  

## 📌 Overview  
This project is a simple **banking system simulation** written in **C++**. It demonstrates the use of **Object-Oriented Programming (OOP) principles** such as classes, objects, encapsulation, and method-based interactions.  

The system allows a user to:  
- Authenticate with a **username and PIN**  
- **Check account balance**  
- **Deposit money** into the account  
- **Withdraw money** (with insufficient balance protection)  
- View a complete **transaction history** with timestamps  

This program is designed as a console-based application for demonstration and learning purposes.  

---

## ⚙️ Features  
1. **Authentication System**  
   - The user must log in with a **username and PIN**.  
   - If authentication fails, the system exits immediately.  

2. **Account Management**  
   - Check current balance anytime.  
   - Deposit and withdraw money with validation.  

3. **Transaction History**  
   - Each transaction (deposit or withdrawal) is stored with:  
     - Type (Deposit/Withdraw)  
     - Amount  
     - Timestamp (date and time of transaction)  

4. **Interactive Menu**  
   - User-friendly options to navigate through account operations.  
   - Loop continues until the user explicitly chooses to exit.  

---

## 🖥️ How It Works  

- **Account Class**  
  - Stores details like username, PIN, balance, and transaction history.  
  - Handles deposit, withdrawal, and history operations.  

- **Transaction Class**  
  - Records each transaction’s type, amount, and timestamp.  
  - Ensures traceability of all account activity.  

- **Main Function**  
  - Initializes a demo account (`username = harsh`, `pin = 1234`, balance = Rs.5000).  
  - Prompts user for login credentials.  
  - Displays a menu-driven interface for performing banking operations.  

---

## 🚀 Getting Started  

### 1. Prerequisites  
Make sure you have:  
- A **C++ compiler** (e.g., `g++`) installed on your system.  
- Basic knowledge of running C++ programs in a terminal/command prompt.  

### 2. Compilation  
To compile the program, run:  
```bash
g++ banking_system.cpp -o banking_system
