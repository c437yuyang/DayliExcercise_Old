//篮球可以一次得1-3分，再求
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
std::set<vector<string>> sset;

void dfs(int cura, int curb, vector<string> &curScore, int a, int b);

string getStrScore(int a, int b) {
	return to_string(a) + "_" + to_string(b);
}

void processA(int cura, int curb, vector<string> &curScore, int a, int b, int step) {
	if (cura + step <= a) {
		curScore.push_back(getStrScore(cura + step, curb));
		dfs(cura + step, curb, curScore, a, b);
		curScore.pop_back();
	}
}

void processB(int cura, int curb, vector<string> &curScore, int a, int b, int step) {
	if (curb + step <= b) {
		curScore.push_back(getStrScore(cura, curb + step));
		dfs(cura, curb + step, curScore, a, b);
		curScore.pop_back();
	}
}

void dfs(int cura, int curb, vector<string> &curScore, int a, int b) {
	if (cura == a && curb == b) {
		sset.insert(curScore);
		return;
	}
	for (int step=1;step<=3;++step)
	{
		processA(cura, curb, curScore, a, b, step);
		processB(cura, curb, curScore, a, b, step);
	}
}

int solve(int a, int b) {
	vector<string> curScore;
	dfs(0, 0, curScore, a, b);
	return sset.size();
}

int main() {
	// cout << solve(108, 85) << endl;
	cout << solve(20, 10) << endl;//数据量太恐怖了，跑不出来的，3，3都有100+种可能
	return 0;
}