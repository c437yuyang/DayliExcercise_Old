/*
A[n,m]是一个n行m列的矩阵，a[i,j]表示A的第i行j列的元素，定义x[i,j]为A的第i行和第j列除了a[i,j]之外所有元素(共n+m-2个)的乘积，即x[i,j]=a[i,1]*a[i,2]*...*a[i,j-1]*...*a[i,m]*a[1,j]*a[2,j]...*a[i-1,j]*a[i+1,j]...*a[n,j],现输入非负整形的矩阵A[n,m]，求MAX(x[i,j])，即所有的x[i,j]中的最大值。
输入描述:
第一行两个整数n和m。之后n行输入矩阵，均为非负整数。
输出描述:
一行输出答案。
示例1
输入
复制
3 5
5 1 8 5 2
1 3 10 3 3
7 8 5 5 16
输出
复制
358400
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

long long solve(vector<vector<long long>>&nums) {
	int m = nums.size();
	int n = nums[0].size();

	vector<long long> rowProducts(m); //每一行的乘积存下来加速计算
	vector<long long> colProducts(n);

	//计算每一行的乘积
	for (int i = 0; i < m; ++i) {
		long long rowCur = 1;
		for (int j = 0; j < n; ++j) {
			rowCur *= nums[i][j];
		}
		rowProducts[i] = rowCur;
	}

	//计算每一列的乘积
	for (int j = 0; j < n; ++j) {
		long long colCur = 1;
		for (int i = 0; i < m; ++i) {
			colCur *= nums[i][j];
		}
		colProducts[j] = colCur;
	}

	long long max = std::numeric_limits<int>::min();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (rowProducts[i] == 0 || colProducts[j] == 0 || nums[i][j] == 0) { //当前数是0，或者当前行是0或者当前列是0的单独计算
				long long rowCur = 1;
				for (int j1 = 0; j1 < n; ++j1) {
					if (j1 == j)
						continue;
					rowCur *= nums[i][j1];
				}
				long long colCur = 1;
				for (int i1 = 0; i1 < m; ++i1) {
					if (i1 == i)
						continue;
					colCur *= nums[i1][j];
				}
				max = std::max(max, rowCur * colCur);
			} else //不是特殊情况的直接可以除了来加速计算
				max = std::max(max, (rowProducts[i] / nums[i][j]) * (colProducts[j] / nums[i][j]));
		}
	}
	return max;
}



int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<vector<long long>> mat(m, vector<long long>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> mat[i][j];
			}
		}

		cout << solve(mat) << endl;

	}


	return 0;
}