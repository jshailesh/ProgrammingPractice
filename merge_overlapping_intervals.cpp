#include <iostream>
#include <vector>
#include <tuple>

using interval = std::vector<std::tuple<int, int>>;

std::tuple<int, int> merge_interval(const interval & interval_list)
{
    if (interval_list.empty()) return std::tuple<int, int>{};
    auto min_val = std::get<0>(interval_list[0]);
    auto upper_limit = std::get<1>(interval_list[0]);
    std::tuple<int, int> overlap_interval = std::make_tuple(min_val, upper_limit);
    for (std::size_t i = 1; i < interval_list.size(); ++i)
    {
        upper_limit = std::get<1>(interval_list[i]);
        if (upper_limit > std::get<1>(overlap_interval))
        {
            overlap_interval = std::make_tuple(min_val, upper_limit);
        }        
    }

    return overlap_interval;
}

int main(int argc, char **argv)
{
    interval interval_list{};
    std::vector<int> var_list{10, 12, 11, 15}; //{1, 5, 3, 7, 4, 6, 6, 8};
    for (std::size_t i = 0; i < var_list.size(); i = i + 2)
    {
        interval_list.push_back(std::make_tuple(var_list[i], var_list[i + 1]));
    }
    auto overlap_interval = merge_interval(interval_list);

    std::cout << "The overlapping interval is: "
              << "("
              << std::get<0>(overlap_interval)
              << ", "
              << std::get<1>(overlap_interval)
              << ")."
              << std::endl;
    
    return 0;
}
