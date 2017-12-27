#include <iostream>
#include <string>

int get_key_recursive(int a[], int key, int low, int high)
{
    if (low > high) return -1;
    auto mid = low + (high - low) / 2;

    if (a[mid] == key) return mid;

    if (key < a[mid])
    {
        return get_key_recursive(a, key, low, mid - 1);
    }

    return get_key_recursive(a, key, mid + 1, high);    
}

int get_key_iterative(int a[], int key, int low, int high)
{
    while (low < high)
    {
        auto mid = low + (high - low) / 2;
        if (key == a[mid]) return mid;
        if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

void print_status(int key, int index, std::string type)
{
    std::cout << type << " method: \n";
    if (index != -1)
    {
        std::cout << "The key '" << key << "' was found at index: "
                  << index << "." << "\n";
    }
    else
    {
        std::cout << "The key '" << key << "' was not found.\n";
    }
}

int main(int argc, char **argv)
{
    int a[] = {1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162,
               176, 188, 199, 200, 210, 222};

    int key = 59;
    auto index = get_key_recursive(a, key, 0, 19);
    print_status(key, index, "Recursive");

    index = get_key_iterative(a, key, 0, 19);
    print_status(key, index, "Iterative");
    
    key = 76;
    index = get_key_recursive(a, key, 0, 19);
    print_status(key, index, "Recursive");

    index = get_key_iterative(a, key, 0, 19);
    print_status(key, index, "Iterative");
    
    return 0;
}
