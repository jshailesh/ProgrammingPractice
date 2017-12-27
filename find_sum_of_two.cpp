#include <iostream>
#include <vector>
#include <unordered_set>

bool sum_of_two_exists(const std::vector<int> & arr, int val)
{
    std::unordered_set<int> found_values;
    for (const auto & item : arr)
    {
        if (found_values.find(val - item) != found_values.end())
        {
            return true;
        }
        found_values.insert(item);
    }

    return false;
}

int main(int argc, char **argv)
{
    std::vector<int> arr{5, 7, 1, 2, 8, 4, 3};
    int val;

    std::cout << "Enter a targeted sum value: ";
    std::cin >> val;

    bool found = sum_of_two_exists(arr, val);
    if (found) std::cout << "Exists.\n";
    else std::cout << "Does not exist.\n";

    return 0;
}
