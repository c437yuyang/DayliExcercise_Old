/*
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。


输出描述:
对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

输入例子1:
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

输出例子1:
100
1000
1001
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
//这道题不用建立结构其实，直接用map<int,int>来简直完美
struct Job
{
	int diff;
	int pay;
};
void solve(std::vector<int>& buddies, std::vector<Job> &jobs)
{
	auto cmp = [](const Job&j1, const Job&j2) { return j1.diff < j2.diff; };
	std::sort(jobs.begin(), jobs.end(), cmp); //按照工作难度排序
	int max = jobs[0].pay;
	for (int i = 1; i < jobs.size(); ++i) //关键点:更新数组，更新后，每个位置即为当前di的最大收益
	{
		if (jobs[i].pay > max)
			max = jobs[i].pay;
		else jobs[i].pay = max; //比它小的maxpay肯定能做
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