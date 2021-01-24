/*
Given two binary strings, return their sum (also a binary string).

For example,
a ="11"
b ="1"
Return"100".
*/

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        if (a == "")
            return b;
        if (b == "")
            return a;
        std::string res;
        if (a.length() < b.length())
            a = std::string(b.length() - a.length(), '0') + a;
        else
            b = std::string(a.length() - b.length(), '0') + b;

        int carry = 0;
        for (int i = a.length() - 1; i >= 0; --i)
        {
            int curDigit = a[i] - '0' + b[i] - '0' + carry;
            carry = 0;
            if (curDigit > 1)
            {
                curDigit = curDigit - 2;
                carry = 1;
            }
            res = std::string(1, '0' + curDigit) + res;
        }
        if (carry == 1)
            res.insert(res.begin(), '1');
        return res;
    }
};