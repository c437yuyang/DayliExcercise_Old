/*
������һ�����飬��ֵΪ��1��10000���������������֡�����ĳ��żȻ������������������ж�ʧ��ĳ����Ԫ�أ�ͬʱ˳�򱻴��ң�������Ҫ�������ķ����ҳ���ʧ��������Ԫ�أ����ҽ�������Ԫ�ظ��ݴ�С��������ƴ��Ϊһ�������֣����������7�������� ������ʧ��Ԫ��Ϊ336��10��8435���õ���������Ϊ103368435�������ߵ�����Ϊ2��
��������:
��������Ϊһ�У�����9997�����֣��ո������
�������:
���Ϊһ�У�����һ�����֡�
ʾ��1
����
����
ͬ������������
���
����
2
*/
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    int n = 9997;
    unordered_set<int> s;
    for(int i=0;i<9997;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        s.insert(tmp);
    }
    
    set<int> lost;
    for(int i=1;i<=10000;++i){
        if(s.find(i)==s.end())
            lost.insert(i);
    }
    
    std::string str;
    for(auto i:lost){
        str+=to_string(i);
    }
    
    long long lostcombine = stoll(str);
    cout<<(lostcombine%7)<<endl;
    return 0;
}