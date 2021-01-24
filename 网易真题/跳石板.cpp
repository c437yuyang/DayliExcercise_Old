/*

С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
��������:
����Ϊһ�У�����������N��M���Կո������ (4 �� N �� 100000) (N �� M �� 100000)
�������:
���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1
ʾ��1
����
����
4 24
���
����
5
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
void dfs(int src, int dst, int curRes, int &res);

int solve(int src, int dst)
{
	int res = std::numeric_limits<int>::max();
	dfs(src, dst, 0, res);
	return res == std::numeric_limits<int>::max() ? -1 : res;
}

vector<int> getFactors(int num);

//dfsֻ�ܹ�60%,��ʱ
void dfs(int src, int dst, int curRes, int &res)
{
	if (dst == src)
	{
		res = std::min(res, curRes);
		return;
	}

	if (src > dst)
		return;

	if (curRes == res)
	{
		return;
	}

	//for (int i = src - 1; i >= 2; --i) //�Ӵ�Сѭ�������ã�30%->60%
	//for (int i = src / 2; i >= 2; --i) //Լ��һ���Ǵӳ�2��ʼ��
	//{
	//	if (src % i == 0 && src + i <= dst) //���Ƽ���<=dst
	//		dfs(src + i, dst, curRes + 1, res);
	//}

	//��������������

	auto factors = getFactors(src);
	for (int i = 0; i < factors.size(); ++i)
	{
		dfs(src + factors[i], dst, curRes + 1, res);
	}

}

//��̬�滮
int solveDp(int src, int dst)
{
	std::vector<int> dp(dst + 1, std::numeric_limits<int>::max());
	dp[dst] = 0;

	for (int curPos = dst - 1; curPos >= src; --curPos)
	{
		auto factors = getFactors(curPos);
		for (int j = 0; j < factors.size(); ++j)
		{
			if (curPos + factors[j] <= dst &&
				dp[curPos + factors[j]] != std::numeric_limits<int>::max())
			{
				dp[curPos] = std::min(dp[curPos], dp[curPos + factors[j]] + 1);
			}
		}
	}

	return dp[src] == std::numeric_limits<int>::max() ? -1 : dp[src];
}

vector<int> getFactors(int num) //�������������󣬲��ܹ������ܴӳ���2��ʼ��
{
	vector<int> res;
	//��Լ��
	for (int i = sqrt(num); i >= 2; --i)
	{
		if (num % i == 0)
		{
			res.push_back(i);
			if (num / i != i)
				res.push_back(num / i);
		}
	}
	return res;
}


int main()
{
	/*int src, dst;
	cin >> src >> dst;

	cout << solveDp(src, dst) << endl;*/
	//cout << sovleDp(4, 24) << endl;

	cout << solveDp(4, 24) << endl;
	cout << solveDp(8, 85678) << endl;
	//cout << solve(8, 85678) << endl; //dfs�����������������




	return 0;
}