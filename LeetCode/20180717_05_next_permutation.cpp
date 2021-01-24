/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3→1,3,2
3,2,1→1,2,3
1,1,5→1,5,1
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

/*
思路：
首先从后往前查找第一个满足i-1<i的位置i，如果找不到，说明这个排列是降序的，那么返回所有数的顺序排列；
否则，说明i及以后的排列是降序的，首先将该部分置换为升序的，
然后从中找比i-1位置处的值大的最小的那个数(就是在后半部分找，后半部分现在是升序的,就是第一个比i-1位置大的数)，
然后将i-1位置处的数与找到的数进行交换即可。
//看 1423的例子
*/

class Solution
{
public:
	void nextPermutation(std::vector<int> &num)
	{
		if (num.size() <= 1)
			return;

		int i = num.size() - 1;
		while (i > 0 && num[i] <= num[i - 1])
			--i;

		//i位置和以后的，是逆序的
		if (i == 0)
			std::reverse(num.begin(), num.end());
		else
		{
			//先逆序后面的
			std::reverse(num.begin() + i, num.end());
			int j = i;
			while (j < num.size() && num[j] <= num[i - 1])
				++j;
			std::swap(num[j], num[i - 1]);
		}


	}
};



int main()
{
	
	Solution s;
	std::vector<int> v = { 1,2,3,4 };
	s.nextPermutation(v);
	std::vector<int> res{ 1, 2, 4, 3 };
	assert(v == res);

	s.nextPermutation(v);
	 res = { 1, 3,2,4 };
	assert(v == res);

	s.nextPermutation(v);
	res = { 1, 3,4,2 };
	assert(v == res);

	s.nextPermutation(v);
	res = { 1, 4,2,3 };
	assert(v == res);

	v = { 1,1,5};
	s.nextPermutation(v);
	res = { 1, 5,1};
	assert(v == res);

	return 0;
}


