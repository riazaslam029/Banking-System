# 🏦 Banking System (C++)

This is a **console-based Banking System** written in **C++**.  
It allows creation of customer accounts, deposits, withdrawals, fund transfers, and transaction history management using arrays (without STL containers).

---

## 📌 Features
- Create new customer accounts  
- Deposit money into an account  
- Withdraw money from an account  
- Transfer funds between accounts  
- Show **customer information**  
- Show **transaction history** for each account  
- Supports up to **50 customers** and **100 transactions per account**  

---

## 🖥️ Example Run
===== Banking System Menu =====

Create Customer

Deposit

Withdraw

Fund Transfer

Show Customer Info

Show Transactions

Exit
Enter your choice: 1
Enter Customer ID: 101
Enter Name: Alice Johnson
Enter Account Number: 1001
Enter Initial Deposit: 5000
✅ Customer account created successfully!

===== Banking System Menu =====

Create Customer

Deposit

Withdraw

Fund Transfer

Show Customer Info

Show Transactions

Exit
Enter your choice: 2
Enter Account Number: 1001
Enter Deposit Amount: 2000
✅ Deposit successful! New Balance: 7000

yaml
Copy code

---

## 🚀 How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/banking-system-cpp.git
Navigate into the project folder:

bash
Copy code
cd banking-system-cpp
Compile the program:

bash
Copy code
g++ banking.cpp -o banking
Run the program:

bash
Copy code
./banking
📂 Files
banking.cpp → Main C++ source code

README.md → Documentation

⚡ Requirements
C++ compiler (e.g., g++, clang++, or MSVC)

🔮 Future Improvements
Replace fixed arrays with STL vectors for flexibility

Add file storage for persistent data (accounts & transactions)

Implement password-protected logins for customers

Add interest calculation and loan management

📜 License
This project is open-source and available under the MIT License.
