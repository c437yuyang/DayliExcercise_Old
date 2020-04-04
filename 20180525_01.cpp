#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
void solve(long long l, long long r)
{
    long long div[10] = {0};
    for (int i = 0; i < 9; ++i)
    {
        div[i] = (int)pow(10, i);
    }
    int lastDivIdx = 0;

    long long res[9] = {0};
    for (long long x = l; x <= r; ++x)
    {
        for (long long i = 1; i <= x; ++i)
        {
            if (x % i == 0)
            {
                for (int j = lastDivIdx; j < 10; ++j)
                {
                    if (i / div[j] < 10)
                    {
                        ++res[i / div[j] - 1];
                        if (j > lastDivIdx)
                            lastDivIdx = j;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        std::cout << res[i] << std::endl;
    }
}

struct mydata
{
    long long value;
    std::vector<long long> occurs(9, 0);
};

void solve1(long long l, long long r)
{
    long long div[10] = {0};
    for (int i = 0; i < 9; ++i)
    {
        div[i] = (int)pow(10, i);
    }
    int lastDivIdx = 0;

    long long res[9] = {0};
    for (long long x = l; x <= r; ++x)
    {
        for (long long i = 1; i <= x; ++i)
        {
            if (x % i == 0)
            {
                for (int j = lastDivIdx; j < 10; ++j)
                {
                    if (i / div[j] < 10)
                    {
                        ++res[i / div[j] - 1];
                        if (j > lastDivIdx)
                            lastDivIdx = j;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        std::cout << res[i] << std::endl;
    }
}

int GetHighDigit(int value)
{
    long long div[10] = {0};
    for (int i = 0; i < 9; ++i)
    {
        div[i] = (int)pow(10, i);
    }
    int lastDivIdx = 0;

    for (int j = 0; j < 10; ++j)
    {
        if (value / div[j] < 10)
        {
            return value / div[j];
        }
    }
    return -65536;
}

int main()
{
    int l, r;
    // std::cin >> l >> r;
    // solve(l, r);
    std::cout << GetHighDigit(1) << std::endl;
    std::cout << GetHighDigit(9) << std::endl;
    std::cout << GetHighDigit(45) << std::endl;

    std::cout << GetHighDigit(1234) << std::endl;

    return 0;
}