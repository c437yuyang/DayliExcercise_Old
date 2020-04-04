/*
��һ��X*Y������С��Ҫ�ڴ������ϴ����Ͻǵ����½ǣ�ֻ���߸����ֻ�����һ������ߡ������һ���㷨������С���ж������߷�����������������int x,int y���뷵��С�ŵ��߷���Ŀ��
��������:
�������һ�У����Ÿ���������������x��y��ȡֵ��Χ[1,10]��
�������:
�������һ�У�Ϊ�߷�����Ŀ��
ʾ��1
����
3 2
���
10
*/
#include <vector>
#include <iostream>
using namespace std;

int solve(int rows, int cols) {
	vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 1));
	//��i,jλ���ߵ�[rows,cols]λ�õ��߷���Ŀ
	for (int i = rows - 1; i >= 0; --i) {
		for (int j = cols - 1; j >= 0; --j) {
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}

	return dp[0][0];

	//��0��0�ߵ�i,jλ�õ��߷���Ŀ��[i,0],[0,j] ��ʼ��Ϊ1
	//for (int i = 1; i <= rows; ++i) {
	//	for (int j = 1; j <= cols; ++j) {
	//		dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	//	}
	//}
	//return dp[rows][cols];
}


int main() {
	int m, n;
	cin >> m >> n;

	cout << solve(m, n) << endl;

	return 0;
}