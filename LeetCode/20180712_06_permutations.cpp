//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 150;
//
//#define cle(x) memset(x, 0, sizeof(x))
//int a[N], b[N];
//int main()
//{
//	//freopen("in.txt","r",stdin);
//	//freopen("out.txt","w",stdout);
//	int n, x;
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//			b[i] = i;
//		}
//		do
//		{
//			int sum = 0;
//			for (int i = 0; i < n; i++)
//			{
//				sum += a[b[i]];
//				if (sum == 100)
//				{
//					cout << i + 1 << endl;
//					for (int j = 0; j <= i; j++)
//						cout << b[j] + 1 << endl;
//					return 0;
//				}
//			}
//		}
//		while (next_permutation(b, b + n));
//	}
//	return 0;
//}

/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3]have the following permutations:
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], and[3,2,1].
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;
class Solution
{
public:
	vector<vector<int> > permutations(vector<int> &num)
	{
		std::vector<std::vector<int>> res;
		permutationProcess(num, 0, res);
		return res;
	}

	void permutationProcess(std::vector<int>&nums, int i,
		std::vector<std::vector<int>> &res)
	{
		if (i == nums.size() - 1)
		{
			std::vector<int> curRes(nums.begin(), nums.end());
			res.push_back(curRes);
		}
		else
		{
			for (size_t j = i; j < nums.size(); ++j)
			{
				keepOrderSwap1(nums, i, j);
				permutationProcess(nums, i + 1, res);
				keepOrderSwap2(nums, i, j);
			}
		}
	}

	template<class T>
	void keepOrderSwap1(std::vector<T>&arr, size_t i, size_t j)
	{
		char tmp = arr[j];
		for (size_t i1 = j; i1 > i; --i1)
			arr[i1] = arr[i1 - 1];
		arr[i] = tmp;
	}

	//从后往前移动
	template<class T>
	void keepOrderSwap2(std::vector<T>&arr, size_t i, size_t j)
	{
		char tmp = arr[i];
		for (size_t i1 = i; i1 < j; ++i1)
			arr[i1] = arr[i1 + 1];
		arr[j] = tmp;
	}

};


//另外一种写法:采用存到curRes里面的做法
class Solution1
{
public:
	vector<vector<int> > permutations(vector<int> &num)
	{
		std::vector<int> curRes;
		std::vector<std::vector<int>> res;
		getPermutations(num, 0, curRes, res);
		return res;
	}

	void getPermutations(std::vector<int>&nums, int i, std::vector<int>&curRes, std::vector<std::vector<int>> &res)
	{
		if (i == nums.size() - 1)
		{
			curRes.push_back(nums[i]);
			res.push_back(curRes);
			curRes.pop_back(); //这里也要pop_back()!!!
		}
		else
		{
			for (size_t j = i; j < nums.size(); ++j)
			{
				std::swap(nums[j], nums[i]);
				curRes.push_back(nums[i]);
				getPermutations(nums, i + 1, curRes, res);
				curRes.pop_back();
				std::swap(nums[j], nums[i]);
			}
		}
	}
};


int main()
{
	std::vector<int> v = { 1,2,3 };
	Solution s;
	auto res = s.permutations(v);

	std::vector<std::vector<int>> res1;
	v = { 1,2,3 };
	do
	{
		res1.push_back(v);
	}
	while (next_permutation(v.begin(), v.end())); 

	assert(res == res1); //可以看到stl的也是采用了保持顺序不变的交换的
	return 0;
}