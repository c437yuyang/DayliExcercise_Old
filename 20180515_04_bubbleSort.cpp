#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
void bubbleSort(int *arr, int n)
{
    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < i; ++j)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

int main()
{
    int arr[] = {8, 5, 9, 7, 1, 8, 7, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
    std::cout << std::endl;
    bubbleSort(arr, n);

    std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
    std::cout << std::endl;

    return 0;
}