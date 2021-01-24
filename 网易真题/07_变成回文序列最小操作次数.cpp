/*
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列,
{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。
输入描述:
输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50) 第二行为序列中的n个整数item[i] (1 ≤ iteam[i] ≤ 1000)，以空格分隔。
输出描述:
输出一个数，表示最少需要的转换次数
示例1
输入
复制
4
1 1 1 3
输出
复制
2
*/
#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
#include <deque>
using namespace std;

//题意是一定能够转换
//思路就是，左边小就左边加，右边小就右边加，双指针往中间找
int solve(std::deque<int> &arr)
{
	if (arr.size() == 1)
		return 0;

	if (arr.size() == 2)
	{
		return arr[0] == arr[1] ? 0 : 1;
	}

	int left = 0, right = arr.size() - 1;
	int cnt = 0;
	while (left < right && arr.size() > 2)
	{
		if (arr[left] < arr[right])
		{
			arr[left+1] += arr[left];
			arr.erase(arr.begin() + left);
			right -= 1;
			++cnt;
		}
		else if (arr[left] > arr[right])
		{
			arr[right - 1] += arr[right];
			arr.pop_back();
			right -= 1;
			++cnt;
		}
		else
		{
			++left;
			--right;
		}
	}
	if (arr[left] != arr[right]) //最后不相等，比如3,2最后是，还得加一次
		cnt += 1;

	return cnt; 
}



int main()
{
	//int n;
	//cin >> n;
	//deque<int> queue(n);
	//for (int i = 0; i < n; ++i)
	//{
	//	cin >> queue[i];
	//}

	//deque<int> queue = { 10,40,1,3,32,14,1,1,1,1,3,1,17,73,7,3,11,27,2,2,2,14
	//	,38,7,2,13,36,1,1,1,1,14,36,2,1,1,1,4,81,55,36,91,90,54,58,56,50,98,50,50 };
	deque<int> queue = { 1,1,1,3 };

	cout << solve(queue) << endl;


	return 0;
}