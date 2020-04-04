#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>



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