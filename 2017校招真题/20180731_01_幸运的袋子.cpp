/*
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)
输出描述:
输出可以产生的幸运的袋子数
示例1
输入
3
1 1 1
输出
2
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cassert>
using namespace std;
bool isLucky(std::vector<int> & nums);
void getSubSets(std::vector<int> &arr, vector<int>&curRes, int i, std::vector<std::vector<int>> &res);


//方法1，暴力求解，找所有的子集，然后求解,20%通过，超时
//正确解法是要进行dfs+剪枝，没怎么看懂
int getLuckCount(std::vector<int> & nums)
{
	std::sort(nums.begin(), nums.end());
	std::vector<std::vector<int>> res;
	std::vector<int> curres;
	getSubSets(nums, curres, 0, res);
	int cnt = 0;
	for (int i=0;i<res.size();++i)
	{
		if (isLucky(res[i]))
			++cnt;
	}
	return cnt;
}

void getSubSets(std::vector<int> &arr, vector<int>&curRes,int i,std::vector<std::vector<int>> &res)
{
	if (i == arr.size())
	{
		if (!curRes.empty() &&std::find(res.begin(), res.end(), curRes) == res.end())
			res.push_back(curRes);
		return;
	}
	
	getSubSets(arr, curRes, i + 1, res);
	curRes.push_back(arr[i]);
	getSubSets(arr, curRes, i + 1, res);
	curRes.pop_back();
}



bool isLucky(std::vector<int> & nums)
{
	long long sumres = std::accumulate(nums.begin(), nums.end(), 0);
	long long prodres = std::accumulate(nums.begin(), nums.end(), 1, [](int v1, int v2) { return v1*v2; });
	return sumres > prodres;
}


int getLuckCount1(std::vector<int> & nums)
{
	std::sort(nums.begin(), nums.end());
	std::vector<int>




}

int main()
{
	//vector<int> arr = { 1,2,4 };
	//assert(!isLucky(arr));
	//arr = { 1,1,2 };

	//assert(isLucky(arr));

	//arr = { 1,1,1 };
	int n;
	cin >> n;
	std::vector<int> arr(n);
	for (int i=0;i<n;++i)
	{
		cin >> arr[i];
	}
	std::cout << getLuckCount(arr) << std::endl;

	return 0;
}