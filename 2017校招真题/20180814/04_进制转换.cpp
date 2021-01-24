/*
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1
输入
复制
7 2
输出
复制
111
*/

//注意点:
//负数的情况

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <deque>
using namespace std;

char table[] = { 'A','B','C','D','E','F' };


void convertdecimal(int n, int k)
{
	if (n == 0)
	{
		cout << 0 << endl;
		return;
	}
	std::deque<char> res;
	if (n < 0)
	{
		cout << "-";
		n = -n;
	}
	while (n > 0)
	{
		int cur = n%k;
		if (cur >= 10)
			res.push_front(table[cur - 10]);
		else res.push_front('0' + cur);
		n /= k;
	}

	for (auto i : res)
	{
		cout << i;
	}
	cout << endl;

}


int main()
{
	int n;
	int k;
	cin >> n >> k;
	convertdecimal(n, k);

	return 0;
}

