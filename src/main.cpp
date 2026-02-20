#include "order.hpp"
#include <iostream>
#include  "order_book.cpp"

int main() {
    OrderBook book;

    book.addOrder(Order(1, 100, 50, Side::Sell));
    book.addOrder(Order(2, 99, 40, Side::Sell));
    book.addOrder(Order(3, 101, 60, Side::Buy));

    return 0;
}