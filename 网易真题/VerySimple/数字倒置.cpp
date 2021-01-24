/*
����һ������X���������rev(X)Ϊ��X����λ��ת����������ȥ����ǰ��0������:
��� X = 123����rev(X) = 321;
��� X = 100����rev(X) = 1.
���ڸ�������x��y,Ҫ��rev(rev(x) + rev(y))Ϊ���٣�
��������:
����Ϊһ�У�x��y(1 �� x��y �� 1000)���Կո������
�������:
���rev(rev(x) + rev(y))��ֵ
ʾ��1
����
����
123 100
���
����
223
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int rev(int x);
int solve(int x, int y)
{
	return rev(rev(x) + rev(y));
}

int rev(int x)
{
	int res = 0;
	while (x != 0)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}

	return res;
}

int main()
{
	//cout << solve(123, 100) << endl;


	int x, y;
	cin >> x >> y;
	cout << solve(x, y) << endl;
	return 0;
}