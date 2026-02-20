#pragma once
#include "order.hpp"
#include <map>
#include <deque>



class OrderBook{
    public:
        void addOrder(const Order& order);

    private:
        std::map<double, std::deque<Order>, std::greater<double>> bids;

        std::map<double, std::deque<Order>> asks;

        void matchBuy(Order& order);
        void matchSell(Order& order);
    
};