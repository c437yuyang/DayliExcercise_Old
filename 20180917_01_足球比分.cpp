//足球比分4:2可能出现多少种分数情况? 1:0,2:0,3:0,4:0,4:1,4:2是一种，再比如
//0:1,1:1,2:1,3:1,4:1,4:2另一种
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
std::set<vector<string>> sset;

string getStrScore(int a, int b) { return to_string(a) + "_" + to_string(b); }

void dfs(int cura, int curb, vector<string> &curScore, int a, int b) {
  if (cura == a && curb == b) {
    sset.insert(curScore);
    return;
  }

  if (cura < a) {
    curScore.push_back(getStrScore(cura + 1, curb));
    dfs(cura + 1, curb, curScore, a, b);
    curScore.pop_back();
  }
  if (curb < b) {
    curScore.push_back(getStrScore(cura, curb + 1));
    dfs(cura, curb + 1, curScore, a, b);
    curScore.pop_back();
  }
}

int solve(int a, int b) {
  vector<string> curScore;

  dfs(0, 0, curScore, a, b);
  return sset.size();
}

int main() {
  cout << solve(4, 2) << endl;
  return 0;
}