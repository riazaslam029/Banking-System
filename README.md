# Banking System

A console-based banking management system written in **C++**. The application demonstrates object-oriented programming, account operations, transaction tracking, and menu-driven interaction using fixed-size arrays.

> **Note:** This project is intended for educational and demonstration purposes. It does not provide the security, persistence, validation, or compliance controls required for production banking software.

## Features

- Create customer accounts with a customer ID, name, account number, and initial deposit
- Deposit funds into an existing account
- Withdraw funds while checking for insufficient balance
- Transfer funds between two accounts
- Display customer and account information
- Display account transaction history
- Prevent duplicate account numbers
- Record deposits, withdrawals, and incoming/outgoing transfers
- Support up to **50 customers** and **100 transactions per account**

## Technology Stack

- **Language:** C++
- **Paradigm:** Object-oriented programming
- **Storage:** In-memory fixed-size arrays
- **Project format:** Microsoft Visual Studio solution and project files
- **Standard library components:** `iostream` and `string`

## Project Structure

```text
Banking-System/
├── Banking System.sln
├── Banking System/
│   ├── Banking System.cpp
│   ├── Banking System.vcxproj
│   └── Banking System.vcxproj.filters
├── .gitattributes
├── .gitignore
└── README.md
```

### Core Classes

- `Transaction` — Stores the transaction type, amount, and additional details.
- `Account` — Maintains the account number, balance, transaction history, and account operations.
- `Customer` — Associates customer information with an account.

## Requirements

Choose one of the following environments:

- **Visual Studio 2019 or later** with the C++ desktop development workload
- A compatible C++ compiler such as `g++` or `clang++`

## Getting Started

### Clone the Repository

```bash
git clone https://github.com/riazaslam029/Banking-System.git
cd Banking-System
```

### Build with Visual Studio

1. Open `Banking System.sln` in Visual Studio.
2. Select a build configuration such as `Debug` or `Release`.
3. Select the appropriate platform, such as `x64` or `Win32`.
4. Build the solution.
5. Run the application from Visual Studio or the generated executable.

### Build with g++

From the repository root, run:

```bash
g++ "Banking System/Banking System.cpp" -std=c++17 -Wall -Wextra -o banking-system
```

Run the program on Linux or macOS:

```bash
./banking-system
```

Run the program on Windows PowerShell:

```powershell
./banking-system.exe
```

## Usage

After launching the program, use the numbered menu to select an operation:

```text
===== Banking System Menu =====
1. Create Customer
2. Deposit
3. Withdraw
4. Fund Transfer
5. Show Customer Info
6. Show Transactions
7. Exit
```

A typical workflow is:

1. Create a customer account.
2. Use the account number to deposit funds.
3. Withdraw funds or transfer money to another account.
4. Review customer details and transaction history.
5. Exit the application.

## Data and Validation Notes

- All data is stored in memory and is lost when the application exits.
- The current implementation uses fixed-size arrays rather than dynamic containers.
- The application checks for duplicate account numbers and insufficient funds.
- Account numbers must exist before deposits, withdrawals, transfers, or lookups can be performed.
- Input validation for malformed or negative values is limited and can be improved.

## Potential Improvements

- Add persistent storage using files or a database
- Replace fixed-size arrays with STL containers such as `std::vector`
- Add stronger validation for account numbers, amounts, and menu input
- Prevent negative initial deposits and transaction amounts
- Add authentication and role-based access
- Add account closing and customer update functionality
- Add timestamps and unique transaction IDs
- Separate business logic, user interface, and data access into dedicated modules
- Add automated tests and a build system such as CMake
- Add interest calculation, loan management, and reporting features

## Contributing

Contributions are welcome. To propose an improvement:

1. Fork the repository.
2. Create a feature branch:

   ```bash
   git checkout -b feature/your-improvement
   ```

3. Make your changes and test them locally.
4. Commit your changes with a clear message.
5. Push the branch and open a pull request.

## License

No license is currently specified for this repository. Contact the repository owner before using, modifying, or redistributing the code outside the repository.

## Author

**Riaz Aslam**  
GitHub: [@riazaslam029](https://github.com/riazaslam029)
