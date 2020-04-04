/*
小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为avg。每门课由平时成绩和考试成绩组成，满分为r。现在他知道每门课的平时成绩为ai ,若想让这门课的考试成绩多拿一分的话，小v要花bi 的时间复习，不复习的话当然就是0分。同时我们显然可以发现复习得再多也不会拿到超过满分的分数。为了拿到奖学金，小v至少要花多少时间复习。
输入描述:
第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，接下来n行，每行两个整数ai和bi，均小于等于1e6大于等于1
输出描述:
一行输出答案。
示例1
输入
复制
5 10 9
0 5
9 1
8 1
0 1
9 100
输出
复制
43
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

struct Exam {
	int time;
	int score;
};

double calcAvg(vector<Exam>&exams) {
	double score = 0.0;
	for (int i = 0; i < exams.size(); ++i) {
		score += exams[i].score;
	}
	score /= exams.size();
	return score;

}

int sum(vector<Exam>&exams) {
	int score = 0;
	for (int i = 0; i < exams.size(); ++i) {
		score += exams[i].score;
	}
	return score;
}


//就是贪心，按照花费小的来学
/*(c/c++)
只需满足平均成绩大于等于avg即可，不管单科成绩。
所以先从花时间最少的课开始复习，使其满分。
伪码：
if(当前成绩 >= avg*n)
cout << 0 << endl;
else{
sort(时间花费)；
for（时间花费从小到大）
if 当前课程满分后不能获得奖学金
复习至满分，累加复习时间，然后复习下一门
else if 当前课程满分后能获得奖学金
所需时间 += （所需总分 - 当前分数）*在该课程上获得1分所需时间
输出时间；
退出循环。
}
*/
// 注意用Long long 最后一个很大!
long long  solve(vector<Exam> & exams, int fullScore, int avg) {
	std::sort(exams.begin(), exams.end(), [](const Exam&e1, const Exam&e2) {return e1.time < e2.time; });

	double curAvg = calcAvg(exams);
	long long res = 0;
	int curIdx = 0;
	while (curAvg < avg) {
		int neededScore = exams.size()*avg - sum(exams); 
		if (exams[curIdx].score + neededScore <= fullScore) {//当前位置添加就能够到平均分
			res += neededScore*exams[curIdx].time;
			exams[curIdx].score += neededScore;
			curAvg = calcAvg(exams);
			++curIdx;
		}else if (exams[curIdx].score < fullScore) { //否则学到满分
			res += (fullScore - exams[curIdx].score)*exams[curIdx].time;
			exams[curIdx].score = fullScore;
			curAvg = calcAvg(exams);
			++curIdx;
		} else {
			++curIdx;
		}
	}
	return res;
}


int main() {
	int n; int fullscore; int avg;
	while (cin >> n >> fullscore >> avg) {
		vector<Exam> exams(n);
		for (int i = 0; i < n; ++i) {
			cin >> exams[i].score >> exams[i].time;
		}
		cout << solve(exams, fullscore, avg) << endl;
	}


	return 0;
}