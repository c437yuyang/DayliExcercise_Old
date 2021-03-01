#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int partition(int *arr, int L, int R) {
  if (L >= R) {
    return L;
  }

  int i = L - 1, j = R, pivot = arr[R];
  while (L < j) {
    if (arr[L] < pivot) {
      std::swap(arr[L++], arr[++i]);
    } else if (arr[L] == pivot) {
      L++;
    } else {
      std::swap(arr[L], arr[--j]);
    }
  }

  std::swap(arr[R], arr[j]);
  return j;
}

void quick_sort(int *arr, int L, int R) {
  if (L >= R) {
    return;
  }

  int pos = partition(arr, L, R);
  quick_sort(arr, L, pos - 1);
  quick_sort(arr, pos + 1, R);
}

std::vector<int> partition_with_span(int *arr, int L, int R) {
  if (L >= R) {
    return {R, L};
  }

  int i = L - 1, j = R, pivot = arr[R];
  while (L < j) {
    if (arr[L] < pivot) {
      std::swap(arr[L++], arr[++i]);
    } else if (arr[L] == pivot) {
      L++;
    } else {
      std::swap(arr[L], arr[--j]);
    }
  }

  std::swap(arr[R], arr[j]);
  return {i + 1, j - 1};
}

void quick_sort_with_span(int *arr, int L, int R) {
  if (L >= R) {
    return;
  }

  const auto &pos = partition_with_span(arr, L, R);
  quick_sort_with_span(arr, L, pos[0] - 1);
  quick_sort_with_span(arr, pos[1] + 1, R);
}

void quick_sort_no_recursive(int *arr, int L, int R) {
  if (L >= R || R - L < 2) {
    return;
  }
  std::stack<int> wait_for_sort_pos;
  wait_for_sort_pos.push(R);
  wait_for_sort_pos.push(L);
  while (!wait_for_sort_pos.empty()) {
    int l = wait_for_sort_pos.top();
    wait_for_sort_pos.pop();
    int r = wait_for_sort_pos.top();
    wait_for_sort_pos.pop();
    const auto &pos = partition_with_span(arr, l, r);
    if (pos[1] < r) {
      wait_for_sort_pos.push(r);
      wait_for_sort_pos.push(pos[1] + 1);
    }

    if (pos[0] > l) {
      wait_for_sort_pos.push(pos[0] - 1);
      wait_for_sort_pos.push(l);
    }
  }
}

int main() {
  int arr[] = {8, 5, 9, 7, 1, 8, 7, 10, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  // quick_sort_with_span(arr, 0, n - 1);
  quick_sort_no_recursive(arr, 0, n - 1);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  return 0;
}