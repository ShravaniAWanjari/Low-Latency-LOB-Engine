# Low-Latency-Limit-Order-Book-Engine
building the core of a stock exchange matching engine

1. there's bid orders and ask orders
2. We match bid orders prices >= ask order prices
3. If two same prices exist we match based on time priority

Seems simple, but I will be doing this in large scale where it can process 4M orders per second because that's what stock exchanges operate at.
and I am learning so its building and learning from scratch.


