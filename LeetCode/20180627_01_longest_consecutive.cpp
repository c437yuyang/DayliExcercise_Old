/*


Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given[100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length:4.

Your algorithm should run in O(n) complexity.


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
	
	//牛客看到的,用hash表，然后每个数都往前找
	int longestConsecutive(vector<int> &num)
	{
		if (num.empty())
			return 0;
		std::unordered_set<int> s(num.begin(), num.end());
		int max = 1;
		for (auto cur : num)
		{
			if (s.find(cur) == s.end())
				continue;
			s.erase(cur);
			int prev = cur - 1;
			int next = cur + 1;
			while (s.find(prev) != s.end())
				s.erase(prev--); //因为这里删掉了，所以保证是O(n),最多每个数两次被遍历到
			while (s.find(next) != s.end())
				s.erase(next++);
			max = std::max(max, next - prev - 1);
		}
		return max;
	}

	//自己的做法，O(nlogn)
	int longestConsecutive2(vector<int> &num)
	{
		if (num.empty())
			return 0;
		std::set<int> s;
		for (size_t i = 0; i < num.size(); ++i)
			s.insert(num[i]);

		auto it = s.begin();
		int pre = *it;
		++it;
		int maxLen = 1;
		int curLen = 1;
		for (; it != s.end(); ++it)
		{
			if (*it - pre == 1)
				++curLen;
			else
				curLen = 1;
			pre = *it;
			maxLen = std::max(curLen, maxLen);
		}
		return maxLen;
	}
};

int main()
{
	std::vector<int> num{ 100,1,3,200,4,2 };

	return 0;
}