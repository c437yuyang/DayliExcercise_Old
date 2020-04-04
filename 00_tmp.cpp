#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

//

void bubble_sort(int *arr, int n) {
  // 小的冒到前面来,从后往前遍历
  // for (int i = 0; i < n; ++i) {
  //   for (int j = n - 1; j > i; --j) {
  //     if (arr[j] < arr[j - 1]) {
  //       std::swap(arr[j], arr[j - 1]);
  //     }
  //   }
  // }

  // 大的冒到后面，从前往后
  for (int i = n - 1; i >= 1; --i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int arr[] = {8, 5, 9, 7, 1, 8, 7, 10, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  bubble_sort(arr, n);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
}