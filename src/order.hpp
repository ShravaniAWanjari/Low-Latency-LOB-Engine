#pragma once

#include <cstdint>

enum class Side {
    Buy,
    Sell
};

struct Order {
    std::uint64_t id;
    double price;
    std::uint32_t quantity;
    Side side;

    Order(std::uint64_t id_,
          double price_,
          std::uint32_t quantity_,
          Side side_)
        : id(id_), price(price_), quantity(quantity_), side(side_) {}
};