#  NanoMatch — High-Speed Trade Matching Engine

A modular C++ project that simulates how exchanges match trades quickly and accurately. This engine captures incoming orders, matches them based on price-time priority, and logs trades with formatted timestamps — just like real-world trading systems.

---

## 📌 Project Overview

NanoMatch is inspired by real exchange backends. It simulates:

- Order intake (BUY / SELL)
- Price-time priority matching
- Trade execution
- Nanosecond timestamp logging
- Audit trail generation

Each trade is stored with full metadata including symbol, quantity, price, side, and timestamp — making it suitable for compliance, analytics, and performance tracking.

---

## 🧩 Key Modules

- **Order Struct**: Captures incoming orders with symbol, price, quantity, side, and timestamp  
- **Matching Engine**: Matches BUY and SELL orders using price-time priority logic  
- **Trade Logger**: Stores executed trades with nanosecond timestamps  
- **Audit Trail Formatter**: Converts raw timestamps into human-readable format  
- **CSV Exporter**: Writes trade history to CSV file for external analysis

---

## 🧪 Sample Trade Log

Symbol: INFY 

Price: 1560.25 

Quantity: 100 

Side: BUY 

Time: 12:45:23.456789123


---

## 🧠 Real-World Mapping

| Module | System Role |
|--------|--------------|
| Matching Engine | Core trade execution logic |
| Timestamp Logger | Performance tracking + audit trail |
| CSV Export | External reporting |
| Price-Time Priority | Fairness + deterministic matching |
| Side Normalization | Standardized trade direction |

---

## 🚀 How to Run

1. Compile the code using any C++17 compatible compiler  
2. Run the executable  
3. Enter BUY/SELL orders as prompted  
4. View matched trades and audit logs  
5. Export trade history to CSV file

### 🛠 Sample Compilation Command

bash
g++ -std=c++17 -o NanoMatch src/*.cpp
./NanoMatch



📂 How to Get the CSV File

1. The engine has a built‑in method exportCSVtoFile() that writes all executed trades into a file named trades.csv.
   
2. After running the program, check your project’s working directory (e.g., Debug/ folder in Visual Studio).


To open the file quickly:

notepad trades.csv

or

start trades.csv




🤖 Built with AI Mentorship
I used Microsoft Copilot as a mentor — not a coder. It helped me validate matching logic, format timestamps, and structure modules clearly. I never followed anything blindly. Every suggestion was reviewed, modified, and tested. The final code is fully mine and mapped to real-world trading infrastructure.

🧠 Why This Project Matters
Simulates core matching logic used in real exchanges

Shows timestamp literacy and audit trail formatting

Demonstrates modular thinking and performance-focused design

Recruiter-ready and easy to explain in interviews


📇 Connect with me on [Saksham Verma](https://www.linkedin.com/in/saksham-verma-302271285/)  
