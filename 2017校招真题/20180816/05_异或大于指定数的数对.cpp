/*
��������m�Լ�n������A1,A2,..An��������A������Ԫ��������򣬹��ܵõ�n(n-1)/2��������������Щ����д���m���ж��ٸ���
��������:
��һ�а�����������n,m.

�ڶ��и���n������A1��A2��...��An��

���ݷ�Χ

����30%�����ݣ�1 <= n, m <= 1000

����100%�����ݣ�1 <= n, m, Ai <= 10^5
�������:
���������һ�У�������Ĵ�
ʾ��1
����
����
3 10
6 5 10
���
����
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
	query_tree() :count(1) {}//countҪ��ʼ��Ϊ1
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
		return root->next[0] ? query_num(num, cmp, root->next[0], index - 1) : 0;//���0��null,ֻ����1��1^1=0��С��cmpdigit��ֱ�ӷ���0,������0����0^1=1 ����cmpdigit��������һ��
	}
	else if (num_i == 1 && cmp_i == 0)
	{
		long long val1 = root->next[0] ? root->next[0]->count : 0; //cmp��0����0��1�����ԣ�1^0=1,��ֱ�ӷ���
		long long val2 = root->next[1] ? query_num(num, cmp, root->next[1], index - 1) : 0; //1^1=0,�����Ƚ���һλ
		return val1 + val2;
	}
	else if (num_i == 0 && cmp_i == 1)
	{
		return root->next[1] ? query_num(num, cmp, root->next[1], index - 1) : 0;//���1��null,ֻ����0��0^0=0,С��cmpdigit,ֱ�ӷ���0, ��1��������һ��
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