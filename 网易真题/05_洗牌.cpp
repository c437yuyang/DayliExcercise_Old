/*
洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
输入描述:
第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n,k(1 ≤ n,k ≤ 100)，接下来一行有2n个数a1,a2,...,a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。
输出描述:
对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。
示例1
输入
复制
3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1
输出
复制
1 4 2 5 3 6 1 5 4 3 2 6 1 1 1 1
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//我自己做的，直接是错的，不知道为什么，暴力方法应该是对的
std::string solve(std::vector<long long>&nums, int k)
{
	if (nums.size() == 2)
	{
		std::string res;
		for (int i = 0; i < nums.size(); ++i)
		{
			res += nums[i] + " ";
		}
		return res;
	}


	for (int time = 0; time < k; ++time)
	{
		std::vector<long long> tmp(nums.size());

		int idx = 0;
		for (int i = 0; i < nums.size(); i += 2)
		{
			tmp[i] = nums[idx++];
		}

		for (int i = 1; i < nums.size(); i += 2)
		{
			tmp[i] = nums[idx++];
		}
		nums = tmp;
	}
	std::string res;
	for (int i = 0; i < nums.size(); ++i)
	{
		res += to_string(nums[i]) + " ";
	}
	return res;
}

//牛客看到的 思路就是:
/**
 * 每次读取一个数之后，算出他经过k次洗牌后的位置，只用一个长度为2n数组用来输出
 * 根据当前数的位置，可以算出经过一次洗牌后的位置
 * 如果当前数小于等于n（即在左手），则他下次出现的位置是 2*当前位置-1
 * 如果当前位置大于n（即在右手）,则他下次出现的位置是 2*（当前位置 - n）
 * 个人建议在线面试题的时候如果5分钟内没想到好方法建议就使用暴力方法，
 * 毕竟测试用例不通过什么都没用
 * Created by lizo on 2016/8/20.
 */
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; ++i)
			cin >> table[i];
		while (k--)
		{
			vector<int> n1(table.begin(), table.end());
			for (int i = 0; i < n; ++i)
			{
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[i + n];
			}
		}
		for (int i = 0; i < num - 1; ++i)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
	return 0;
}

int main()
{
	int cnt;
	cin >> cnt;
	std::string res;
	while (cnt--)
	{
		int n, k;
		cin >> n >> k;
		std::vector<long long> nums(n * 2);
		for (int i = 0; i < n * 2; ++i)
		{
			cin >> nums[i];
		}
		res += solve(nums, k);
	}

	res.pop_back();
	cout << res << endl;

	return 0;
}