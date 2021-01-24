#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

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
示例1
输入
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000
输出
100
1000
1001
*/

//牛客看到的，其实真的贼简单
int main()
{
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n; cin >> n;
		int j = 0, count = 0;
		while (j++ < n)
		{
			char ch; cin >> ch;
			if (ch == '.') //说白了就是遇到.就可以cnt+1然后跳过三个字符，'X'就下一个字符
			{
				count++;
				if (j++ < n) cin >> ch;
				if (j++ < n) cin >> ch;
			}
		}
		cout << count << endl;
	}
	return 0;
}


////我的，有错
//int getMinLambCount(string str)
//{
//	if (str.length() == 0)
//		return 0;
//	//if (str.length() <= 3)
//	//	return 1;
//	int cnt = 0;
//
//
//	int pos = str.find("...");
//	while (pos != std::string::npos)
//	{
//		str = str.replace(str.begin() + pos, str.begin() + pos + 3, "");
//		pos = str.find("...");
//		++cnt;
//	}
//	pos = str.find("..");
//	while (pos != std::string::npos)
//	{
//		//检查左右是否还有可以带着一起替换的
//
//		str = str.replace(str.begin() + pos, str.begin() + pos + 2, "");
//		pos = str.find("..");
//		++cnt;
//	}
//
//	pos = str.find(".");
//	while (pos != std::string::npos)
//	{
//		//考虑.X. 这种,检查左右是否还有.存在，可以一起替换
//		if (pos + 2 < str.length() && str[pos + 2] == '.')
//			str = str.replace(str.begin() + pos, str.begin() + pos + 3, "");
//
//		else
//			str = str.replace(str.begin() + pos, str.begin() + pos + 1, "");
//		pos = str.find(".");
//		++cnt;
//	}
//	return cnt;
//}
//
//
//int main()
//{
//	int cnt;
//	std::cin >> cnt;
//	while (cnt--) 
//	{
//		int len;
//		std::cin >> len;
//		string str;
//		while (len--) 
//		{
//			char c;
//			cin >> c;
//			str += c;
//		}
//		int res = getMinLambCount(str);
//		cout << res << endl;
//	}
//
//	//int res = getMinLambCount("...XX....XX");
//	//res = getMinLambCount(".X.");
//
//	return 0;
//}