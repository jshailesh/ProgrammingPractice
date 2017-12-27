#include <iostream>
#include <vector>
#include <list>

void find_max_sliding_window(const std::vector<int> & arr, int wSize)
{
    std::list<int> window;

    // Process the first 'wSize' elements from the array
    // For each of those elements
    // 1. Remove the elements from the tail of the list
    //    if they are smaller than or equal to the current
    //    element
    // 2. Push the current element at the tail of the list
    for (int i = 0; i < wSize; ++i)
    {
        while (!window.empty() && arr[window.back()] <= arr[i])
        {
            window.pop_back();
        }
        window.push_back(i);
    }

    std::cout << arr[window.front()] << ", ";

    // Process the remaining elements now
    // For each of those elements
    // 1. Remove the elements from the tail of the list
    //    if they are smaller than or equal to the current
    //    element
    // 2. Remove the element at the head of the list, if the
    //    index for the element falls outside of the window
    // 3. Push the current element at the tail of the list
    for (int i = wSize; i < arr.size(); ++i)
    {
        while (!window.empty() && arr[i] >= arr[window.back()])
        {
            window.pop_back();
        }

        if (!window.empty() &&
            window.front() <= i - wSize) window.pop_front();
        window.push_back(i);

        std::cout << arr[window.front()] << ", ";
    }

    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<int> arr{-4, 1, -2, -3, -1, 2, 4, 6};
    find_max_sliding_window(arr, 3);

    return 0;
}
