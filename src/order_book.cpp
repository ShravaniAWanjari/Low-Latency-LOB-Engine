#include "order_book.hpp"
#include <iostream>

void OrderBook::addOrder(const Order& order){
    Order incoming = order;
    
    if (incoming.side == Side::Buy){
        matchBuy(incoming);
        if (incoming.quantity > 0){
            bids[incoming.price].push_back(incoming);
        }
    } else{
        matchSell(incoming);
        if (incoming.quantity > 0){
            asks[incoming.price].push_back(incoming);
        }
    }
}


void OrderBook::matchBuy(Order& buyOrder) {
    while (buyOrder.quantity > 0 && !asks.empty()) {

        auto bestAskIt = asks.begin(); // lowest ask
        double bestAskPrice = bestAskIt->first;

        if (bestAskPrice > buyOrder.price) {
            break; // no match possible
        }

        auto& askQueue = bestAskIt->second;

        while (buyOrder.quantity > 0 && !askQueue.empty()) {
            Order& sellOrder = askQueue.front();

            std::uint32_t tradedQty = std::min(buyOrder.quantity, sellOrder.quantity);

            buyOrder.quantity -= tradedQty;
            sellOrder.quantity -= tradedQty;

            std::cout << "Trade: "
                      << tradedQty << " @ "
                      << bestAskPrice << "\n";

            if (sellOrder.quantity == 0) {
                askQueue.pop_front();
            }
        }

        if (askQueue.empty()) {
            asks.erase(bestAskIt);
        }
    }
}

void OrderBook::matchSell(Order& sellOrder) {
    while (sellOrder.quantity > 0 && !bids.empty()) {

        auto bestBidIt = bids.begin();  // highest bid
        double bestBidPrice = bestBidIt->first;

        if (bestBidPrice < sellOrder.price) {
            break;  // no match possible
        }

        auto& bidQueue = bestBidIt->second;

        while (sellOrder.quantity > 0 && !bidQueue.empty()) {

            Order& buyOrder = bidQueue.front();

            std::uint32_t tradedQty =
                std::min(buyOrder.quantity, sellOrder.quantity);

            buyOrder.quantity -= tradedQty;
            sellOrder.quantity -= tradedQty;

            std::cout << "Trade: "
                      << tradedQty << " @ "
                      << bestBidPrice << "\n";

            if (buyOrder.quantity == 0) {
                bidQueue.pop_front();
            }
        }

        if (bidQueue.empty()) {
            bids.erase(bestBidIt);
        }
    }
}
