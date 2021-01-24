/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path ="/home/", =>"/home"
path ="/a/./b/../../c/", =>"/c"

click to show corner cases.

Corner Cases:

Did you consider the case where path ="/../"?
In this case, you should return"/".
Another corner case is the path might contain multiple slashes'/'together, such as"/home//foo/".
In this case, you should ignore redundant slashes and return"/home/foo".

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
#include <sstream>
using namespace std;
using namespace yxp_utility;

class Solution
{
public:
	string simplifyPath(string path)
	{
		vector<string> res;
		stringstream ss(path);
		string sub;
		while (getline(ss, sub, '/')) //就是按照/进行分割
		{
			if (sub == "." || sub == "")
				continue;
			else if (sub == "..")
			{
				if (!res.empty())
					res.pop_back();
			}
			else
				res.push_back(sub);
		}
		string result;
		for (string temp : res)
			result += '/' + temp;
		return res.empty() ? "/" : result;
	}
};

int main()
{
	string str = "/home/";
	Solution s;

	assert(s.simplifyPath(str) == "/home");
	assert(s.simplifyPath("/a/./b/../../c/") == "/c");
	assert(s.simplifyPath("/../") == "/");
	assert(s.simplifyPath("/...") == "/...");
	assert(s.simplifyPath("/home//foo/") == "/home/foo");



	return 0;
}