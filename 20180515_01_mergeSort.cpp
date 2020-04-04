#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

void merge(int *arr, int L, int R);
void mergeSort(int *arr, int L, int R);
void mergeSort(int *arr, int n) { mergeSort(arr, 0, n - 1); }

void mergeSort(int *arr, int L, int R) {
  if (L == R) return;
  int mid = (L + R) / 2;

  mergeSort(arr, L, mid);
  mergeSort(arr, mid + 1, R);
  merge(arr, L, R);
}

void merge(int *arr, int L, int R) {
  if (L == R) return;

  int *help = new int[R - L + 1];
  int mid = (L + R) / 2;
  int i = L, j = mid + 1, k = 0;
  while (i <= mid && j <= R) {
    help[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
  }

  while (i <= mid) {
    help[k++] = arr[i++];
  }

  while (j <= R) {
    help[k++] = arr[j++];
  }

  k = 0;
  while (k < (R - L + 1)) {
    arr[k + L] = help[k++];
  }
  delete[] help;
  help = nullptr;
}


/*
//20200404 review
void merge(int *arr, int L, int R);
void merge_sort(int *arr, int L, int R);
void merge_sort(int *arr, int n) { return merge_sort(arr, 0, n - 1); }
void merge_sort(int *arr, int L, int R) {
  if (L == R) {
    return;
  }

  int mid = L + (R - L) / 2;
  merge_sort(arr, L, mid);
  merge_sort(arr, mid + 1, R);
  merge(arr, L, R);
}

void merge(int *arr, int L, int R) {
  if (L == R) {
    return;
  }
  int *help = new int[R - L + 1]();
  int mid = L + (R - L) / 2;
  int i = L, j = mid + 1, k = 0;
  while (i <= mid && j <= R) {
    help[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
  }
  while (i <= mid) {
    help[k++] = arr[i++];
  }
  while (j <= R) {
    help[k++] = arr[j++];
  }

  k = 0;
  while (k < (R - L + 1)) {
    arr[L + k] = help[k++];
  }
  delete[] help;
  help = nullptr;
}

*/

int main() {
  int arr[] = {8, 5, 9, 7, 1, 8, 7, 10, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  mergeSort(arr, n);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;

  return 0;
}