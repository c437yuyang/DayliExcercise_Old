/*
Given an index k, return the k th row of the Pascal's triangle.
For example, given k = 3,
Return[1,3,3,1].
Note:
Could you optimize your algorithm to use only O(k) extra space?
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace std;
using namespace yxp_utility;
class Solution
{
  public:
	vector<int> getRow(int rowIndex)
	{
		if (rowIndex == 0)
			return {1};
		if (rowIndex == 1)
			return {1, 1};
		std::vector<int> v(rowIndex + 1, 1);
		auto vTemp = v;
		for (int i = 2; i <= rowIndex; ++i) //从第三行开始需要循环
		{
			for (int j = 1; j < i; ++j) //从第二个数到倒数第二个数需要求解
				v[j] = vTemp[j - 1] + vTemp[j];
			vTemp = v;
		}
		return v;
	}
};

int main()
{
	Solution s;
	ArrayHelper::printArr(s.getRow(4));

	return 0;
}