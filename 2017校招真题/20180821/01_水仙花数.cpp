/*
�������ʻ��ļ��ڣ�ˮ�ɻ��������������˵Ĵ�����ѧ���и�ˮ�ɻ�����������������ģ� ��ˮ�ɻ�������ָһ����λ�������ĸ�λ���ֵ������͵����䱾�����磺153=1^3+5^3+3^3�� ����Ҫ�����������m��n��Χ�ڵ�ˮ�ɻ�����
��������:
���������ж��飬ÿ��ռһ�У�������������m��n��100 �� m �� n �� 999����
�������:
����ÿ������ʵ����Ҫ����������ڸ�����Χ�ڵ�ˮ�ɻ���������˵�������ˮ�ɻ���������ڵ���m,����С�ڵ���n������ж������Ҫ���С����������һ���������֮����һ���ո����;
��������ķ�Χ�ڲ�����ˮ�ɻ����������no;
ÿ������ʵ�������ռһ�С�
ʾ��1
����
����
100 120
300 380
���
����
no
370 371
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

bool isShuiXianNum(int num) {
	int numsave = num;
	vector<int> digits;
	while (num != 0) {
		digits.push_back(num % 10);
		num /= 10;
	}
	int res = 0;
	for (int i = 0; i < digits.size(); ++i) {
		res += (int)pow(digits[i], 3);
	}
	return res == numsave;
}


void solve(int m, int n) {
	vector<int> res;
	for (int i = m; i <= n; ++i) {
		if (isShuiXianNum(i))
			res.push_back(i);
	}

	if (res.empty()) {
		cout << "no" << endl;
		return;
	}

	for (int i=0;i<res.size();++i)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << " ";
	}

}


int main() {

	int m, n;
	while (cin >> m >> n) {
		solve(m, n);
	}

	return 0;
}