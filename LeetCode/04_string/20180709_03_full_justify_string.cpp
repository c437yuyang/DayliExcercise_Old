/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces' 'when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words:["This", "is", "an", "example", "of", "text", "justification."]
L:16.

Return the formatted lines as:

[
"This    is    an",
"example  of text",
"justification.  "
]

Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:

A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

//测试用例可能有问题，这个题没多大意思，就是按要求coding
//我这个做法不知道对不对，有个测试用例是错的，OJ卡在那里了
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

class Solution
{

public:
	vector<string> fullJustify(vector<string> &words, int L)
	{
		std::vector<std::vector<string>> groups;
		std::vector<std::string> res;
		int curLen;
		for (size_t i = 0; i < words.size() - 1;)
		{
			std::vector<std::string> curGroup;
			curLen = 0;

			while (i < words.size() - 1)
			{
				if (curGroup.size() == 0)
				{
					curGroup.push_back(words[i]);
					curLen += words[i].length();
				}
				else
				{
					if (curLen + words[i].length() + 1 <= L)
					{
						curGroup.push_back(words[i]);
						curLen += words[i].length() + 1;
						if (curLen == L)
						{
							groups.push_back(curGroup);
							curGroup.clear();
							++i;
							break;
						}
					}
					else
					{
						groups.push_back(curGroup);
						curGroup.clear();
						break;
					}
				}
				++i; //长度大于了L的时候break了下次就会继续考察这一个word
			}
			if (!curGroup.empty())
				groups.push_back(curGroup);
		}
		groups.push_back(std::vector<std::string>{words.back()}); //最后一个词单独成一组

		//进行结算
		for (size_t i = 0; i < groups.size() - 1; ++i)
		{
			if (groups[i].size() == 1)
			{
				res.push_back(groups[i][0]);
				continue;
			}
			size_t groupLen = 0;
			std::for_each(groups[i].begin(), groups[i].end(),
				[&groupLen](const std::string &cur) { groupLen += cur.length(); });
			groupLen += groups[i].size() - 1;

			size_t slots = L - groupLen;
			size_t avgSlots = slots / (groups[i].size() - 1);
			size_t bigSlots = avgSlots + slots % (groups[i].size() - 1);
			std::string curRes = groups[i].front() + std::string(bigSlots + 1, ' ');
			std::for_each(groups[i].begin() + 1, groups[i].end() - 1,
				[&curRes, &avgSlots](const std::string &cur) { curRes += cur + std::string(avgSlots + 1, ' '); });
			curRes += groups[i].back();
			res.push_back(curRes);
		}
		//最后一组单独结算
		std::string last = groups.back()[0] + std::string(L - groups.back()[0].length(), ' ');
		res.push_back(last);

		return res;
	}
};


int main()
{
	std::vector<std::string> words = { "This", "is", "an", "example", "of", "text","justification." };

	Solution s;
	s.fullJustify(words, 16);

	words = { "a","b","c","d","e" };
	s.fullJustify(words, 1);

	words = { "a","b","c","d","e" };
	s.fullJustify(words, 3);


	return 0;
}