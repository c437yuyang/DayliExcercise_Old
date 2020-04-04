/*
有很多条组件相互依赖，相互依赖的组件形成链路，
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

void solve1(std::vector<int>& times, std::unordered_multimap<int, int> &depends)
{
	std::map<int, int> res;
	std::map<int, int> resLen;

	std::unordered_multimap<int, int> depends_r;
	for (auto it = depends.begin(); it != depends.end(); ++it)
		depends_r.insert({ it->second, it->first });

	//第一步，找到所有链路
	std::vector<std::vector<int>> links;
	for (auto it = depends.begin(); it != depends.end(); ++it)
	{
		//没有人依赖它，就可以作为开始
		if (depends_r.find(it->first) == depends_r.end())
		{
			std::vector<int> link;
			link.push_back(it->first);
			link.push_back(it->second);
			int curNext = it->second;
			while (depends.find(curNext) != depends.end())
			{
				auto findNext = depends.find(curNext);
				link.push_back(findNext->second);
				curNext = findNext->second;
			}
			links.push_back(link);
		}
	}

	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < links.size(); ++i)
	{
		int cur = 0;
		for (int j = 0; j < links[i].size(); ++j)
			cur += times[links[i][j] - 1];
		max = std::max(cur, max);
	}
	std::cout << links.size() << " " << max << std::endl;
}




int main()
{
	int timeCnt, dependCnt;
	cin >> timeCnt >> dependCnt;
	std::vector<int> times(timeCnt);
	std::unordered_multimap<int, int> depends;

	for (int i = 0; i < timeCnt; ++i)
		cin >> times[i];

	for (int i = 0; i < dependCnt; ++i)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		depends.insert({ tmp1,tmp2 });
	}

	solve1(times, depends);

	return 0;
}