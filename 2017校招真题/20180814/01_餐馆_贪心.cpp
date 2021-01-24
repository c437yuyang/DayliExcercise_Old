/*
某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数； 有m批客人，每批客人有两个参数:b人数，c预计消费金额。 在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大
输入描述:
输入包括m+2行。 第一行两个整数n(1 <= n <= 50000),m(1 <= m <= 50000) 第二行为n个参数a,即每个桌子可容纳的最大人数,以空格分隔,范围均在32位int范围内。 接下来m行，每行两个参数b,c。分别表示第i批客人的人数和预计消费金额,以空格分隔,范围均在32位int范围内。
输出描述:
输出一个整数,表示最大的总预计消费金额
示例1
输入
复制
3 5 
2 4 2 
1 3 
3 5 
3 7 
5 9 
1 10
输出
复制
20

4 6
12 1 4 7
11 3
3 10
35 10
5 9
12 10
6 7

29
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <functional>
using namespace std;
//几个点:
//1.不一定每批客人都能找到桌子
//2.输出是long long才够


//15.08
struct Customer
{
	int peoplenum;
	int money;
};

//AC 80%
long long solve(vector<int>& desks, vector<Customer> &customers)
{
	long long res = 0;

	std::sort(desks.begin(), desks.end(), std::less<int>()); //先满足小桌的

	for (int i = 0; i < desks.size(); ++i)
	{
		int deskCapacity = desks[i];
		int maxmoney = std::numeric_limits<int>::min();
		int maxIdx = -1;
		for (int j = 0; j < customers.size(); ++j)
			if (customers[j].peoplenum <= desks[i] && maxmoney < customers[j].money)
			{
				maxIdx = j;
				maxmoney = customers[j].money;
			}
		if (maxIdx != -1)
		{
			res += customers[maxIdx].money;
			customers.erase(customers.begin() + maxIdx);
		}
	}
	return res;
}

//AC
long long solve1(vector<int>& desks, vector<Customer> &customers)
{
	long long res = 0;

	std::sort(desks.begin(), desks.end(), std::less<int>()); //先满足小桌的
	std::sort(customers.begin(), customers.end(),//客人按照人数排序
		[](const Customer&cus1, const Customer&cus2) { return cus1.peoplenum < cus2.peoplenum; });
	for (int i = 0; i < desks.size(); ++i)
	{
		int maxmoney = std::numeric_limits<int>::min();
		int maxIdx = -1;
		for (int j = 0; j < customers.size(); ++j)
			if (customers[j].peoplenum <= desks[i] && maxmoney < customers[j].money)
			{
				maxIdx = j;
				maxmoney = customers[j].money;
			}else if(customers[j].peoplenum > desks[i]) //如果人数超过了直接break
				break;
		if (maxIdx != -1)
		{
			res += customers[maxIdx].money;
			customers.erase(customers.begin() + maxIdx);
		}
	}
	return res;
}


int main()
{
	int desknum, custnum;
	cin >> desknum >> custnum;
	vector<int> desks(desknum);
	for (int i = 0; i < desknum; ++i)
		cin >> desks[i];
	vector<Customer> customers(custnum);
	for (int i = 0; i < custnum; ++i)
	{
		cin >> customers[i].peoplenum;
		cin >> customers[i].money;
	}
	cout << solve1(desks, customers) << endl;

	return 0;
}
