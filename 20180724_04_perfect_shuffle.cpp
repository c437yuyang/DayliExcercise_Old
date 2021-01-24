#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://blog.csdn.net/juzihongle1/article/details/76563336 具体看这个
//注意环操作和上文中略有不同，原因在于：
//文中下标是从1开始，我们编程数组下标从0开始，交换元素时位置需要-1，
//另外递归过程要考虑初始位置与环操作的长度。
//就是1-2-4-6-8-7-5-1 （位置，不是下标）
void cycle(vector<int>& a, int s, int begin, int length)
{
	int pre = a[begin + s - 1];
	int mod = length + 1;
	int next = s * 2 % mod;
	while (next != s)
	{
		swap(pre, a[begin + next - 1]);
		next = 2 * next % mod;
	}
	a[begin + s - 1] = pre;
}


//翻转[s,t]之间的元素
void Reverse(vector<int>& a, int s, int t)
{
	while (s < t) swap(a[s++], a[t--]);
}


//将[s,m]之间的元素循环右移到[m+1,t]之后
//如561234->123456 m=1(下标1，第二个数)
void LeftRotate(vector<int>& a, int s, int m, int t)
{
	Reverse(a, s, m);
	Reverse(a, m + 1, t);
	Reverse(a, s, t);
}


//对数组a进行洗牌算法,s代表洗牌的首元素的位置，t代表洗牌的尾元素位置
void PerfectShuffle(vector<int>& arr, int s, int t)
{
	if (s > t) return;
	int len = t - s + 1;
	//判断数组长度是不是3^k-1
	int k = 1, p = 3;
	while (p - 1 <= len) { k++; p *= 3; }
	//循环右移,确定m,n长度
	int n = len / 2, m = n;
	if (p != len)
	{
		m = (p / 3 - 1) / 2;// 确定m
		LeftRotate(arr, s + m, s + n - 1, s + m + n - 1);
	}
	//前3^k-1个元素进行环操作
	int start = 1;
	while (--k) //对于2*n =（3^k-1）这种长度的数组，恰好只有k个环,这里k会多1，因此是--k
	{
		cycle(arr, start, s, 2 * m);
		start *= 3;
	}
	//最后剩余进行递归操作
	PerfectShuffle(arr, s + 2 * m, t); //比如一共12个数，第一轮会对8个数洗牌，递归对后4个(每次两个)，再对后两个
}


int main()
{
	vector<int> a({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 });
	PerfectShuffle(a, 0, a.size() - 1);
    std::for_each(a.begin(),a.end(),[](int val){std::cout <<val << " "; });
    std::cout << std::endl;
	return 0;
}