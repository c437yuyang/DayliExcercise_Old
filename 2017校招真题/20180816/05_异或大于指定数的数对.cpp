/*
给定整数m以及n各数字A1,A2,..An，将数列A中所有元素两两异或，共能得到n(n-1)/2个结果，请求出这些结果中大于m的有多少个。
输入描述:
第一行包含两个整数n,m.

第二行给出n个整数A1，A2，...，An。

数据范围

对于30%的数据，1 <= n, m <= 1000

对于100%的数据，1 <= n, m, Ai <= 10^5
输出描述:
输出仅包括一行，即所求的答案
示例1
输入
复制
3 10
6 5 10
输出
复制
2
*/
#include<iostream>
#include<vector>

using namespace std;

class query_tree
{
public:
	query_tree *next[2]{ NULL,NULL };
	int count;
	query_tree() :count(1) {}//count要初始化为1
};

query_tree root;
void build_tree(int m)
{
	query_tree *cur = &root;
	for (int j = 16; j >= 0; j--)
	{
		bool flag = m >> j & 1;
		if (!cur->next[flag])
			cur->next[flag] = new query_tree;
		else
			cur->next[flag]->count++;
		cur = cur->next[flag];
	}
}

long long query_num(int num, int cmp, query_tree *root, int index)
{
	if (index < 0)
		return 0;
	int num_i = num >> index & 1;
	int cmp_i = cmp >> index & 1;
	if (num_i == 1 && cmp_i == 1)
	{
		return root->next[0] ? query_num(num, cmp, root->next[0], index - 1) : 0;//如果0是null,只能走1，1^1=0，小于cmpdigit，直接返回0,否则走0，走0^1=1 等于cmpdigit，继续下一步
	}
	else if (num_i == 1 && cmp_i == 0)
	{
		long long val1 = root->next[0] ? root->next[0]->count : 0; //cmp是0，走0走1都试试，1^0=1,则直接返回
		long long val2 = root->next[1] ? query_num(num, cmp, root->next[1], index - 1) : 0; //1^1=0,继续比较下一位
		return val1 + val2;
	}
	else if (num_i == 0 && cmp_i == 1)
	{
		return root->next[1] ? query_num(num, cmp, root->next[1], index - 1) : 0;//如果1是null,只能走0，0^0=0,小于cmpdigit,直接返回0, 走1，继续下一步
	}
	else
	{
		long long val1 = root->next[1] ? root->next[1]->count : 0;
		long long val2 = root->next[0] ? query_num(num, cmp, root->next[0], index - 1) : 0;
		return val1 + val2;
	}
}
int main()
{
	int n, cmp;
	cin >> n >> cmp;
	vector<int> vi(n);
	long long count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> vi[i];
		build_tree(vi[i]);
	}
	for (int i = 0; i < n; i++)
		count += query_num(vi[i], cmp, &root, 16);
	cout << count / 2;
	return 0;
}