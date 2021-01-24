/*
GPU叠图
题目描述
GPU绘制图像时，会把各个APP窗口绘制图像叠图之后再进行绘制，以避免无效、多余的绘制运算。

比如 ：

桌面上需要绘制如下两个APP

                        +---------------------------------+
                        | A1(400,80)                      |
  B1(20,150)            |                                 |
 +-------------------------------------+                  |
 |                      |              |                  |
 |                      |              |                  |
 |                      |              |                  |
 |              B       |              |   A              |
 |                      |              |                  |
 |                      |              |                  |
 |                      |              |                  |
 |                      |              |                  |
 +-------------------------------------+ B2(720,650)      |
                        |                                 |
                        |                                 |
                        |                                 |
                        +---------------------------------+A2(1000,680)
APP A 窗口的左上角是 A1(400,80),右下角是A2(1000,680) --> 需要绘制 (1000-400) * (680-80) = 36万像素

APP B 窗口的左上角是 B1(20,150),右下角是B2(720,650) --> 需要绘制 (720 - 20) * (650 -150) = 35万像素

如果不进行叠图处理，GPU需要绘制像素个数为APP A所占像素点 加APP B所占像素点 共 71万像素。

但因为窗口A和B之间有重叠部分只需要绘制一次，叠图之后需要计算的像素点会减少到55万像素 。

请你帮忙实现一个算法计算GPU绘制时的运算量。

输入说明
输入文件data.txt，在当前目录,第一个数字N（1<=N<=100）表示有N个APP窗体需要绘制， 后面N行，每一行4个数值(int), x1 y1 x2 y2 (0 <= x1 < x2 <= 100000;0 <= y1 < y2 <= 100000),表示窗体的左上角和右下角像素点坐标。

输出说明
叠图处理后需要GPU需要绘制多少像素点。

示例1
输入：

2 
10 10 20 20 
15 15 25 25
输出：

175
示例2
输入：

2 
400 80 1000 680 
20 150 720 650
输出：

550000
*/

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct app
{
	int x1;
	int y1;
	int x2;
	int y2;
};

bool isinside(app a1, app a2)
{
	if (a1.x1 <= a2.x1 && a1.y1 <= a2.y1 && a1.x2 >= a2.x2 && a2.y2)
		return true;
	return false;
}

int main()
{
	ifstream ifs("data.txt");
	int n;
	ifs >> n;
	vector<app> avec;
	while (n--)
	{
		app tmp;
		ifs >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
		avec.push_back(tmp);
	}
	vector<app> avec1;
	for (int i = 0; i < avec.size(); ++i)
	{
		int j = i;
		for (; j < avec.size(); ++j)
		{
			if (j == i)
				continue;
			else if (isinside(avec[j], avec[i]))
				break;
		}
		if (j == avec.size())
			avec1.push_back(avec[i]);
	}
	avec.clear();
	avec = avec1;

	long long res = 0;
	for (int i = 0; i < avec.size(); ++i)
		res += (avec[i].x2 - avec[i].x1) * (avec[i].y2 - avec[i].y1);

	for (int i = 0; i < avec.size(); ++i)
	{
		for (int j = i + 1; j < avec.size(); ++j)
		{
			if (avec[j].x1 >= avec[i].x2 || avec[j].x2 <= avec[i].x1)
				continue;
			else if (avec[j].y1 >= avec[i].y2 || avec[j].y2 <= avec[i].y1)
				continue;
			else
			{
				app tmp;
				tmp.x1 = max(avec[j].x1, avec[i].x1);
				tmp.x2 = min(avec[j].x2, avec[i].x2);
				tmp.y1 = max(avec[j].y1, avec[i].y1);
				tmp.y2 = min(avec[j].y2, avec[i].y2);
				int k = 0;
				for (; k < avec.size(); ++k)
				{
					if (k == i || k == j)
						continue;
					else if (isinside(avec[k], tmp))
						break;
				}
				if (k == avec.size())
					res -= (tmp.y2 - tmp.y1) * (tmp.x2 - tmp.x1);
			}
		}
	}
	cout << res << endl;
	return 0;
}