#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <unordered_set>
using namespace std;

std::unordered_set<int> getPrimerNumbers(int n)
{
	if (n == 1)
		return{}; //1不是质数!!!
	if (n == 2)
		return{ 2 };
	if (n == 3)
		return{ 2,3 };

	std::unordered_set<int> set{ 2,3 };
	for (int i = 4; i <= n; ++i)
	{
		bool prime = true;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
			set.insert(i);
	}
	return set;
}

int solve(int sum)
{
	auto primes = getPrimerNumbers(sum);
	int res = 0;

	for (auto it = primes.begin(); it != primes.end() && *it <= sum / 2; ++it)
	{
		int left = sum - *it;
		if (primes.find(left) != primes.end())
		{
			/*cout << *it << " " << left << endl;*/
			++res;
		}
	}
	return res;
}


int main()
{
	/*auto primes = getPrimerNumbers(100);*/

	//cout << solve(10) << endl;
	int n;
	cin >> n;
	cout << solve(n) << endl;

	return 0;
}

