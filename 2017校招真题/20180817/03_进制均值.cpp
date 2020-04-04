/*
������һ��CSרҵ��ѧ����СB����ѧ�����ܺò�����ֵ���������ر����Ȥ��ϲ���ü���������������ѧ���⣬���ڣ���������һ����ֵ�任����Ϸ�������ּ�����о����ò�ͬ�Ľ��Ʊ�ʾһ��������ʮ������123���Ϊ16����ʱֻ������λ��7��11��B�����ð˽��Ʊ�ʾΪ��λ��1��7��3������ͬ���Ʊ��ʱ������λ���ĺ�Ҳ��ͬ��������������ʮ�����ƺͰ˽����и�λ���ĺͷֱ���18��11,�� СB����Ȥ���ǣ�һ����A�����2��A-1���Ʊ��ʱ������λ��֮�͵ľ�ֵ�Ƕ��٣���ϣ�����ܰ������������⣿ ���еļ��������ʮ���ƽ��У����Ҳ��ʮ���Ʊ�ʾΪ����Լ��ķ�����ʽ��
��������:
�������ж���������ݣ�ÿ���������Ϊһ������A(1 �� A �� 5000).
�������:
��ÿ��������ݣ��ڵ�����������X/Y����ʽ��������
ʾ��1
����

5
3
���

7/3
2/1
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

long long calcDecimalSum(int num, int decimal) {
	long long res = 0;
	while (num != 0) { //ֻ�Ǽ���ͣ�����˳��
		res += num%decimal;
		num /= decimal;
	}
	return res;
}

long long gcd(long long m, long long n) {
	//return n == 0 ? m : gcd(n, m % n);
	//�ǵݹ�汾
	while (m%n != 0) {
		int c = m%n;
		m = n;
		n = c;
	}
	return n;
}


std::string simpifyFraction(long long m, long long n) {
	if (m%n == 0)
		return to_string(m / n) + "/1";

	//�����Լ��,���취:
	//for (long long i = sqrt(n); i >= 2; --i) {
	//	if ((n%i == 0 && m%i == 0)) {
	//		m /= i; n /= i;
	//	}
	//	if ((n % (n / i) == 0 && m % (n / i) == 0)) {
	//		m /= (n / i);
	//		n /= (n / i);
	//	}
	//}

	long long g = gcd(m, n);

	return to_string(m / g) + "/" + to_string(n / g);
}

void solve(int num) {

	long long res = 0;
	for (int i = 2; i <= num - 1; ++i) {
		res += calcDecimalSum(num, i);
	}
	cout << simpifyFraction(res, num - 2) << endl;
}


int main() {

	int m;
	while (cin >> m) {
		solve(m);
	}
	return 0;
}

