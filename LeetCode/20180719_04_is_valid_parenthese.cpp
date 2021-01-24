/*
Given a string containing just the characters'(',')','{','}','['and']', determine if the input string is valid.

The brackets must close in the correct order,"()"and"()[]{}"are all valid but"(]"and"([)]"are not.


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <stack>
class Solution
{
public:
	bool isValid(std::string s)
	{
		if (s.empty())
			return true;
		if (s.size() % 2 != 0)
			return false;

		std::stack<char> stack;
		int idx = 0;
		while (idx < s.length())
		{
			if (s[idx] == ')')
			{
				if (stack.top() != '(')
					return false;
				stack.pop();
			}
			else if (s[idx] == ']')
			{
				if (stack.top() != '[')
					return false;
				stack.pop();
			}
			else if (s[idx] == '}')
			{
				if (stack.top() != '{')
					return false;
				stack.pop();
			}
			else
				stack.push(s[idx]);
			++idx;
		}
		return stack.empty() ? true : false;
	}
};
int main()
{
	Solution s;
	std::string str = "()[]{}";

	bool res = s.isValid(str);


	return 0;
}