/*
The set[1,2,3,…,n]contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"

Given n and k, return the k th permutation sequence.
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
	bool finded = false;
	string getPermutation(int n, int k)
	{
		std::string res = "";
		vector<char> arr;
		for (int i = 1; i <= n; ++i)
			arr.push_back('0' + i);
		getPermutationProcess(arr, 0, k, res);
		return res;
	}

	void getPermutationProcess(std::vector<char>& arr, int i, int& k, std::string&res)
	{
		if (finded)
			return;
		if (i == arr.size())
		{
			--k;
			if (k == 0)
			{
				res = std::string(arr.begin(), arr.end());
				finded = true;
			}
		}

		for (int j = i; j < arr.size(); ++j)
		{
			keepOrderSwap1(arr, i, j);
			getPermutationProcess(arr, i + 1, k, res);
			keepOrderSwap2(arr, i, j);
		}
	}

	//必须这么交换，比如1234,交换2和4,直接交换后是1432就乱了，这个交换后就是1423
	//这个和直接交换的区别，在getPermutation(3,3)的时候，最后两个顺序会有区别
	void keepOrderSwap1(std::vector<char>&arr, int i, int j)
	{
		char tmp = arr[j];
		for (int i1 = j; i1 > i; --i1)
			arr[i1] = arr[i1 - 1];
		arr[i] = tmp;
	}

	void keepOrderSwap2(std::vector<char>&arr, int i, int j)
	{
		char tmp = arr[i];
		for (int i1 = i; i1 < j; ++i1)
			arr[i1] = arr[i1 + 1];
		arr[j] = tmp;
	}

};

int main()
{
	Solution s;
	cout << s.getPermutation(3, 3) << endl;

	return 0;
}