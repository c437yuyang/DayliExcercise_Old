/*
 两端对齐
题目描述
请你实现一下Word排版中的“两端对齐”效果。 
给定一个宽度 maxWidth，表示每行能容纳的字符上限。再给你一个句子，请你来重新排版， 使其符合“两端对齐”的格式要求。 
所谓两端对齐，是指段落的每行（除末行外）恰好有 maxWidth 个字符，且文本均匀分布，左右两端对齐。

要求
输出中的空格请全部使用下划线 '_' 代替。
除末行外，每行都应该以单词开头，以单词结尾。
单词不能跨行（即不能拆分单词）。
适当的填充下划线，使每行恰好有 maxWidth 个字符。
每行必须尽量容纳尽可能多的单词。
文本的最后一行为左对齐，不能填充额外的下划线。
尽可能均匀分配单词间的下划线数量。如果某一行的下划线确定不能均匀分配，则可以在左侧放置多于右侧的空格数。（请参考下文说明）
关于"均匀分布"，举如下的例子：

a___b__c__d 正确
a__b__c___d 不正确
a__b___c__d 不正确
a_b___c___d 不正确
a___b___c_d 不正确
a__b__c__d_ 不正确
_a__b__c__d 不正确
输入说明
程序从当前路径下的data.txt文件中读取测试数据， 有两行。 
第一行只有一个正整数，表示 maxWidth值，不超过128。 
第二行保存一个长句子，长度不超过1MB。句子中单词与单词之间以空格隔开

输出说明
输出格式化后的文本信息 
特别提醒：输出中的空格请全部使用下划线代替。

示例
输入：

16
This is an example of text justification
输出：

This____is____an
example__of_text
justification
运行时间限制：1 秒   运行内存限制：128 MB。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <fstream>
#include <cassert>
using namespace std;
// 时间复杂度 O(n)，空间复杂度 O(1)
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		const int n = words.size();
		int begin = 0, len = 0; // 当前行的起点，当前长度
		for (int i = 0; i < n; ++i) {
			if (len + words[i].size() + (i - begin) > L) {
				result.push_back(connect(words, begin, i - 1, len, L, false));
				begin = i;
				len = 0;
			}
			len += words[i].size();
		}
		// 最后一行不足 L
		result.push_back(connect(words, begin, n - 1, len, L, true));
		return result;
	}
	
	string connect(vector<string> &words, int begin, int end,
		int len, int L, bool is_last) {
		string s;
		int n = end - begin + 1;
		for (int i = 0; i < n; ++i) {
			s += words[begin + i];
			addUnderLines(s, i, n - 1, L - len, is_last);
		}
		if (s.size() < L) s.append(L - s.size(), ' ');
		return s;
	}
	
	void addUnderLines(string &s, int i, int n, int L, bool is_last) {
		if (n < 1 || i > n - 1) return;
		int spaces = is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
		s.append(spaces, '_');
	}
};

int main(int argc, char **argv) {
	std::ifstream ifs("data.txt");
	int len;
	ifs >> len;
	std::vector<std::string> words;
	std::string str;
	while (ifs >> str) {
		words.push_back(str);
	}

	Solution s;
	auto res = s.fullJustify(words, len);
	for (int i = 0; i < res.size(); ++i) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}