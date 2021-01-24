/*
�ҳ�n��������С��k��
��������:
ÿ��������������ո�ָ��n+1�����������һ������Ϊkֵ,n
������100��
�������:
���n����������С��k�������������
ʾ��1
����
����
3 9 6 8 -10 7 -11 19 30 12 23 5
���
����
-11 -10 3 6 7
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <cstdio>
using namespace std;

std::priority_queue<int> getMinkNum(std::vector<int>&nums, int k)
{
	std::priority_queue<int> pq;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (pq.size() < k) //�����
			pq.push(nums[i]);
		else if (pq.top() > nums[i])
		{
			pq.pop();
			pq.push(nums[i]);
		}
	}
	return pq;
}


int main()
{
	vector<int> nums;
	int num;
	while (cin >> num)
		nums.push_back(num);
	int k = nums.back();
	nums.pop_back();
	auto v = getMinkNum(nums, k);
	std::stack<int> s;
	while (!v.empty())
	{
		s.push(v.top());
		v.pop();
	}
	while (s.size() > 1)
	{
		printf("%d ", s.top());
		s.pop();
	}
	printf("%d\n", s.top());

	return 0;
}

