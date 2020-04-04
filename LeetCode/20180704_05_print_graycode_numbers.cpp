/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return[0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example,[0,2,3,1]is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.


*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;

/*
链接：https://www.nowcoder.com/questionTerminal/55dddb4cdf074fefba653ff523e42346
来源：牛客网

当n=1时，为[0,1]
当n=2时，为[00,01,11,10]
当n=3时，为[000,001,011,010,110,111,101,100]
由此可以看出新的序列其实是在前面序列基础上插入新的值
其中前半部分的数值不变，后半部分的数值为上个序列中每个元素第n个位变1，逆向插入
*/

class Solution {
public:
	std::vector<int> grayCode(int n) {
		std::vector<int> res((int)pow(2, n), 0);
		res[0] = 0;
		res[1] = 1;
		int appendix[4] = { 0, 1, 1, 0 };
		for (int i = 2; i <= n; ++i) //每一层一层的来
		{
			int j = (int)pow(2, i) - 1;
			for (; j >= 0; --j)
				res[j] = (res[j / 2] << 1) + appendix[j % 4];
		}
		return res;
	}

	//leetcode题解:格雷码有数学公式，整数 n 的格雷码是 n ^ (n/2)
	std::vector<int> grayCode1(int n) {
		std::vector<int> result;
		const size_t size = 1 << n; // 2^n
		result.reserve(size);
		for (size_t i = 0; i < size; ++i)
			result.push_back(binary_to_gray(i));
		return result;
	}
private:
	static unsigned int binary_to_gray(unsigned int n) {
		return n ^ (n >> 1);
	}

};



int main() {
	Solution s;

	auto v = s.grayCode(2);
	ArrayHelper::printArr(v);

	v = s.grayCode(3);
	ArrayHelper::printArr(v);

	v = s.grayCode1(3);
	ArrayHelper::printArr(v);

	return 0;
}