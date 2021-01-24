/*
��һƬ1000*1000�Ĳݵأ�С�׳�ʼվ��(1,1)(�����Ͻǵ�λ��)��С����ÿһ��������������ƶ������ڵĲݵ��ϳԲ�(С�ײ����߳��߽�)�����ɳ�����ȥ��׽�ɰ���С�ף�
��������n�����塣��i�����屻�����ں�����Ϊxi ��������Ϊyi ��λ���ϣ�С��һ������һ�����壬���ᱻ������׽����Ϊ��ȥ���С�ף���Ҫ֪��С�����ٶ�������ܻ�����һ�����壬�Ӷ���ǰ���С�ס�
��������:
��һ��Ϊһ������n(n �� 1000)����ʾ����һ��ӵ��n�����塣
�ڶ�����n������xi����ʾ��i������ĺ�����
��������n������yi����ʾ��i�������������
��֤���궼�ڲݵط�Χ�ڡ�
�������:
���һ������,��ʾС�����ٿ��ܶ���������볬��������
ʾ��1
����
3
4 6 8
1 2 1
���
3
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int solve(std::vector<int>&x, std::vector<int>&y)
{
	int min = std::numeric_limits<int>::max();
	for (int i = 0; i < x.size(); ++i)
	{
		min = std::min(min, (x[i] - 1) + (y[i] - 1)); //��ʵ������һ��ֱ��(ŷ�����)���밡������
	}
	return min;

}


int main()
{
	int n;
	cin >> n;
	std::vector<int>x(n), y(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	for (int i = 0; i < n; ++i)
		cin >> y[i];

	cout << solve(x, y) << endl;

	return 0;
}