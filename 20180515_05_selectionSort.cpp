#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>

/*
// 20200404 review
// 选出最大的放到最后
void selection_sort(int *arr, int n) {
  int max_idx = -1;
  int max_val = -1;
  for (int i = n - 1; i > 0; --i) { // 不需要=0 因为剩下最后一个的时候就是最小了
    max_val = arr[0]; 
    max_idx = 0;
    for (int j = 1; j <= i; ++j) { // 需要等号
      if (max_val < arr[j]) {
        max_idx = j;
        max_val = arr[j];
      }
    }
    std::swap(arr[i], arr[max_idx]);
  }
}
*/

void selectionSort(int *arr, int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		int max_idx = 0;
		for (int j = 1; j <= i; ++j)
			if (arr[j] > arr[max_idx])
				max_idx = j;
		std::swap(arr[max_idx], arr[i]);
	}
}


int main()
{
	int arr[] = { 8,5,9,7,1,8,7,10,3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
	std::cout << std::endl;
	selectionSort(arr, n);

	std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
	std::cout << std::endl;

	return 0;
}