/*
�����������ϣ�Ҫ��{A} + {B}�� ע��ͬһ�������в�����������ͬ��Ԫ�ء�
��������:
ÿ���������ݷ�Ϊ����,��һ������������n,m(0 �� n,m �� 10000)���ֱ��ʾ����A�ͼ���B��Ԫ�ظ����������зֱ��ʾ����A�ͼ���B��ÿ��Ԫ��Ϊ������int��Χ������,ÿ��Ԫ��֮���и��ո������
�������:
���ÿ���������һ�����ݣ���ʾ�ϲ���ļ��ϣ�Ҫ���С���������ÿ��Ԫ��֮����һ���ո����,��ĩ�޿ո�
ʾ��1
����
����
3 3
1 3 5
2 4 6
���
����
1 2 3 4 5 6
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(std::vector<int> &v1, std::vector<int> &v2) {
	int i1 = 0, i2 = 0;
	int cnt = 0;
	std::sort(v1.begin(), v1.end());//��Ϊԭʼ������ģ�Ҫ�����򣬵��������Ӷ�һ�¾������ˣ�������ֱ����set����
	std::sort(v2.begin(), v2.end());//����������ֱ��merge��O(n)
	v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
	v2.erase(std::unique(v2.begin(), v2.end()), v2.end());
	std::vector<int> merged(v1.size() + v2.size());
	while (i1 < v1.size() && i2 < v2.size()) {
		if (v1[i1] < v2[i2]) {
			merged[cnt++] = v1[i1++];
		} else if (v1[i1] > v2[i2]) {
			merged[cnt++] = v2[i2++];
		} else {
			merged[cnt++] = v1[i1];
			++i1;
			++i2;
		}
	}

	while (i1 < v1.size()) {
		merged[cnt++] = v1[i1++];
	}
	while (i2 < v2.size()) {
		merged[cnt++] = v2[i2++];
	}
	
	for (int i = 0; i < cnt; ++i) {
		cout << merged[i];
		if (i != cnt - 1) {
			cout << " ";
		}
	}
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	std::vector<int> v1(n1), v2(n2);
	for (int i = 0; i < n1; ++i)
		cin >> v1[i];
	for (int i = 0; i < n2; ++i)
		cin >> v2[i];

	solve(v1, v2);
	return 0;
}
