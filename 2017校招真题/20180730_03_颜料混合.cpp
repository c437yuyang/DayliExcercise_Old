/*
你就是一个画家！你现在想绘制一幅画，但是你现在没有足够颜色的颜料。为了让问题简单，我们用正整数表示不同颜色的颜料。你知道这幅画需要的n种颜色的颜料，你现在可以去商店购买一些颜料，但是商店不能保证能供应所有颜色的颜料，所以你需要自己混合一些颜料。混合两种不一样的颜色A和颜色B颜料可以产生(A XOR B)这种颜色的颜料(新产生的颜料也可以用作继续混合产生新的颜色,XOR表示异或操作)。本着勤俭节约的精神，你想购买更少的颜料就满足要求，所以兼职程序员的你需要编程来计算出最少需要购买几种颜色的颜料？
输入描述:
第一行为绘制这幅画需要的颜色种数n (1 ≤ n ≤ 50)
第二行为n个数xi(1 ≤ xi ≤ 1,000,000,000)，表示需要的各种颜料.
输出描述:
输出最少需要在商店购买的颜料颜色种数，注意可能购买的颜色不一定会使用在画中，只是为了产生新的颜色。
示例1
输入
3
1 7 3
输出
3
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <YXPUtility>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
//求该数最高位是第几位
int getHighPosition(int a)
{
	int count = 0;
	while (a)
	{
		a >>= 1;
		count++;
	}
	return count;
}

//求解线性方程组的最大秩(初等行变换)类似
int main()
{
	int n;
	std::vector<int> colors;
	while (cin >> n)
	{
		int temp;
		int res = 0;
		int i = n;
		colors.clear();
		while (i--)
		{
			cin >> temp;
			colors.push_back(temp);
		}
		sort(colors.begin(), colors.end());
		//endValue和cmpValue指向最后一个数和倒数第二个数
		int endValue = n - 1;
		int cmpValue = endValue - 1;
		//两种颜色以上才有混合的可能，如果只需要两种颜色，那么最少就要购买两种，购买一种是不可能得到两种颜色的。
		while (colors.size() > 2)
		{
			//只有最高位相同，那么他们的最高位一定可以消去
			if (getHighPosition(colors[endValue]) == getHighPosition(colors[cmpValue]))
			{

				int temp = colors[endValue] ^ colors[cmpValue];
				//如果异或出来的这个低维的颜色没有，就加入到colors里
				if (find(colors.begin(), colors.end(), temp) == colors.end())
				{
					colors.push_back(temp);
					sort(colors.begin(), colors.end());
					//因为新加入了一个数，所以为了让endValue和cmpValue还是指向倒数第一和倒数第二个数，需要++
					endValue++;
					cmpValue++;
				}
			}
			else// 如果两者最高位不同，说明已经所有数的最高位已经只有最大的那个数是 1 了，这样它已经不可能被消掉了，结果＋ 1
			{
				res++;
			}
			//每判断完一次，就把最后一个数扔掉，没什么用了
			colors.pop_back();
			endValue = cmpValue;
			cmpValue--;
		}
		cout << res + colors.size() << endl;
	}
}

//int main()
//{
//	int n;
//	std::cin >> n;
//	std::vector<int> arr(n);
//	for (int i = 0; i < n; ++i)
//	{
//		std::cin >> arr[i];
//	}
//
//	std::cout << solve(arr, n, k) << std::endl;
//
//	return 0;
//}