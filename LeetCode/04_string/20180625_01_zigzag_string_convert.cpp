/*

The string"PAYPALISHIRING"is written in a zigzag pattern on a given number of rows like this:
 (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line:"PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3)should return"PAHNAPLSIIGYIR".

*/

/*
注意把字母转换成数字就好看了
0       6		12
1    5  7	 11
2  4	8  10
3		9
*/
//周期是nRows*2-2

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;
//因为输入不是矩阵的，因此不好按照zigzag matrix那样左上角右下角来解。
//但是可以转化成那样来解6
class Solution
{
public:
	string convert(string s, int nRows)
	{
		if (nRows <= 1) return s;
		int t = nRows + nRows - 2; //求出循环周期
		string res = "";
		vector<string> m(nRows, res);
		for (int i = 0; i < s.length(); i++)
		{
			int a = i % t;
			if (a < nRows)//往下走
				m[a] += s[i];
			else//往上走
				m[t - a] += s[i];
		}
		for (int i = 0; i < nRows; i++)
			res += m[i];//合并
		return res;
	}
};


int main()
{
	string str = "PAHNAPLSIIGYIR";
	Solution s;
	cout << s.convert(str, 3) << endl;
	cout << s.convert(str, 4) << endl;

	return 0;
}