#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

/*
找所有字符串的最长公共前缀
*/

//牛客看到的
//先对字符串排序，然后考虑第一个和最后一个的首字符，这两个字符必定是差距最大的两个
//(因为排序首先从第一个开始排)，如果这两个不等，就返回空，否则，说明所有字符串的首
//字符相等，那么接着判断第二个。
class Solution1
{
  public:
    string longestCommonPrefix1(vector<string> &strs)
    {
        if (!strs.size())
            return "";
        sort(strs.begin(), strs.end()); //O(nlogn*m) ,n是vector的数量，m是字符串的长度
        int i = 0, sz = strs.size(), l = min(strs[0].size(), strs[sz - 1].size());
        for (; i < l; i++)
            if (strs[0][i] != strs[sz - 1][i])
                return strs[0].substr(0, i);
        return strs[0].substr(0, l);
    }
};

//我做的，O(N*m),还要快一些,OJ也体现了
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        int len = 0;
        for (;; ++len) //就是依次比较每个字符串的i位置，看是否相等，相等就下一个位置，不相等就break
            for (int i = 0; i < strs.size() - 1; ++i)
                if (len >= strs[i].length() || len >= strs[i + 1].length() || strs[i][len] != strs[i + 1][len])
                    return strs[0].substr(0, len);
    }
};

int main()
{
    vector<string> strs = {"abcdef", "abd", "abde"};
    Solution s;
    auto res = s.longestCommonPrefix(strs);

    return 0;
}