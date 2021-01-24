/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama"is a palindrome.
"race a car"is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>


class Solution
{
public:
	//复制一遍
	bool isPalindrome1(string s)
	{
		if (s == "")
			return true;
		std::string strCopy;
		for (size_t i = 0; i < s.length(); ++i)
		{
			if (isalnum(s[i]))
				strCopy += tolower(s[i]);
		}
		return std::string(strCopy.rbegin(), strCopy.rend()) == strCopy;
	}

	//牛客看到的更好的
	bool isPalindrome(std::string& s)
	{
		int i, j;
		for (i = 0, j = s.length() - 1; i < j; ++i, --j)
		{
			while (i < j && !isalnum(s[i])) ++i;
			while (i < j && !isalnum(s[j])) --j;
			if (i < j && tolower(s[i]) != tolower(s[j])) return false;
		}
		return true;
	}
};
int main()
{

	//"A man, a plan, a canal: Panama" true
	//"race a car" false

	return 0;
}