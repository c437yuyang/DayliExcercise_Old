#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

class Solution
{
  public:
	int singleNumber(int A[], int n)
	{
		if (A == nullptr || n <= 0)
			return -1;
		int xor = 0;
		for (int i = 0; i < n; ++i)
		{
			xor ^= A[i];
		}
		return xor;
	}
};

int main()
{
	Solution s;
	int arr[] = {1, 1, 2, 2, 3};
	assert(s.singleNumber(arr, 5) == 3);

	return 0;
}