#include <iostream>
#include <vector>

bool sum_of_two_exists(const std::vector<int> & arr, int val)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        auto sum = arr[left] + arr[right];
        if (sum == val) return true;
        if (sum < val) ++left;
        else --right;
    }

    return false;
}

int main(int argc, char **argv)
{
    std::vector<int> arr{1, 3, 4, 5, 7, 14, 15};
    int val;

    std::cout << "Enter a targeted sum value: ";
    std::cin >> val;

    bool found = sum_of_two_exists(arr, val);
    if (found) std::cout << "Exists.\n";
    else std::cout << "Does not exist.\n";

    return 0;
}
