#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

void insertionSort(int *arr, int n) {
  for (int i = 1; i < n; ++i)
    for (int j = i - 1; j >= 0 && arr[j + 1] < arr[j]; --j)
      std::swap(arr[j], arr[j + 1]);
}

int main() {
  int arr[] = {8, 5, 9, 7, 1, 8, 7, 10, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  insertionSort(arr, n);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;

  return 0;
}