/*
牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，其中有一些位置（不超过 10 个）看不清了，但是牛牛记得这个数列顺序对的数量是 k，顺序对是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。
输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含两个整数 n 和 k（1 <= n <= 100, 0 <= k <= 1000000000），接下来的 1 行，包含 n 个数字表示排列 A，其中等于0的项表示看不清的位置（不超过 10 个）。
输出描述:
输出一行表示合法的排列数目。
示例1
输入
复制
5 5
4 0 0 2 0
输出
复制
2
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <YXPUtility>

void getAllPermutations(std::vector<int> & arr, int i, std::vector<std::vector<int>> &res);
//思路很简单，就是找出没出现的数，所有排列找到，然后放进去看满足条件的数量就行了(就是暴力求解)

/*
//唯一的优化点:我没做，应该差不了多少

首先，顺序对的个数互不影响。也就是说，对于数组A来说，增加（插入）一个数字，其A的顺序对个数不变，所以新数组A+1的顺序对个数=数组A的顺序对+新插入的数字产生的顺序对.
进而推广到，增加c个数字，新数组A+c的顺序对=数组A的顺序对+数组c的顺序对+每个新插入的数字产生顺序对（共c个数字）。
所以，1）首先计算已经给出的数字共有arrbase个顺序对；
2）然后计算缺失的数字共有canbase个顺序对；
3）最后计算每个缺失的数字产生的顺序对；
对于2,3步骤，可以将缺失的数字（数组）进行全排列。
*/

int solve(std::vector<int>& arr, int n, int k)
{
	std::vector<int> notAppear;
	std::unordered_set<int> set(arr.begin(), arr.end());
	for (int i = 1; i <= n; ++i)
		if (set.find(i) == set.end())
			notAppear.push_back(i);

	std::vector<std::vector<int>> allPerms;
	getAllPermutations(notAppear, 0, allPerms);

	int res = 0;
	for (int permIdx = 0; permIdx < allPerms.size(); ++permIdx) //遍历每种排列
	{
		int curOrderPair = 0;
		auto arrCopy = arr;
		int permCurIdx = 0;
		for (int i = 0; i < arrCopy.size(); ++i) //先把0的全部填上
		{
			if (arrCopy[i] == 0)
			{
				arrCopy[i] = allPerms[permIdx][permCurIdx];
				++permCurIdx;
			}
		}
		//检查是否符合条件
		for (int i = 0; i < arrCopy.size(); ++i)
		{
			for (int j = i + 1; j < arrCopy.size(); ++j)
			{
				if (arrCopy[i] < arrCopy[j])
					++curOrderPair;
			}
		}
		if (curOrderPair == k)
		{
			++res;
			yxp_utility::ArrayHelper::printArr(arrCopy);
		}
	}
	return res;
}

//这个可以直接用stl的,其实还简单些
void getAllPermutations(std::vector<int> & arr, int i, std::vector<std::vector<int>> &res)
{
	if (i == arr.size())
	{
		res.push_back(arr);
		return;
	}

	for (int j = i; j < arr.size(); ++j)
	{
		std::swap(arr[i], arr[j]);
		getAllPermutations(arr, i + 1, res);
		std::swap(arr[i], arr[j]);
	}
}

int main()
{
	int n; int k;
	std::cin >> n >> k;
	std::vector<int> arr(n);
	for (int i=0;i<n;++i)
	{
		std::cin >> arr[i];
	}

	std::cout << solve(arr, n, k) << std::endl;

	return 0;
}