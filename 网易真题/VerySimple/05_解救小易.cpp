/*
有一片1000*1000的草地，小易初始站在(1,1)(最左上角的位置)。小易在每一秒会横向或者纵向移动到相邻的草地上吃草(小易不会走出边界)。大反派超超想去捕捉可爱的小易，
他手里有n个陷阱。第i个陷阱被安置在横坐标为xi ，纵坐标为yi 的位置上，小易一旦走入一个陷阱，将会被超超捕捉。你为了去解救小易，需要知道小易最少多少秒可能会走入一个陷阱，从而提前解救小易。
输入描述:
第一行为一个整数n(n ≤ 1000)，表示超超一共拥有n个陷阱。
第二行有n个整数xi，表示第i个陷阱的横坐标
第三行有n个整数yi，表示第i个陷阱的纵坐标
保证坐标都在草地范围内。
输出描述:
输出一个整数,表示小易最少可能多少秒就落入超超的陷阱
示例1
输入
3
4 6 8
1 2 1
输出
3
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int solve(std::vector<int>&x, std::vector<int>&y)
{
	int min = std::numeric_limits<int>::max();
	for (int i = 0; i < x.size(); ++i)
	{
		min = std::min(min, (x[i] - 1) + (y[i] - 1)); //其实就是算一个直角(欧几里得)距离啊。。。
	}
	return min;

}


int main()
{
	int n;
	cin >> n;
	std::vector<int>x(n), y(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	for (int i = 0; i < n; ++i)
		cin >> y[i];

	cout << solve(x, y) << endl;

	return 0;
}