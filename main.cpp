#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <map>
#include <deque>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;

// Order Struct
struct Order {
    int orderID;
    string symbol;
    string side;
    double price;
    int quantity;
    string timestamp;
};

// Trade Struct
struct Trade {
    int tradeID;
    string symbol;
    double price;
    int quantity;
    chrono::high_resolution_clock::time_point timestamp;
};

// Timestamp Formatter
string getCurrentTimestamp() {
    auto now = chrono::system_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;
    time_t t = chrono::system_clock::to_time_t(now);
    tm* ptm = localtime(&t);

    stringstream ss;
    ss << put_time(ptm, "%H:%M:%S") << "." << setfill('0') << setw(3) << ms.count();
    return ss.str();
}

string formatTimestamp(chrono::high_resolution_clock::time_point ts) {
    auto duration = ts.time_since_epoch();
    auto nanos = chrono::duration_cast<chrono::nanoseconds>(duration).count();
    return to_string(nanos) + " ns";
}

// OrderBook Class
class OrderBook {
public:
    map<double, deque<Order>, greater<double>> buyOrders;
    map<double, deque<Order>> sellOrders;
    vector<Trade> trades;
    int orderCounter = 1;
    int tradeCounter = 1;

    void addOrder(Order o) {
        o.orderID = orderCounter++;
        o.timestamp = getCurrentTimestamp();
        for (auto& c : o.side) c = toupper(c);

        if (o.side == "BUY") {
            matchBuyOrder(o);
        } else if (o.side == "SELL") {
            matchSellOrder(o);
        } else {
            cout << "Invalid side: " << o.side << endl;
        }
    }

    void matchBuyOrder(Order& o) {
        while (o.quantity > 0 && !sellOrders.empty()) {
            auto it = sellOrders.begin();
            if (o.price >= it->first) {
                while (!it->second.empty() && o.quantity > 0) {
                    Order& sell = it->second.front();
                    int tradeQty = min(o.quantity, sell.quantity);
                    trades.push_back({tradeCounter++, o.symbol, sell.price, tradeQty, chrono::high_resolution_clock::now()});
                    o.quantity -= tradeQty;
                    sell.quantity -= tradeQty;
                    if (sell.quantity == 0) it->second.pop_front();
                }
                if (it->second.empty()) sellOrders.erase(it);
            } else break;
        }
        if (o.quantity > 0) buyOrders[o.price].push_back(o);
    }

    void matchSellOrder(Order& o) {
        while (o.quantity > 0 && !buyOrders.empty()) {
            auto it = buyOrders.begin();
            if (it->first >= o.price) {
                while (!it->second.empty() && o.quantity > 0) {
                    Order& buy = it->second.front();
                    int tradeQty = min(o.quantity, buy.quantity);
                    trades.push_back({tradeCounter++, o.symbol, o.price, tradeQty, chrono::high_resolution_clock::now()});
                    o.quantity -= tradeQty;
                    buy.quantity -= tradeQty;
                    if (buy.quantity == 0) it->second.pop_front();
                }
                if (it->second.empty()) buyOrders.erase(it);
            } else break;
        }
        if (o.quantity > 0) sellOrders[o.price].push_back(o);
    }

    void printBook() {
        cout << "\n--- BUY Orders ---\n";
        for (auto& [price, dq] : buyOrders) {
            for (auto& o : dq) {
                cout << "ID: " << o.orderID << ", " << o.symbol << " @ " << price << " x " << o.quantity
                     << " [" << o.timestamp << "]" << endl;
            }
        }

        cout << "\n--- SELL Orders ---\n";
        for (auto& [price, dq] : sellOrders) {
            for (auto& o : dq) {
                cout << "ID: " << o.orderID << ", " << o.symbol << " @ " << price << " x " << o.quantity
                     << " [" << o.timestamp << "]" << endl;
            }
        }
    }

    void printTrades() {
        cout << "\n--- Trade History ---\n";
        for (auto& t : trades) {
            cout << "TradeID: " << t.tradeID << ", Symbol: " << t.symbol
                 << ", Price: " << t.price << ", Qty: " << t.quantity
                 << ", Time: " << formatTimestamp(t.timestamp) << endl;
        }
    }

    void printCSV() {
        cout << "\n--- CSV Export Preview ---\n";
        cout << "TradeID,Symbol,Price,Quantity,Timestamp\n";
        for (auto& t : trades) {
            cout << t.tradeID << "," << t.symbol << "," << t.price << "," << t.quantity << "," << formatTimestamp(t.timestamp) << endl;
        }
    }

    void exportCSVtoFile() {
        ofstream file("trades.csv");
        file << "TradeID,Symbol,Price,Quantity,Timestamp\n";
        for (auto& t : trades) {
            file << t.tradeID << "," << t.symbol << "," << t.price << "," << t.quantity << "," << formatTimestamp(t.timestamp) << "\n";
        }
        file.close();
        cout << "✅ trades.csv file created successfully.\n";
    }
};

// Main Function
int main() {
    OrderBook ob;
    int n;
    cout << "Enter number of orders: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Order o;
        cout << "\nOrder " << i + 1 << ":\n";
        cout << "Symbol: ";
        cin >> o.symbol;
        cout << "Side (BUY/SELL): ";
        cin >> o.side;
        cout << "Price: ";
        cin >> o.price;
        cout << "Quantity: ";
        cin >> o.quantity;

        ob.addOrder(o);
    }

    ob.printBook();
    ob.printTrades();
    ob.printCSV();
    ob.exportCSVtoFile(); 

    return 0;
}
