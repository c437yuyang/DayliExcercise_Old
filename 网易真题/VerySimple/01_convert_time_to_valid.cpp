/*
小W有一个电子时钟用于显示时间，显示的格式为HH:MM:SS，HH，MM，SS分别表示时，分，秒。其中时的范围为[‘00’,‘01’…‘23’]，分的范围为[‘00’,‘01’…‘59’]，秒的范围为[‘00’,‘01’…‘59’]。

但是有一天小W发现钟表似乎坏了，显示了一个不可能存在的时间“98:23:00”，小W希望改变最少的数字，使得电子时钟显示的时间为一个真实存在的时间，譬如“98:23:00”通过修改第一个’9’为’1’，即可成为一个真实存在的时间“18:23:00”。修改的方法可能有很多，小W想知道，在满足改变最少的数字的前提下，符合条件的字典序最小的时间是多少。其中字典序比较为用“HHMMSS”的6位字符串进行比较。


输入描述:
每个输入数据包含多个测试点。每个测试点后有一个空行。 第一行为测试点的个数T(T<=100)。 每个测试点包含1行，为一个字符串”HH:MM:SS”，表示钟表显示的时间。


输出描述:
对于每个测试点，输出一行。如果钟表显示的时间为真实存在的时间，则不做改动输出该时间，否则输出一个新的”HH:MM:SS”，表示修改最少的数字情况下，字典序最小的真实存在的时间。

输入例子1:
2
19:90:23
23:59:59

输出例子1:
19:00:23
23:59:59
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

std::vector<std::string> split(const std::string& src, char delim)
{
	if (src == "")
		return{};

	std::vector<std::string> res;
	std::string tmp = src;

	size_t index = 0;
	size_t last = 0;
	last = tmp.find_first_not_of(delim, last);//找到第一个不为分隔符的字符
	index = tmp.find_first_of(delim, last);//找到第一个分隔符
	if (index == std::string::npos) //没找到
		return{};
	while (index != std::string::npos)//npos代表字符串的结尾
	{
		std::string target = tmp.substr(last, index - last);
		res.push_back(target);

		//last = index +1;
		last = tmp.find_first_not_of(delim, index);
		index = tmp.find_first_of(delim, last);
	}
	if (index == std::string::npos && tmp.length() > last)//到末尾了,如果整个长度大于last坐标,说明还有最后一个字符要放到vector
		res.push_back(tmp.substr(last));
	return res;
}

std::string getMinTime(const std::string&str)
{
	auto hms = split(str, ':');
	int h = stoi(hms[0]); 
	if (h > 23)
	{
		//需要修改
		h = h % 10;
	}
	int m = stoi(hms[1]);
	if (m > 59)
	{
		m = m % 10;
	}
	int s = stoi(hms[2]);
	if (s > 59)
	{
		s = s % 10;
	}
	char buffer[256];
	snprintf(buffer, 9, "%02d:%02d:%02d", h, m, s);
	std::string res(buffer);
	return res;
}



int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		std::string str;
		cin >> str;
		cout << getMinTime(str) << endl;
	}

	/*std::string str = "69:11:12";
	auto res = getMinTime(str);*/

	return 0;
}