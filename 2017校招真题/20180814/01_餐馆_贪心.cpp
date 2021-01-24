/*
ĳ�͹���n�����ӣ�ÿ��������һ��������a �����ɵ���������� ��m�����ˣ�ÿ����������������:b������cԤ�����ѽ� �ڲ�����ƴ��������£���ʵ��һ���㷨ѡ������һ���ֿ��ˣ�ʹ����Ԥ�����ѽ�����
��������:
�������m+2�С� ��һ����������n(1 <= n <= 50000),m(1 <= m <= 50000) �ڶ���Ϊn������a,��ÿ�����ӿ����ɵ��������,�Կո�ָ�,��Χ����32λint��Χ�ڡ� ������m�У�ÿ����������b,c���ֱ��ʾ��i�����˵�������Ԥ�����ѽ��,�Կո�ָ�,��Χ����32λint��Χ�ڡ�
�������:
���һ������,��ʾ������Ԥ�����ѽ��
ʾ��1
����
����
3 5 
2 4 2 
1 3 
3 5 
3 7 
5 9 
1 10
���
����
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
//������:
//1.��һ��ÿ�����˶����ҵ�����
//2.�����long long�Ź�


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

	std::sort(desks.begin(), desks.end(), std::less<int>()); //������С����

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

	std::sort(desks.begin(), desks.end(), std::less<int>()); //������С����
	std::sort(customers.begin(), customers.end(),//���˰�����������
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
			}else if(customers[j].peoplenum > desks[i]) //�������������ֱ��break
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
