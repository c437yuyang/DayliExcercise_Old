/*
找出n个数里最小的k个
输入描述:
每个测试输入包含空格分割的n+1个整数，最后一个整数为k值,n
不超过100。
输出描述:
输出n个整数里最小的k个数。升序输出
示例1
输入
复制
3 9 6 8 -10 7 -11 19 30 12 23 5
输出
复制
-11 -10 3 6 7
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <cstdio>
using namespace std;

std::priority_queue<int> getMinkNum(std::vector<int>&nums, int k)
{
	std::priority_queue<int> pq;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (pq.size() < k) //大根堆
			pq.push(nums[i]);
		else if (pq.top() > nums[i])
		{
			pq.pop();
			pq.push(nums[i]);
		}
	}
	return pq;
}


int main()
{
	vector<int> nums;
	int num;
	while (cin >> num)
		nums.push_back(num);
	int k = nums.back();
	nums.pop_back();
	auto v = getMinkNum(nums, k);
	std::stack<int> s;
	while (!v.empty())
	{
		s.push(v.top());
		v.pop();
	}
	while (s.size() > 1)
	{
		printf("%d ", s.top());
		s.pop();
	}
	printf("%d\n", s.top());

	return 0;
}

