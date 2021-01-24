/*
����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
��������:
����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
�������:
Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
ʾ��1
����
����
7 2
���
����
111
*/

//ע���:
//���������

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <deque>
using namespace std;

char table[] = { 'A','B','C','D','E','F' };


void convertdecimal(int n, int k)
{
	if (n == 0)
	{
		cout << 0 << endl;
		return;
	}
	std::deque<char> res;
	if (n < 0)
	{
		cout << "-";
		n = -n;
	}
	while (n > 0)
	{
		int cur = n%k;
		if (cur >= 10)
			res.push_front(table[cur - 10]);
		else res.push_front('0' + cur);
		n /= k;
	}

	for (auto i : res)
	{
		cout << i;
	}
	cout << endl;

}


int main()
{
	int n;
	int k;
	cin >> n >> k;
	convertdecimal(n, k);

	return 0;
}

