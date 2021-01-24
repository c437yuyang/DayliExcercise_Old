/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <set>
#include <vector>
#include <map>
using namespace std;

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
bool operator==(const Point &p1, const Point &p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}
class Solution
{
  public:
	int maxPoints(vector<Point> &points)
	{
		int size = points.size();
		if (size == 0)
			return 0;
		else if (size == 1)
			return 1;

		int ret = 0;
		for (int i = 0; i < size; i++)
		{
			int curmax = 1;
			map<double, int> mp;		   //记录指定起点points[i]，然后每个斜率有多少个点
			int vcnt = 0;				   //垂直点
			int dup = 0;				   //重复点
			for (int j = 0; j < size; j++) //就两层循环就够了，每个点，以及其他点和这个点的斜率，就能判断了
			{
				if (j == i)
					continue;
				double x1 = points[i].x - points[j].x;
				double y1 = points[i].y - points[j].y;
				if (x1 == 0 && y1 == 0) //重复点
					dup++;
				else if (x1 == 0) //垂直点，斜率无穷大，因此要单独考虑
				{
					if (vcnt == 0)
						vcnt = 2;
					else
						vcnt++;
					curmax = max(vcnt, curmax);
				}
				else
				{
					double k = y1 / x1; //计算斜率
					if (mp[k] == 0)
						mp[k] = 2;
					else
						mp[k]++;
					curmax = max(mp[k], curmax);
				}
			}
			ret = max(ret, curmax + dup);
		}
		return ret;
	}
};

int main()
{
	//std::vector<Point> points = { { 0,0 },{ 1,1 },{ 0,0 } };
	//std::vector<Point> points = { { 1,1 },{ 1,1 },{ 1,1 } };
	//std::vector<Point> points = { { 3,1 },{ 12,3 },{ 3,1 },{ -6,-1 } };
	//std::vector<Point> points = { { -4,1 },{ -7,7 },{ -1,5 },{ 9,-25 } };
	std::vector<Point> points = {{0, 0}, {1, 1}, {1, -1}};
	Solution s;
	std::cout << s.maxPoints(points) << std::endl;

	return 0;
}