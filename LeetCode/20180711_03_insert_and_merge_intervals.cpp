/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1: 
Given intervals[1,3],[6,9], insert and merge[2,5]in as[1,5],[6,9].

Example 2: 
Given[1,2],[3,5],[6,7],[8,10],[12,16], insert and merge[4,9]in as[1,2],[3,10],[12,16].

This is because the new interval[4,9]overlaps with[3,5],[6,7],[8,10].
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>



struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


//牛客上的
using std::vector;
class Solution
{
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		vector<Interval> res;
		int i = 0;
		for (; i < intervals.size(); i++)
		{
			if (newInterval.end < intervals[i].start) //后面的是不相关的
				break;
			else if (newInterval.start > intervals[i].end) //新newInterval前面的直接也会进入res
				res.push_back(intervals[i]);
			else //有重叠部分的，就累计计算最大就行了
			{
				newInterval.start = std::min(newInterval.start, intervals[i].start);//start要找最小
				newInterval.end = std::max(newInterval.end, intervals[i].end); //end要找最大
			}
		}

		res.push_back(newInterval);//
		for (; i < intervals.size(); i++) //结算break后尾巴上的
			res.push_back(intervals[i]);
		return res;
	}
};


void test1()
{
	Interval i1{ 1,3 };
	Interval i2{ 6,9 };
	Interval i3{ 2,5 };
	std::vector<Interval> is{ i1,i2 };
	Solution s;
	auto news = s.insert(is, i3);
}

void test2()
{
	Interval i3{ 4,9 };
	std::vector<Interval> is{ {1,2},{3,5},{6,7},{8,10},{12,16} };
	Solution s;
	auto news = s.insert(is, i3);
}

void test3()
{
	Interval i3{ 5,7};
	std::vector<Interval> is{ { 1,5} };
	Solution s;
	auto news = s.insert(is, i3);
}


void test4()
{
	Interval i3{ 1,7 };
	std::vector<Interval> is{ { 1,5 } };
	Solution s;
	auto news = s.insert(is, i3);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}