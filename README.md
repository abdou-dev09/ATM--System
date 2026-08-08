# ATM Management System (C++)

![Language](https://img.shields.io/badge/Language-C%2B%2B11-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

A robust, console-based Automated Teller Machine (ATM) System developed in modern C++. This application simulates a full-featured banking client interface, enabling users to authenticate securely and execute essential financial transactions—including preset quick withdrawals, custom normal withdrawals, real-time balance inquiries, and account deposits. 

All financial state changes are kept synchronized with a flat-file storage mechanism (`Clients.txt`), demonstrating core software engineering principles such as data structures, modular function design, file I/O operations, and record parsing.

---

## Table of Contents

- [Key Features](#key-features)
- [Architecture & Design](#architecture--design)
- [Data Storage Format](#data-storage-format)
- [Project File Structure](#project-file-structure)
- [Prerequisites](#prerequisites)
- [Installation & Compilation](#installation--compilation)
- [How to Run & Use](#how-to-run--use)
- [System Flow](#system-flow)
- [Error Handling & Validation](#error-handling--validation)
- [Future Improvements](#future-improvements)
- [License](#license)

---

## Key Features

- 🔐 **Secure Account Authentication**
  - Requires matching Account Number and PIN code against persistent database records.
  - Recovers from failed login attempts with friendly error notifications without crashing.

- ⚡ **Quick Withdraw Menu**
  - Instant selection of popular dollar presets ($50, $100, $250, $400, $500, $750, $1000, $1500).
  - Automatically verifies if the chosen preset exceeds the current available account balance.

- 💵 **Custom Normal Withdrawals**
  - Allows users to request custom dollar amounts.
  - Enforces banking validation rules (e.g., amounts must be positive multiples of 5).
  - Prevents overdrawing by validating requested funds against live balances.

- 💳 **Deposit System**
  - Accepts arbitrary credit amounts directly into the user's account.
  - Recalculates total holdings and immediately writes changes to storage.

- 📊 **Real-time Balance Inquiries**
  - Instant screen displaying up-to-date user account balance information.

- 💾 **Persistent Flat-File Data Storage**
  - Reads, parses, modifies, and overwrites client records inside `Clients.txt`.
  - Employs custom delimiter-based record serialization (`#//#`).

---

## Architecture & Design

The project uses a structured procedural design in C++ paired with vector-based dynamic memory structures to manage user sessions effectively:

1. **Authentication Layer:** Validates user credentials from disk before granting access to the main menu routing loop.
2. **In-Memory Operations:** Loads disk data into a `std::vector<stClientInfo>` for fast lookup during active user sessions.
3. **Synchronization Layer:** On transaction confirmation (`[Y/n]`), updates the active client memory model and rewrites the modified state back to `Clients.txt` to guarantee data persistence across application restarts.

---

## Data Storage Format

Client records are stored in `Clients.txt` in a single line per user, using `#//#` as a field separator:

`<AccountNumber>#//#<PINCode>#//#<FullName>#//#<PhoneNumber>#//#<AccountBalance>`

### Example `Clients.txt`:
```text
A101#//#1234#//#John Doe#//#0500000000#//#5000.00
A102#//#4321#//#Jane Smith#//#0511111111#//#12000.50
A103#//#9999#//#Alice Johnson#//#0522222222#//#750.25
```

---

## Project File Structure

```text
├── main.cpp          # Core application logic, transaction algorithms, and CLI menus
├── StrLib.h          # String parsing utilities (splitting record strings into vector fields)
├── Clients.txt       # Flat-file database containing serialized client records
└── README.md         # Detailed project documentation
```

---

## Prerequisites

To compile and run this application, you need:

- A C++ compiler supporting C++11 or higher (`g++`, `clang++`, or MSVC).
- Terminal access (Linux, macOS, or Windows WSL/MinGW).

---

## Installation & Compilation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/atm-management-system.git
   cd atm-management-system
   ```

2. **Ensure `Clients.txt` exists:**
   Make sure `Clients.txt` is in the same working directory as your compiled binary.

3. **Compile the Source Code:**

   - **Using GCC / g++:**
     ```bash
     g++ -std=c++11 main.cpp -o ATM_System
     ```

   - **Using Clang:**
     ```bash
     clang++ -std=c++11 main.cpp -o ATM_System
     ```

---

## How to Run & Use

1. **Launch the Executable:**
   ```bash
   ./ATM_System
   ```

2. **Login Screen:**
   Enter a valid account number and PIN code found in your `Clients.txt` file (e.g., Account: `A101`, PIN: `1234`).

3. **Navigate the Main Menu:**
   ```text
   -----------------------------------------------------------
                   ATM System Main Menu Screen                
   -----------------------------------------------------------
           [1] Quick WithDraw.
           [2] Normal WithDraw.
           [3] Deposit.
           [4] Check Balance.
           [5] Logout.
   -----------------------------------------------------------
   Enter Your Choice [1 - 5]:
   ```

4. **Perform Transactions:**
   - Choose options `1` through `4` to manage your funds.
   - Confirm actions with `Y` or cancel with `N`.
   - Option `5` logs out of the current account and returns to the authentication screen.

---

## System Flow

```text
+---------------------+      +------------------------+      +-------------------------+
|     Login Screen    | ---> |   Main Menu Navigation | ---> | Transaction Operations  |
| (Account # & PIN)   |      | (Quick/Normal/Deposit) |      | (Updates Clients.txt)   |
+---------------------+      +------------------------+      +-------------------------+
```

---

## Error Handling & Validation

- **Authentication Failure:** Prompts the user again if credentials do not match stored records.
- **Insufficient Funds Guard:** Rejects withdrawal attempts exceeding the user's available balance.
- **Invalid Denomination Checking:** Forces normal withdrawals to be positive integers divisible by 5.
- **Menu Choice Boundaries:** Restricts menu selection inputs strictly within valid numeric ranges (e.g., `[1 - 5]`).

---

## Future Improvements

- [ ] Implement encryption for PIN codes stored in `Clients.txt` (e.g., SHA-256 hashing).
- [ ] Add account lockouts after 3 consecutive invalid login attempts.
- [ ] Add transaction history logging (mini-statements saved to a `Log.txt` file).
- [ ] Cross-platform terminal screen clearing (`cls` on Windows / `clear` on Unix).

---

## License

This project is open-source and available under the [MIT License](LICENSE).