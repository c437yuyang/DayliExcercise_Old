/*
Ϊ���ҵ��Լ�����Ĺ�����ţţ�ռ���ÿ�ֹ������ѶȺͱ��ꡣţţѡ�����ı�׼�����ѶȲ�������������ֵ������£�ţţѡ�񱨳���ߵĹ�������ţţѡ�����Լ��Ĺ�����ţţ��С���������ţţ��æѡ������ţţ��Ȼʹ���Լ��ı�׼������С����ǡ�ţţ��С���̫���ˣ�������ֻ�ð�������񽻸����㡣
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а����������������ֱ��ʾ����������N(N<=100000)��С��������M(M<=100000)��
��������N��ÿ�а����������������ֱ��ʾ��������Ѷ�Di(Di<=1000000000)�ͱ���Pi(Pi<=1000000000)��
��������һ�а���M�����������ֱ��ʾM��С��������ֵAi(Ai<=1000000000)��
��֤������������ı�����ͬ��


�������:
����ÿ��С��飬�ڵ�����һ�����һ����������ʾ���ܵõ�����߱��ꡣһ���������Ա������ѡ��

��������1:
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

�������1:
100
1000
1001
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
//����ⲻ�ý����ṹ��ʵ��ֱ����map<int,int>����ֱ����
struct Job
{
	int diff;
	int pay;
};
void solve(std::vector<int>& buddies, std::vector<Job> &jobs)
{
	auto cmp = [](const Job&j1, const Job&j2) { return j1.diff < j2.diff; };
	std::sort(jobs.begin(), jobs.end(), cmp); //���չ����Ѷ�����
	int max = jobs[0].pay;
	for (int i = 1; i < jobs.size(); ++i) //�ؼ���:�������飬���º�ÿ��λ�ü�Ϊ��ǰdi���������
	{
		if (jobs[i].pay > max)
			max = jobs[i].pay;
		else jobs[i].pay = max; //����С��maxpay�϶�����
	}
	for (int i = 0; i < buddies.size(); ++i)
	{
		int curMaxPay = std::numeric_limits<int>::min();
		auto pos = std::upper_bound(jobs.begin(), jobs.end(), Job{ buddies[i], 0 }, cmp) - jobs.begin();
		std::cout << jobs[pos - 1].pay << std::endl;
	}
}



int main()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<int> buddies(M);
	std::vector<Job> jobs(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> jobs[i].diff;
		std::cin >> jobs[i].pay;
	}

	for (int i = 0; i < M; ++i)
		std::cin >> buddies[i];

	solve(buddies, jobs);

	return 0;
}