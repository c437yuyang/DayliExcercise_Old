/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径
输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

文件路径为windows格式

如：E:\V1R2\product\fpgadrive.c 1325
输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1

结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

如果超过8条记录，则只输出前8条记录.

如果文件名的长度超过16个字符，则只输出后16个字符
示例1
输入
复制
E:\V1R2\product\fpgadrive.c 1325
输出
复制
fpgadrive.c 1325 1
*/

/*
测试用例:
e:\1\aa3.txt 3 e:\3\aa1.txt 2 e:\2\aa2.txt 3 e:\3\aa1.txt 1 e:\1\aa1.txt 3 e:\3\aa1.txt 2 e:\1\aa3.txt 3 e:\2\aa3.txt 2 e:\1\aa1.txt 2 e:\3\aa3.txt 2 e:\1\aa2.txt 2 e:\1\aa3.txt 1 e:\1\aa3.txt 1 e:\2\aa3.txt 2 e:\1\aa2.txt 1 e:\3\aa1.txt 2 e:\1\aa1.txt 3 e:\2\aa1.txt 1 e:\3\aa3.txt 2 e:\1\aa1.txt 1 e:\2\aa2.txt 2 e:\3\aa3.txt 2 e:\1\aa2.txt 1 e:\1\aa3.txt 2 e:\1\aa3.txt 3 e:\1\aa2.txt 3 e:\3\aa1.txt 3 e:\2\aa2.txt 2 e:\1\aa1.txt 1 e:\2\aa3.txt 1 e:\3\aa1.txt 1 e:\2\aa1.txt 3 e:\3\aa3.txt 2 e:\1\aa3.txt 3 e:\2\aa3.txt 3 e:\1\aa2.txt 3 e:\2\aa2.txt 1 e:\1\aa3.txt 1 e:\1\aa3.txt 1 e:\3\aa3.txt 3 e:\3\aa3.txt 2 e:\1\aa2.txt 3 e:\1\aa2.txt 3 e:\1\aa2.txt 3 e:\1\aa1.txt 1 e:\2\aa3.txt 1 e:\3\aa3.txt 1 e:\2\aa3.txt 2 e:\3\aa1.txt 3 e:\2\aa2.txt 2 e:\2\aa2.txt 2 e:\2\aa3.txt 1 e:\1\aa3.txt 3 e:\3\aa1.txt 2 e:\3\aa2.txt 2 e:\1\aa2.txt 1 e:\2\aa2.txt 1 e:\2\aa1.txt 2 e:\2\aa2.txt 1 e:\1\aa2.txt 1 e:\2\aa3.txt 1 e:\2\aa2.txt 1 e:\2\aa1.txt 2 e:\3\aa2.txt 3 e:\3\aa1.txt 3 e:\2\aa2.txt 3 e:\2\aa3.txt 1 e:\3\aa3.txt 2 e:\2\aa3.txt 1 e:\1\aa1.txt 2 e:\3\aa3.txt 1 e:\3\aa1.txt 1 e:\2\aa2.txt 3 e:\3\aa3.txt 2 e:\2\aa1.txt 3 e:\1\aa3.txt 3 e:\3\aa2.txt 1 e:\2\aa1.txt 3 e:\1\aa3.txt 3 e:\2\aa2.txt 2 e:\1\aa1.txt 2 e:\3\aa1.txt 1 e:\1\aa3.txt 1 e:\3\aa1.txt 2 e:\1\aa1.txt 2 e:\1\aa1.txt 3 e:\3\aa1.txt 1 e:\3\aa1.txt 1 e:\2\aa3.txt 3 e:\2\aa2.txt 1 e:\2\aa1.txt 2 e:\2\aa2.txt 1 e:\3\aa2.txt 3 e:\1\aa2.txt 1 e:\3\aa2.txt 2 e:\2\aa1.txt 1 e:\2\aa3.txt 3 e:\1\aa1.txt 2 e:\1\aa1.txt 1 e:\1\aa1.txt 2
对应输出应该为:
aa1.txt 2 14 aa3.txt 1 13 aa1.txt 1 12 aa2.txt 1 12 aa3.txt 3 11 aa3.txt 2 11 aa2.txt 3 10 aa1.txt 3 9
你的输出为:
aa3.txt 3 35
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

struct Error {
	string filename;
	int lineno;
	int cnt;
	int rank; //出现位置
};

struct ErrorHead {
	string filename;
	int lineno;

	bool operator<(const ErrorHead&other) const {
		return to_string(other.lineno) + other.filename <
			to_string(lineno) + filename;
	}
};

std::string getnamenopath(const std::string&path) {
	int pos = path.find_last_of('\\');

	if (pos != -1) {
		return path.substr(pos + 1);
	}
	return path;

}

std::string getLast16chars(const std::string&str) {
	if (str.length() > 16) {
		return str.substr(str.length() - 16);
	}
	return str;
}

void solve(vector<string>&files, vector<int>&lineno) {

	std::map<ErrorHead, int> mp;


	vector<Error> res;
	for (int i = 0; i < files.size(); ++i) {
		string filename = getnamenopath(files[i]);
		ErrorHead eh = { filename,lineno[i] };
		if (mp.find(eh) == mp.end()) {
			mp.insert({ eh,res.size() });
			Error error = { filename, lineno[i], 1,i };
			res.push_back(error);
		} else {
			++res[mp[eh]].cnt;
		}
	}

	std::sort(res.begin(), res.end(), [](const Error&e1, const Error&e2) {
		if (e1.cnt == e2.cnt)
			return e1.rank < e2.rank;
		return e1.cnt > e2.cnt;
		//return e2.cnt <= e1.cnt;
	});

	for (int i = 0; i < 8 && i < res.size(); ++i) {
		cout << getLast16chars(res[i].filename) << " " << res[i].lineno << " " << res[i].cnt << endl;
	}

}


int main() {

	string file; int lineno;
	vector<string> files; vector<int> linenos;
	while (cin >> file >> lineno) {
		files.push_back(file);
		linenos.push_back(lineno);
	}

	solve(files, linenos);

	return 0;
}