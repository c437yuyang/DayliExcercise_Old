/*
????B???????A????????????
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
bool isPanlidrome(const std::string&str);
int solve(std::string &str1, const std::string&str2)
{
	int res = 0;
	for (int i=0;i<=str1.length();++i)
	{
		std::string tmp = str1;
		tmp = tmp.insert(i, str2); //?? temp=A.substr(0,i)+B+A.substr(i);
		if (isPanlidrome(tmp))
			++res;
	}
	return res;

}

bool isPanlidrome(const std::string&str)
{
	return std::string(str.rbegin(), str.rend()) == str;
}

int main()
{
	std::string str1, str2;
	cin >> str1 >> str2;
	cout << solve(str1, str2) << endl;

	return 0;
}