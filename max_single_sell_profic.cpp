#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

std::tuple<int, int> find_buy_sell_prices(const std::vector<int> & stock_prices)
{
    if (stock_prices.empty()) return std::make_tuple(nullptr, nullptr);
    
    auto current_profit = std::numeric_limits<int>::min();
    auto current_buy    = stock_prices[0];
    auto global_sell    = stock_prices[1];
    auto global_profit  = global_sell - current_buy;
    
    for (int i = 1; i < stock_prices.size(); ++i)
    {
        current_profit = stock_prices[i] - current_buy;
        if (current_profit > global_profit)
        {
            global_profit = current_profit;
            global_sell = stock_prices[i];
        }

        if (stock_prices[i] < current_buy)
        {
            current_buy = stock_prices[i];
        }
    }

    return std::make_tuple(global_sell - global_profit,
                           global_sell);
}

int main(int argc, char **argv)
{
    std::vector<int> stock_prices{8, 5, 12, 9, 19, 1};
    int buy, sell;
    std::tie(buy, sell) = find_buy_sell_prices(stock_prices);
    std::cout << "Buy: " << buy << ", Sell: " << sell << "\n";

    stock_prices = {21, 12, 11, 9, 6, 3};
    std::tie(buy, sell) = find_buy_sell_prices(stock_prices);
    std::cout << "Buy: " << buy << ", Sell: " << sell << "\n";


    return 0;
}
