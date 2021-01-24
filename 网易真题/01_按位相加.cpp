#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <YXPUtility>
using namespace std;

//按位相加，递归版本
int handle(int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	int i = a^b;
	int j = (a&b) << 1;
	return  handle(i, j);
}

int main()
{
	auto res = handle(1024, 256);
	return 0;
}