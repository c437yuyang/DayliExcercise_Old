/*
n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，
问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。
输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。
输出描述:
输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。
示例1
输入
复制
4
7 15 9 5
输出
复制
3
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
using namespace std;

int solve2(std::vector<int>& arr)
{
	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	if (sum % arr.size() != 0)
		return -1;

	int target = sum / arr.size();
	int res = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (abs(arr[i] - target) % 2 != 0) //不能通过移动两个来实现的，就是错的
			return -1;
		if (target - arr[i] > 0)
			res += (target - arr[i]) / 2; //反正每次只能两个，因此不管如何，就看这个就行了
	}
	return res;
}

int main()
{
	//std::vector<int> arr = { 7,15,9,5 };
	//int res = solve1(arr);
	int n;
	cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << solve2(arr) << endl;

	return 0;
}