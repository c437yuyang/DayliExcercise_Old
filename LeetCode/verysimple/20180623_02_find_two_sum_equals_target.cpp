/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/
#include <vector>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int> &numbers, int target)
	{
		std::unordered_map<int, size_t> map;
		map.insert({ numbers[0], 0 });
		for (size_t i = 1; i < numbers.size(); ++i)
		{
			if (map.find(target - numbers[i]) != map.end())
				return{ (int)map[target - numbers[i]] + 1, (int)i + 1 }; //题目假设的只有一组输出解
			else
				map.insert({ numbers[i],i });
		}
		return{};
	}
};

int main()
{
	std::vector<int> numbers = { 2, 7, 11, 15,8 };
	Solution s;
	auto v = s.twoSum(numbers, 15);

	return 0;
}
