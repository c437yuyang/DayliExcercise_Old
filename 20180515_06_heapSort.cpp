#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>

inline int parent(int i) { return (i - 1) >> 1; }
inline int right(int i) { return (i << 1) + 2; }
inline int left(int i) { return (i << 1) + 1; }
void build_heap(int *arr, int n);
void heapify(int *arr, int top, int n);

void heapSort(int *arr, int n)
{
	build_heap(arr, n);
	for (int i = 0; i < n; ++i)
	{
		std::swap(arr[0], arr[n - i - 1]);
		heapify(arr, 0, n - i - 1);
	}
}

//从倒数第二层节点网上heapify
void build_heap(int *arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		heapify(arr, i, n);
	}
}

//top的左右子树都是大根堆了
void heapify(int *arr, int top, int n)
{
	int cur = top;
	while (cur < n)
	{
		int max = cur;
		if (left(cur) < n && arr[max] < arr[left(cur)])
			max = left(cur);

		if (right(cur) < n && arr[max] < arr[right(cur)])
			max = right(cur);

		if (max != cur)
		{
			std::swap(arr[max], arr[cur]);
			cur = max;
		}
		else
			break;
	}
}

int main()
{
	// int arr[] = { 8,5,9,7,1,8,7,10,3 };	
	int arr[] = {10,7,12,98,11,121,0,112};

	int n = sizeof(arr) / sizeof(arr[0]);

	std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
	std::cout << std::endl;
	heapSort(arr, n);

	std::for_each(arr, arr + n, [](int val) { std::cout << val << " "; });
	std::cout << std::endl;

	return 0;
}