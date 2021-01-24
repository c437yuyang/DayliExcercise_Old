#include <YXPUtility>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>
using namespace std;
void quickSort(int *arr, int L, int R);
std::vector<int> partition(int *arr, int L, int R);

void quickSort(int *arr, int n) { quickSort(arr, 0, n - 1); }

void quickSort(int *arr, int L, int R) {
  if (L >= R)  //重要!!!
    return;
  auto v = partition(arr, L, R);
  quickSort(arr, L, v[0] - 1);
  quickSort(arr, v[1] + 1, R);
}

std::vector<int> partition(int *arr, int L, int R) {
  int p = L - 1;
  int q = R;
  int l = L;
  int pivot = arr[R];
  while (l < q) {
    if (arr[l] < pivot)
      std::swap(arr[++p], arr[l++]);
    else if (arr[l] > pivot)
      std::swap(arr[--q], arr[l]);
    else  //相等
      ++l;
  }
  std::swap(arr[R], arr[q]);
  return {p + 1, q};  //返回相等区域
}

void QuickSort(int *arr, int n) {
  if (arr == NULL || n <= 1) return;
  std::stack<int> wait2SortSpan;
  int left, right;
  //（注意保存顺序）先将初始状态的左右指针压栈
  wait2SortSpan.push(n - 1);  //先存右指针
  wait2SortSpan.push(0);      //再存左指针
  while (!wait2SortSpan.empty()) {
    left = wait2SortSpan.top();  //先弹出左指针
    wait2SortSpan.pop();
    right = wait2SortSpan.top();  //再弹出右指针
    wait2SortSpan.pop();
    if (left < right) {
      auto k = partition(arr, left, right);
      if (k[0] > left)  //左边部分还需要排序
      {
        wait2SortSpan.push(k[0] - 1);  //存入区间
        wait2SortSpan.push(left);
      }
      if (right > k[1])  //右边部分还需要排序
      {
        wait2SortSpan.push(right);
        wait2SortSpan.push(k[1] + 1);
      }
    }
  }
}

/*
// 20200404 review

int partition(int *arr, int L, int R) {
  if (L >= R) {
    return L;
  }
  int i = L, j = R - 1;
  int pivot = arr[R];
  while (i <= j) { // 这种写法是必须带等于的
    if (arr[i] > pivot) {
      std::swap(arr[i], arr[j--]);
    } else if (arr[i] <= pivot) {
      i++;
    }
  }
  std::swap(arr[i], arr[R]);
  return i;
}

void quick_sort(int *arr, int L, int R) {
  if (L >= R) {
    return;
  }
  int pos = partition(arr, L, R);
  quick_sort(arr, L, pos - 1);
  quick_sort(arr, pos + 1, R);
}

*/

int main() {
  // int arr[] = { 8,5,9,7,1,8,7,10,3 };
  int arr[] = {4, 4, 3, 0, 0};
  int arr[] = {3, 1, 5, 7, 6};
  // int arr[] = {10,7,12,98,11,121,0,112};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;
  // quickSort(arr, n);
  quickSortNoRecur(arr, n);

  assert(yxp_utility::RandomHelper::sortCheck(100, 100, 0, 100, QuickSort));
  assert(yxp_utility::RandomHelper::sortCheck(100, 100, 0, 100, quickSort));
  assert(
      yxp_utility::RandomHelper::sortCheck(100, 100, 0, 100, quickSortNoRecur));
  // assert(SortCheck(100, 100, quickSort));

  std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
  std::cout << std::endl;

  return 0;
}