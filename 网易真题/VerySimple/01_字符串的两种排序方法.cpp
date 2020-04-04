/*
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
输入描述:
输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",

如果根据长度排列而不是字典序排列输出"lengths",

如果两种方式都符合输出"both"，否则输出"none"
示例1
输入
复制
3
a
aa
bbb
输出
复制
both
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve(std::vector<std::string>&words)
{
	if (words.size() <= 1)
	{
		cout << "both" << endl;
		return;
	}


	bool islexicographically = true;
	bool isLengthSort = true;

	std::vector<int> lenArr(words.size());
	for (int i = 1; i < words.size(); ++i)
	{
		if (words[i - 1].length() >= words[i].length())
		{
			isLengthSort = false;
			break;
		}
	}

	for (int i = 1; i < words.size(); ++i)
	{
		if (words[i - 1] >= words[i])
		{
			islexicographically = false;
			break;
		}
	}

	if (islexicographically && isLengthSort)
	{
		cout << "both" << endl;
	}
	else if (islexicographically)
	{
		cout << "lexicographically" << endl;
	}
	else if (isLengthSort)
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i=0;i<n;++i)
	{
		cin >> words[i];
	}


	/*vector<string> words = { "a","aa","aaa" };*/
	solve(words);

	return 0;
}