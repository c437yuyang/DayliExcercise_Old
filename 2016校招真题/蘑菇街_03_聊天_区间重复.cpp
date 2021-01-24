/*
A和B是好友，他们经常在空闲时间聊天，A的空闲时间为[a1 ,b1 ],[a2 ,b2 ]..[ap ,bp ]。B的空闲时间是[c1 +t,d1 +t]..[cq +t,dq +t],这里t为B的起床时间。这些时间包括了边界点。B的起床时间为[l,r]的一个时刻。若一个起床时间能使两人在任一时刻聊天，那么这个时间就是合适的，问有多少个合适的起床时间？
输入描述:
第一行数据四个整数：p,q,l,r（1≤p,q≤50,0≤l≤r≤1000)。接下来p行数据每一行有一对整数ai，bi(0≤aii+1>bi,ci+1>di
输出描述:
输出答案个数
示例1
输入
复制
2 3 0 20
15 17
23 26
1 4
7 11
15 17
输出
复制
20
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

struct Span
{
    int start;
    int end;
};

//就是暴力求解
int solve(vector<Span> &s1, vector<Span> &s2, int l, int r)
{
    int res = 0;
    for (int i = l; i <= r; ++i)
    {
        bool finded = false;
        for (int j = 0; !finded && j < s2.size(); ++j)
        {
            for (int k = 0; k < s1.size(); ++k)
            {
                if (s2[j].start + i >= s1[k].start && s2[j].start + i <= s1[k].end ||
                    s2[j].end + i >= s1[k].start && s2[j].end + i <= s1[k].end)
                {
                    finded = true;
                    break;
                }
            }
        }
        if (finded)
            ++res;
    }
    return res;
}

int main()
{

    int n1, n2, l, r;
    while (cin >> n1 >> n2 >> l >> r)
    {
        vector<Span> s1(n1), s2(n2);
        for (int i = 0; i < n1; ++i)
        {
            cin >> s1[i].start >> s1[i].end;
        }

        for (int i = 0; i < n2; ++i)
        {
            cin >> s2[i].start >> s2[i].end;
        }
        cout << solve(s1, s2, l, r) << endl;
    }

    return 0;
}