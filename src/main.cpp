#include "order.hpp"
#include <iostream>

int main() {
    Order o1(1, 100.5, 10, Side::Buy);

    std::cout << "Order ID: " << o1.id << "\n";
    std::cout << "Price: " << o1.price << "\n";
    std::cout << "Quantity: " << o1.quantity << "\n";

    return 0;
}