/*
题目描述
假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
输入描述:
输入一个待编码的字符串,字符串长度小于等于100.
输出描述:
输出这个编码的index
示例1
输入
baca
输出
16331
*/
#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
using namespace std;


/*


第一大块包含多少个呢？如果长度是4，说明都不包含空（x）第一位已经确定，就是a还有三位可选（选25个字母之一），就是25*25*25，长度是3说明有一个空，25*25,长度为2，两个空只剩一个位置可以是25个字母中任意一个，25，长度是1，那就只有a自己了。所以一共是  25^3+25^2+25+1
--------
例：bcd
第一位是b所以处在第二大块，result += 1 *  (25^3+25^2+25+1) 
第二位是c， result += 2 *（25^2+25+1）+1
第三位是d， result += 3* （25+1）+1  （加一是因为最前面有个空）
第四位是空，不管，因为空就是第一个
result = 17658
--------
例：defc
第一位是d所以处在第四大块，result += 3 *  (25^3+25^2+25+1) 
第二位是e， result += 4 *（25^2+25+1）+1
第三位是 f， result += 5* （25+1）+1
第四位是c， result += 2* （1）+1
result = 51567
*/

int calcDigit(char c, int digit)
{
	if (c - 'a' > 0)
	{
		int res = 0;
		for (int i = digit; i >= 0; --i)
			res += pow(25, i);
		return res * (c - 'a');
	}
	else
		return 0;
}

int solve(std::string&str)
{
	int res = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		res += calcDigit(str[i], 4 - 1 - i);
		if (i != 0)
			res += 1; //第一位不会+1，因为a就是0下标，但是ba的话，要经过b ba,因此要加一
	}
	return res;
}


int main()
{
	std::string str;
	cin >> str;
	cout << solve(str) << endl;
	return 0;
}