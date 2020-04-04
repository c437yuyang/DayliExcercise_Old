#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given[1,3],[2,6],[8,10],[15,18],
return[1,6],[8,10],[15,18].
*/



struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


//牛客看到的的，自己没做出来
using std::vector;
class Solution1 
{
public:
	vector<Interval> merge(vector<Interval> &intervals)
	{
		sort(intervals.begin(), intervals.end(), comp); //按start升序排序
		vector<Interval> res;
		int len = intervals.size();
		for (int i = 0; i < len; i++)
		{
			if (res.empty())
				res.push_back(intervals[i]);
			else
			{
				Interval last = res.back();
				if (last.end >= intervals[i].start)
				{ //需要进行合并
					res.pop_back();
					last.end = std::max(last.end, intervals[i].end); //很巧妙
					res.push_back(last);
				}
				else
					res.push_back(intervals[i]);
			}
		}
		return res;
	}
};

//自己的版本，AC了
class Solution
{
public:
	vector<Interval> merge(vector<Interval> &intervals)
	{
		if (intervals.size() < 2)
			return intervals;

		vector<Interval> res;
		std::sort(intervals.begin(), intervals.end(), 
			[](Interval i1, Interval i2) { return i1.start < i2.start; }); //必须先排序，样例没说是顺序的
		for (int i = 0; i < intervals.size() - 1; ++i)
		{
			if (intervals[i + 1].start > intervals[i].end) //如果不想交，直接加入res
				res.push_back(intervals[i]);
			else
			{
				Interval newinterval;
				newinterval.start = intervals[i].start;
				newinterval.end = std::max(intervals[i + 1].end, intervals[i].end); //相交就取最大的结尾，头是已经顺序的，所以就取前一个的就行了
				intervals[i + 1] = newinterval; //放到i+1位置，下次循环会再来
			}
		}
		res.push_back(intervals.back()); //back位置要么本来就没有不相交，要么和back()-1位置相交，合并到了back()位置，所以始终要加入
		return res;
	}

};
int main()
{
	vector<Interval> v = {
		{1,3},{2,6},{8,10},{15,18}
	};
	Solution s;

	auto v1 = s.merge(v);

	v = {
		{ 1,3 },{ 2,6 },{ 8,10 },{ 9,18 }
	};
	v1 = s.merge(v);


	v = {
		{ 1,10 },{ 2,6 },{ 8,10 },{ 9,18 }
	};
	v1 = s.merge(v);

	v = {
		{ 1,5 },{0,4}
	};
	v1 = s.merge(v);

	return 0;
}

