#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

std::string getFileExtension(const std::string &str) {
	int lastIdx = str.find_last_of('.');
	if (lastIdx == -1)
		return "null";
	return str.substr(lastIdx + 1);
}

int main() {

	std::string path;
	while (cin >> path) {
		cout << getFileExtension(path) << endl;
	}


	return 0;
}

