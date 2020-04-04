
/*
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
��������:
ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50����
��������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��
�������:
���һ�б�ʾ���ĳ˻���
ʾ��1
����
����
3
7 4 7
2 50
���
����
49
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

//dfs�汾��AC 80%
void dfs(vector<int > &capacitys, int  curPos, int  k, int  maxDist, long long  &res, long long  curRes);
long long  solve(vector<int > &capacitys, int  k, long long  maxDist)
{
	long long  res = std::numeric_limits<long long >::min();
	long long  curRes = 1;

	for (long long i = 0; i < capacitys.size(); ++i)
	{
		dfs(capacitys, i, k, maxDist, res, curRes);
	}
	return res;
}

void dfs(vector<int > &capacitys, int  curPos, int  k, int  maxDist, long long  &res, long long  curRes)
{
	if (k == 0)
	{
		if (curRes > res)
			res = curRes;
		return;
	}

	if (curPos >= capacitys.size())
		return;
	curRes *= capacitys[curPos];
	for (int i = curPos + 1; i <= curPos + maxDist; ++i)
	{
		dfs(capacitys, i, k - 1, maxDist, res, curRes);
	}
}

int solve1(vector<int> a, int k, int d)
{
	int n = a.size();
	vector<vector<long long>> dp_max(n, vector<long long>(k + 1, std::numeric_limits<long long>::min()));
	vector<vector<long long>> dp_min(n, vector<long long>(k + 1, std::numeric_limits<long long>::max()));
	for (int i = 0; i < n; i++)
	{
		dp_max[i][1] = a[i];
		dp_min[i][1] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			for (int m = max(0, i - d); m <= i - 1; m++)
			{
				dp_max[i][j] = std::max(dp_max[i][j], std::max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i])); //����֮���Ի������dp_max[i][j]�Ƚϣ���Ϊ�����ǹ̶���i,j��Ȼ����d�ķ�Χ�ڿ��ܳ��ֵ�����������һ������Ŀ϶��ļ��°�
				dp_min[i][j] = std::min(dp_min[i][j], std::min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
			}
		}
	}
	long long max_value = dp_max[k - 1][k];
	for (int i = k; i < n; i++)
	{
		max_value = max(max_value, dp_max[i][k]);
	}
	return max_value;
}


int main()
{
	std::vector<int> capacities = { 7,4,7,8,9 };
	int res = solve(capacities, 2, 50);
	//assert(res == 72);

	capacities = { 7,4,7 };
	res = solve1(capacities, 2, 50);
	assert(res == 49);

	capacities = { 7,4,7,1,1,1,1,1,1,1,1,1,8 };
	res = solve(capacities, 2, 5);
	assert(res == 49);


	/*long long  n;
	cin >> n;
	std::vector<long long > capacities(n);
	for (long long  i=0;i<n;++i)
	{
		cin >> capacities[i];
	}

	long long  k, d;
	cin >> k >> d;

	cout << solve(capacities, k, d) << endl;*/


	return 0;
}