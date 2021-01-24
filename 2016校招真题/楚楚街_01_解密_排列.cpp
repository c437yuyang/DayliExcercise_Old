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



vector<vector<char>> solve(vector<char> &chars) {
	vector<vector<char>> res;
	do {
		res.push_back(chars);
	} while (std::next_permutation(chars.begin(), chars.end()));
	std::sort(res.begin(), res.end());
	return res;
}


int main() {


	char c;
	std::set<char> set;
	while (cin >> c) {
		set.insert(c);
	}
	std::vector<char> chars(set.begin(), set.end());
	auto res = solve(chars);
	for (auto &chars : res) {
		for (auto c : chars) {
			cout << c;
		}
		cout << endl;
	}


	return 0;
}