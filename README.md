# ⚡ NanoMatch — High-Speed Trade Matching Engine

A modular C++ project that simulates how real exchanges match trades at high speed with nanosecond-level precision. This engine captures incoming orders, matches them based on price-time priority, and logs trades with formatted timestamps — just like actual HFT systems.

---

## 📌 Project Overview

NanoMatch is inspired by real-world trading engines used in high-frequency environments. It simulates:

- Order intake (BUY / SELL)
- Price-time priority matching
- Trade execution
- Nanosecond timestamp logging
- Audit trail generation

Each trade is stored with full metadata including symbol, quantity, price, side, and timestamp — making it suitable for compliance, analytics, and latency tracking.

---

## 🧩 Key Modules

- **Order Struct**: Captures incoming orders with symbol, price, quantity, side, and timestamp  
- **Matching Engine**: Matches BUY and SELL orders using price-time priority logic  
- **Trade Logger**: Stores executed trades with nanosecond timestamps  
- **Audit Trail Formatter**: Converts raw timestamps into human-readable format for compliance  
- **CSV Exporter**: Writes trade history to CSV file for external analysis

---

## 🧪 Sample Trade Log

Symbol: SAMMSUNG 

Price: 1560.25 

Quantity: 100 

Side: BUY 

Time: 12:45:23.456789123


---

## 🧠 Real-World Mapping

| Module | Exchange Role |
|--------|----------------|
| Matching Engine | Core trade execution logic |
| Timestamp Logger | Latency tracking + audit trail |
| CSV Export | Compliance + external reporting |
| Price-Time Priority | Fairness + deterministic matching |
| Side Normalization | Standardized trade direction |

---

## 🚀 How to Run

1. Compile the code using any C++17 compatible compiler  
2. Run the executable  
3. Enter BUY/SELL orders as prompted  
4. View matched trades and audit logs  
5. Export trade history to CSV file

---

## 🤖 Built with AI Mentorship

I used Microsoft Copilot as a mentor — not a coder. It helped me validate matching logic, format timestamps, and structure modules clearly. I never followed anything blindly. Every suggestion was reviewed, modified, and tested. The final code is fully mine and mapped to real-world trading infrastructure.

---

## 🧠 Why This Project Matters

- Simulates core matching logic used in real exchanges  
- Shows timestamp literacy and audit trail formatting  
- Demonstrates modular thinking and infra-grade design  
- Recruiter-ready and easy to explain in interviews

---

## 🙋‍♂️ About Me

Built by [Saksham Verma](https://www.linkedin.com/in/saksham-verma-302271285/)  
Focused on modular C++ projects, timestamp precision, and real-world trading simulations.

