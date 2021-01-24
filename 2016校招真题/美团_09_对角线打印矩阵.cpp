/*
有一个二维数组(n*n),写程序实现从右上角到左下角沿主对角线方向打印。

给定一个二位数组arr及题目中的参数n，请返回结果数组。

测试样例：
[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]],4
返回：[4,3,8,2,7,12,1,6,11,16,5,10,15,9,14,13]
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


 vector<int> printMatrix(vector<vector<int>> &mat) {
	 int m = mat.size();
	 int n1 = mat[0].size();
	 int row = 0;
	 int col = n1 - 1;
	 vector<int> res;
	 while (row < m && col >= 0) {
		 int curRow = row;
		 int curCol = col;
		 while (curCol <= n1 - 1 && curRow <= m - 1) {
			 res.push_back(mat[curRow++][curCol++]);
		 }
		 if (col == 0) {
			 ++row;
		 } else {
			 --col;
		 }
	 }
	 return res;
}


int main() {
	int n;
	while(cin >> n)

	return 0;
}