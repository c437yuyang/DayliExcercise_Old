#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

void insertion_sort(int *arr, int n) {
  if (arr == nullptr || n <= 1) {
    return;
  }

  // 把最小的依次插入到队列中来
  // i=1 是因为第一个数组成的队列必然有序
  for (int i = 1; i < n; ++i) {
    // j从i后面(i前面的一定有序)往前面找，依次交换从而插入到合适的位置，直到遇到了比它小的，因为已经是有序的，所以不需要往下就停止
    for (int j = i; j >= 1 && arr[j] < arr[j - 1]; --j) {
      // arr[j-1] > arr[j] 则交换来实现类似于插入的效果
      std::swap(arr[j], arr[j - 1]);
    }
  }
}

int main() {
  int arr[] = {8, 5, 9, 7, 1, 8, 7, 10, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  // quick_sort_with_span(arr, 0, n - 1);
  insertion_sort(arr, n);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  return 0;
}