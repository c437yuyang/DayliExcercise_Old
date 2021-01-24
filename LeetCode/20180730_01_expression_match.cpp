#include <iostream>
#include <string>
#include <vector>
#include <cassert>
bool process(const std::string &str1, const std::string &str2, int i, int j);

bool isMatch(const std::string &str1, const std::string &str2)
{
    return process(str1, str2, 0, 0);
}

bool process(const std::string &str1, const std::string &str2, int i, int j)
{
    //if (i == str1.length()) //不能要，必须是j匹配完了才行，因为j存在特殊字符，比如a,ab*,其实i完了并没有配完
    //	return j == str2.length();

    if (j == str2.length())
        return i == str1.length();

    //j + 1 < str2.length()

    if (str2[j + 1] != '*' || j + 1 == str2.length()) //j+1不是*（没有j+1了也就当然是没有*了）
    {
        return (str1[i] == str2[j] || str2[j] == '.') &&
               process(str1, str2, i + 1, j + 1);
    }
    //j+1 是*
    while ((str1[i] == str2[j] || str2[j] == '.') && i < str1.length())
    {

        if (process(str1, str2, i, j + 2))
            return true;
        ++i;
    }

    return process(str1, str2, i, j + 2);
}

int main()
{
    std::string str = "abcccdefg";
    std::string exp = "ab.*d.*e.*";
    assert(isMatch(str, exp));

    str = "a";
    exp = "ab*";
    assert(isMatch(str, exp));
    return 0;
}