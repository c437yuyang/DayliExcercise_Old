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

char findFirstOccur3Times(std::string&str) {
	std::unordered_map<char, int> mp;
	for (auto c : str) {
		if (isalpha(c)) {
			++mp[c];
			if (mp[c] == 3)
				return c;
		}
	}
	return ' ';
}


int main() {
	std::string str;
	getline(cin, str);
	cout << findFirstOccur3Times(str) << endl;

	return 0;
}