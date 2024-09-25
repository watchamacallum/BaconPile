#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ORDERS 100
#define MAX_BOTS 3

typedef struct {
    char type; // 'B' for buy, 'S' for sell
    float price;
    int quantity;
} Order;

typedef struct {
    Order orders[MAX_ORDERS];
    int orderCount;
} OrderBook;

typedef struct {
    char name[10];
    float cash;
    int shares;
} TradingBot;

void initializeBots(TradingBot bots[]) {
    for (int i = 0; i < MAX_BOTS; i++) {
        sprintf(bots[i].name, "Bot%d", i + 1);
        bots[i].cash = 1000.0; // Each bot starts with $1000
        bots[i].shares = 0;
    }
}

void addOrder(OrderBook *book, char type, float price, int quantity) {
    if (book->orderCount < MAX_ORDERS) {
        book->orders[book->orderCount++] = (Order){type, price, quantity};
    } else {
        printf("Order book is full!\n");
    }
}

void matchOrders(OrderBook *book) {
    for (int i = 0; i < book->orderCount; i++) {
        if (book->orders[i].type == 'S') {
            for (int j = 0; j < book->orderCount; j++) {
                if (book->orders[j].type == 'B' && book->orders[j].price >= book->orders[i].price) {
                    int tradeQuantity = book->orders[i].quantity < book->orders[j].quantity ? book->orders[i].quantity : book->orders[j].quantity;
                    printf("Matched: %d shares at $%.2f between %s (buy) and %s (sell)\n",
                           tradeQuantity, book->orders[i].price, "Buyer", "Seller");
                    book->orders[i].quantity -= tradeQuantity;
                    book->orders[j].quantity -= tradeQuantity;

                    if (book->orders[i].quantity == 0) {
                        // Remove sell order
                        book->orders[i] = book->orders[--book->orderCount];
                        i--; // Adjust index since we removed an order
                        break;
                    }

                    if (book->orders[j].quantity == 0) {
                        // Remove buy order
                        book->orders[j] = book->orders[--book->orderCount];
                        j--; // Adjust index since we removed an order
                    }
                }
            }
        }
    }
}

void simulateTrading(TradingBot bots[], OrderBook *book) {
    srand(time(0));
    for (int i = 0; i < 10; i++) { // Simulate 10 rounds of trading
        for (int j = 0; j < MAX_BOTS; j++) {
            int action = rand() % 2; // 0 for buy, 1 for sell
            int quantity = rand() % 3 + 1; // Random quantity between 1 and 3
            float price = (rand() % 100) + (rand() % 100) / 100.0; // Random price between $0.00 and $100.00

            if (action == 0) { // Buy
                if (bots[j].cash >= price * quantity) {
                    addOrder(book, 'B', price, quantity);
                    bots[j].cash -= price * quantity;
                    bots[j].shares += quantity;
                    printf("%s placed a buy order: %d shares at $%.2f\n", bots[j].name, quantity, price);
                }
            } else { // Sell
                if (bots[j].shares >= quantity) {
                    addOrder(book, 'S', price, quantity);
                    bots[j].shares -= quantity;
                    bots[j].cash += price * quantity;
                    printf("%s placed a sell order: %d shares at $%.2f\n", bots[j].name, quantity, price);
                }
            }
        }
        matchOrders(book);
    }
}

int main() {
    TradingBot bots[MAX_BOTS];
    OrderBook book = { .orderCount = 0 };

    initializeBots(bots);
    simulateTrading(bots, &book);

    return 0;
}
