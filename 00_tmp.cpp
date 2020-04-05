#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
  int arr[] = {8, 5, 9, 7, 1, 8, 7, 10, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  // merge_sort(arr, n);

  // int res = partition(arr, 0, n - 1);
  // std::cout << res << std::endl;
  selection_sort(arr, n);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;

  return 0;
}