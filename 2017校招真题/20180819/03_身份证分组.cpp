#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

std::string solve(std::string&str) {
	std::string copy;
	for (int i=0;i<str.length();++i)
	{ 
		if (str[i] != ' ')
			copy += str[i];
	}
	if (copy.length() > 14)
		return copy.substr(0, 6) + " " + copy.substr(6, 8) +" " +copy.substr(14);
	else if(copy.length() > 6)
		return copy.substr(0, 6) + " " + copy.substr(6);
	else return copy;
}


int main() {

	std::string str;
	while (getline(cin,str)) {
		cout << solve(str) << endl;
	}

	return 0;
}
