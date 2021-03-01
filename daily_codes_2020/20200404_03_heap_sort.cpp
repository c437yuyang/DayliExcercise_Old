#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int left(int idx) { return idx * 2 + 1; }
int right(int idx) { return idx * 2 + 2; }
int parent(int idx) { return (idx - 1) / 2; }

// heap_size 表示 从[0,heap_size) 位置已经是大根堆了
// heap_insert 自下往上
void heap_insert(int *arr, int n, int heap_size) {
  if (arr == nullptr || n <= 1) {
    return;
  }

  int new_insert_idx = heap_size;
  while (arr[new_insert_idx] > arr[parent(new_insert_idx)]) {
    std::swap(arr[new_insert_idx], arr[parent(new_insert_idx)]);
    new_insert_idx = parent(new_insert_idx);
  }
}

void heap_build(int *arr, int n) {
  if (arr == nullptr || n <= 1) {
    return;
  }
  for (int i = 1; i < n; ++i) {
    heap_insert(arr, n, i);
  }
}

// 自上往下， heap_size 表示 从[0,heap_size) 位置是大根堆了
// void heapify(int *arr, int n, int heap_size) {
//   int idx = 0, max_idx = idx, max_val = arr[0]; // 从0开始往下heapify
//   do {
//     idx = max_idx;
//     max_val = arr[idx];
//     if (left(idx) < heap_size && arr[left(idx)] > max_val) {
//       max_idx = left(idx);
//       max_val = arr[left(idx)];
//     }

//     if (right(idx) < heap_size && arr[right(idx)] > max_val) {
//       max_idx = right(idx);
//       max_val = arr[right(max_idx)];
//     }

//     if (idx != max_idx) {
//       std::swap(arr[idx], arr[max_idx]);
//     }
//   } while (idx != max_idx);
// }

// top 的左右子树都已经是大根堆
void heapify(int *arr, int top, int heap_size) {
  int cur_idx = top;  // 为了代码易读性还是单独起一个变量，实际上是可以去掉的
  while (cur_idx < heap_size) {
    int max_idx = cur_idx;
    if (left(cur_idx) < heap_size && arr[left(cur_idx)] > arr[cur_idx]) {
      max_idx = left(cur_idx);
    }
    if (right(cur_idx) < heap_size && arr[right(cur_idx)] > arr[cur_idx]) {
      max_idx = right(cur_idx);
    }
    if (max_idx != cur_idx) {
      std::swap(arr[cur_idx], arr[max_idx]);
      cur_idx = max_idx;
    } else {
      break;
    }
  }
}

void heap_sort(int *arr, int n) {
  if (arr == nullptr || n <= 1) {
    return;
  }

  // 先建立大根堆
  for (int i = 1; i < n; ++i) {
    heap_insert(arr, n, i);
  }
  // 依次把每个堆顶(最大值)放到末尾
  for (int heap_size = n; heap_size > 1; heap_size--) {
    std::swap(arr[0], arr[heap_size - 1]);
    // heapify(arr, n, heap_size - 1); // 配合第一个版本
    heapify(arr, 0, heap_size - 1);  // 现在始终是给换到0这个位置
  }
}

int main() {
  int arr[] = {8, 5, 9, 7, 1, 8, 7, 10, 3};
  // int arr[] = {10,7,12,98,11,121,0,112};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  // quick_sort_with_span(arr, 0, n - 1);
  heap_sort(arr, n);
  // heap_build(arr, n);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;

  return 0;
}