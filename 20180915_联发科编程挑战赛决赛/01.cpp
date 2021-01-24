/*
汉诺塔问题
题目描述
有三个柱子A,B,C上面随机套了N个大小不一盘子(N <= 31)，小号盘子依次罗在大号盘子上面, 现需要将所有的盘子都移到C柱上面，在移动的过程当中:

每次只能将一个柱子最上面的盘子放到其它柱子的最上面
且任何时刻不能将大号的盘子压在小号的盘子上面。
输入说明
以命令行参数的形式输入盘子的初始状态，以及移动步数S(S <= 2^31 - 1)。 
在程序中可以从main 函数的参数中获得，示例代码如下:

int main(int argc, char* argv[])
{
     unsigned int print_count;
     char* init_status;
     init_status = argv[1];
     print_count = strtoul(argv[2], NULL, 10);

     ......
     return 0;
}
输出说明
最少需要移动多少步可以完成目标，以及在移动S步后，盘子的当前状态是什么，以逗号隔开。

示例1
输入:

AAA
1
AAA: 表示初始状态有3个盘子 全部放在A柱上面, 1: 表示移动 步数 S = 1 
输出:

7,CAA
表示最少需要7步，能将所有盘子移到C柱上，CAA: 表示移动S=1步后，1号盘子在C柱上，2和3在A柱上

示例2
输入:

BACA
2
BACA表示1号盘 在B柱，2和4号盘在A柱，3号盘在C柱, S = 2

输出:

13,AABA
表示最少需要13步，能将所有盘子移到C柱上，移动S=2步后，1,2,4号盘子在A柱上，3在B柱上

示例3
输入:

BACA
18
表示1号盘 在B柱，2和4号盘在A柱，3号盘在C柱, S = 18 
输出:

13,CCCC
表示最少需要13步，能将所有盘子移到C柱上，13步就已经完成目标，之后会一直维持CCCC状态

运行时间限制：10 秒   运行内存限制：128 MB。
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <functional>
using namespace std;




int cnt = 0;
std::string res(31, '\0');


static void func(int rest, int down, const std::string& from, const std::string& help, const std::string& to, int S,
	std::map<std::string, std::stack<int>> &mp) {
	if (rest == 1) {
		++cnt;
		int tmp = mp[from].top();
		mp[from].pop();
		mp[to].push(tmp);
		if (cnt == S) {
			for (auto it : mp) {
				std::stack<int> tmpStack = it.second;
				while (!tmpStack.empty()) {
					res[tmpStack.top() - 1] = it.first[0];
					tmpStack.pop();
				}
			}
		}
	} else {
		func(rest - 1, down - 1, from, to, help, S, mp); //先把rest-1个从from搬到help,用to当中转
		func(1, down, from, help, to, S, mp); //再把最后一个从from搬到to
		func(rest - 1, down - 1, help, from, to, S, mp); //再把rest-1个从help搬回来到to中，用from作中转
	}
}


static void hanoi(int S, const std::string& initState) {
	cnt = 0;
	res = std::string(31, '\0');
	std::map<std::string, std::stack<int>> mp;
	std::map<std::string, std::set<int, std::greater<int>>> tmpMap;

	for (int i = 0; i < initState.size(); ++i) {
		tmpMap[std::string(1, 'A')].insert(i + 1);
	}
	for (auto it : tmpMap) {
		for (auto i : it.second) {
			mp[it.first].push(i);
		}
	}
	int n = initState.length();
	func(n, n, "A", "B", "C", S, mp);
	cout << cnt << "," << res;
}



int main(int argc, char **argv) {
	int S = stoi(argv[2]);
	hanoi(S, argv[1]);
	return 0;
}