/*
n ֻ��ţ����һ�ţ�ÿ����ţӵ�� ai ��ƻ����������Ҫ������֮��ת��ƻ����ʹ�����������ţӵ�е�ƻ��������ͬ��ÿһ�Σ���ֻ�ܴ�һֻ��ţ��������ǡ������ƻ������һ����ţ�ϣ�
��������Ҫ�ƶ����ٴο���ƽ��ƻ�������������������� -1��
��������:
ÿ���������һ������������ÿ�����������ĵ�һ�а���һ������ n��1 <= n <= 100������������һ�а��� n ������ ai��1 <= ai <= 100����
�������:
���һ�б�ʾ������Ҫ�ƶ����ٴο���ƽ��ƻ���������������������� -1��
ʾ��1
����
����
4
7 15 9 5
���
����
3
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
using namespace std;

int solve2(std::vector<int>& arr)
{
	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	if (sum % arr.size() != 0)
		return -1;

	int target = sum / arr.size();
	int res = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (abs(arr[i] - target) % 2 != 0) //����ͨ���ƶ�������ʵ�ֵģ����Ǵ��
			return -1;
		if (target - arr[i] > 0)
			res += (target - arr[i]) / 2; //����ÿ��ֻ����������˲�����Σ��Ϳ����������
	}
	return res;
}

int main()
{
	//std::vector<int> arr = { 7,15,9,5 };
	//int res = solve1(arr);
	int n;
	cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << solve2(arr) << endl;

	return 0;
}