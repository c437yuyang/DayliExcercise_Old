/*
小丽的情书
题目描述
小明想给小丽写情书，但是怕被别人偷看，就想了一个加密的办法:

将信的内容逐字节转成二进制，从高位到低位依次排列。
取6位(bit)为一组，前面补上两个0，形成一个新的字节。
新字节再加上60，形成一个密文字符。
不断重复步骤2、3，直到所有字节都被处理。
若第2步时不足6个bit，则在后边补零凑齐。
现在他需要一个程序来加密自己的信，同时也能帮小丽来解密。

你是暗中观察的小强。小明来找你帮忙了。

输入说明
程序从当前路径下的data.txt中取得测试数据。 
data.txt为多行的ASCII文本文件，长度不超过1K。 
第一行为单个字符: E 表示需要加密，D 表示需要解密。 
第二行起内容是待处理的明文或密文。注意，从第二行起，所有字符（包括换行符等）都属于信件内容

输出说明
直接打印出加密或解密后的字符串。

示例
data.txt文件内容为：

E
hello
预期输出为：

VBQhWBx
data.txt文件内容为：

D
HO@mHO@mHO@mHO@mHO@mHO@mHO@mHO@mHO@mHO@mHO@mHL
预期输出为：

1111111111111111111111111111111111
运行时间限制：1 秒   运行内存限制：128 MB。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <fstream>
class Solution {
public:
	std::string solve(const std::string&str, char op) {
		if (op == 'E') {
			return Encrypt(str);
		} else {
			return Decrypt(str);
		}
	}
private:
	std::string Encrypt(const std::string&str) {
		std::string res;
		std::vector<bool> v;
		for (auto c : str) {
			getBinary(c, v);
		}
		int cnt = v.size() / 6;
		int left = v.size() % 6;
		for (int i = 0; i < cnt; ++i) {
			res.push_back(getPreSixDigit(v, 6 * i) + 60);
		}
		if (left != 0) {
			res.push_back(getLastDigits(v, cnt * 6, left) + 60);
		}
		return res;
	}

	std::string Decrypt(const std::string&str) {
		std::vector<bool> v;
		std::string res;
		for (auto c : str) {
			getBinarySkipTwo(c - 60, v);
		}
		int cnt = v.size() / 8;
		for (int i = 0; i < cnt; ++i) {
			res.push_back(getCharFromBinary(v, 8 * i));
		}
		return res;
	}


	//c的8位二进制添加到v中
	void getBinary(char c, std::vector<bool>&v) {
		for (int i = 0; i < 8; ++i) {
			v.push_back((((int)c) >> (7 - i)) & 1);
		}
	}

	//从start取6位，前面补零
	char getPreSixDigit(std::vector<bool>& v, int start) {
		char c = 0;
		for (int i = 0; i < 6; ++i) {
			c |= ((v[start + i] ? 1 : 0) << (5 - i));
		}
		return c;
	}

	//最后的几位的操作
	char getLastDigits(std::vector<bool>& v, int start, int left) {
		char c = 0;
		int idx = 0;
		for (int i = start; i < v.size(); ++i, ++idx) {
			c |= ((v[i] ? 1 : 0) << (5 - idx));
		}
		return c;
	}

	//取每个字符的后6位
	void getBinarySkipTwo(char c, std::vector<bool>&v) {
		for (int i = 0; i < 6; ++i) {
			v.push_back((((int)c) >> (5 - i)) & 1);
		}
	}

	//从start 取8位
	char getCharFromBinary(std::vector<bool> & v, int start) {
		char c = 0;
		int idx = 0;
		for (int i = start; i < start + 8; ++i, ++idx) {
			c |= ((v[i] ? 1 : 0) << (7 - idx));
		}
		return c;
	}
};

int main(int argc, char **argv) {
	Solution s;
	std::ifstream ifs("data.txt");

	char op;
	ifs >> op;
	ifs.get();
	std::string str;
	std::getline(ifs, str);
	std::cout << s.solve(str, op) << std::endl;

	return 0;
}