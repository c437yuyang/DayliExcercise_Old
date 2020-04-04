/*
现在有一个数组，其值为从1到10000的连续增长的数字。出于某次偶然操作，导致这个数组中丢失了某三个元素，同时顺序被打乱，现在需要你用最快的方法找出丢失的这三个元素，并且将这三个元素根据从小到大重新拼接为一个新数字，计算其除以7的余数。 例：丢失的元素为336，10，8435，得到的新数字为103368435，除以七的余数为2。
输入描述:
输入数据为一行，包含9997个数字，空格隔开。
输出描述:
输出为一行，包含一个数字。
示例1
输入
复制
同题设例子输入
输出
复制
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