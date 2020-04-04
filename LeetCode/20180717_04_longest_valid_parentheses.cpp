/*
Given a string containing just the characters'('and')', find the length of the longest valid (well-formed) parentheses substring.
For"(()", the longest valid parentheses substring is"()", which has length = 2.
Another example is")()())", where the longest valid parentheses substring is"()()", which has length = 4.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <stack>

//自己做的，复杂度太高
class Solution1
{
public:
	int longestValidParentheses(const std::string& str)
	{
		if (str == "")
			return 0;

		int max = 0;

		//每个位置开始的最长
		for (int start = 0; start < str.length(); ++start)
		{
			if (str[start] == ')')
				continue;

			for (int end = str.length() - 1; end >= start; --end) //子串的结尾
			{
				//对当前子串进行校验
				bool isValid = true;
				if (str[end] == '(' || //结束不对
					(end - start + 1) % 2 != 0) //长度不是偶数
				{
					isValid = false;
					continue;
				}

				std::stack<char> stack;
				for (int j = start; j <= end; ++j)
				{
					if (str[j] == '(')
						stack.push(str[j]);
					if (str[j] == ')')
					{
						if (stack.empty() || stack.top() != '(')
						{
							isValid = false;
							break;
						}
						stack.pop();
					}
				}
				if (isValid && stack.empty())
				{
					max = end - start + 1;
					return max;
				}
			}
		}

		return max;
	}
};

//牛客看到的
class Solution
{
public:
	int longestValidParentheses(std::string str)
	{
		int res = 0, last = -1;
		std::stack<int> stack;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(') 
				stack.push(i);
			else
			{
				if (stack.empty())
					last = i;
				else
				{
					stack.pop();
					if (!stack.empty())
						res = std::max(res, i - stack.top());
					else 
						res = std::max(res, i - last);
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	assert(s.longestValidParentheses("(()") == 2);
	assert(s.longestValidParentheses(")(()))") == 4);
	assert(s.longestValidParentheses(")(((((()())()()))()(()))(") == 22);
	assert(s.longestValidParentheses("))))((()((") == 2);

	return 0;
}