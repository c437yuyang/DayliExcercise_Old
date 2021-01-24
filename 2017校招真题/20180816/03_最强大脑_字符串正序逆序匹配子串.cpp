/*
СB�˻𳵺�������һ����N�е�M��֮�����С�����·;��ʱ˯ʱ�ѡ����������ۿ�����ķ羰ʱ��ע�⵽ÿ����վ����һ���ر���ɫ�����ģ����������������Ľ����Ǿ�����һС���֡�СB�ڳ˳����������������ѵ�ʱ�䣬�������ó��յ�ʱ����˯���С���վʱ������������̸����һ·�ļ��ţ������Ǿ��ú�����˼�����ǰ�N����M֮�侭����վ��������ɫ�����г�����Ȼ�������СB�ǵõ�������ɫ���У������ж�СB�����Ǵ�N��M֮����Щ������ܿ�����˵��ɫ�����ģ����Ǹ����Ͳ����ܿ�������ɫ����ĸ������ͬ����ĸ������ͬ����ɫ����ͬ����ĸ���ʾ��ͬ����ɫ��
��������:
�������ж���������ݣ�ÿ��������ݰ������У���һ��Ϊһ����Сд������ĸ���ɵķǿ��ַ��������Ȳ�����10^5����ʾN��M֮�䳵վ����ɫ���𳵴�M��N����ʱ�������ĳ�վ��ͬ��ֻ�Ƿ����෴���ڶ���ΪСB�ڵ�һ��˯��ʱ��������ɫ���У�������ΪСB�ڵڶ���˯��ʱ��������ɫ���С��������ж���Сд��������ĸ���ɵ��ַ��������Ȳ�����100����ĸ��ÿ�����е���ɫ˳�����а�СB������ʱ��˳�����С�
�������:
��ÿ��������ݣ��ڵ������������СB�����з���

forward - ��N��M����

backward -��M��N����

both - ���ַ����п��ܣ�

invalid - �����ܿ�����������ɫ���У�
ʾ��1
����
atob
a
b
aaacaaa
aca
aa
���
forward
both

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

bool checkForward(const std::string &colorsAll, const std::string &seq1, const std::string &seq2)
{
	int pos1 = colorsAll.find(seq1);
	if (pos1 == -1)
		return false;
	int pos2 = colorsAll.find(seq2, pos1 + seq1.length());
	if (pos2 == -1)
		return false;
	return true;
}

bool checkBackward(const std::string &colorsAll, const std::string &seq1, const std::string &seq2)
{
	std::string reversColors(colorsAll.rbegin(), colorsAll.rend());

	int pos1 = reversColors.find(seq1);
	if (pos1 == -1)
		return false;
	int pos2 = reversColors.find(seq2, pos1 + seq1.length());
	if (pos2 == -1)
		return false;
	return true;
}

void solve(const std::string &colorsAll, const std::string &seq1, const std::string &seq2)
{

	bool fw = checkForward(colorsAll, seq1, seq2);
	bool bw = checkBackward(colorsAll, seq1, seq2);
	if (fw && bw)
		cout << "both" << endl;
	else if (fw)
		cout << "forward" << endl;
	else if (bw)
		cout << "backward" << endl;
	else
		cout << "invalid" << endl;

}


int main()
{


	std::string strAll, seq1, seq2;
	while (cin >> strAll >> seq1 >> seq2)
	{
		solve(strAll, seq1, seq2);
	}
	

	return 0;
}

