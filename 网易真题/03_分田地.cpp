/*
牛牛和 15 个朋友来玩打土豪分田地的游戏，牛牛决定让你来分田地，地主的田地可以看成是一个矩形，每个位置有一个价值。分割田地的方法是横竖各切三刀，分成 16 份，作为领导干部
牛牛总是会选择其中总价值最小的一份田地， 作为牛牛最好的朋友，你希望牛牛取得的田地的价值和尽可能大，你知道这个值最大可以是多少吗？
输入描述:
每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 75），表示田地的大小，接下来的 n 行，每行包含 m 个 0-9 之间的数字，表示每块位置的价值。
输出描述:
输出一行表示牛牛所能取得的最大的价值。
示例1
输入
复制
4 4
3332
3233
3332
2323
输出
复制
2
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
//牛客看到的
/*
思路:
刚看完大佬的思路AC了，可能还有人不明白，我仔细解释一下吧
题意是：通过横竖各三刀将一个矩阵分为16部分，每部分的value即为这一部分包含的所有数字之和。我们要做的就是想一种切法，使得这16部分中value最小的那个尽可能的大。
首先很显然，每一个部分的value在0-sum之间，sum是指整个矩阵所有数字之和。这样最终的结果一定是[0, sum]中的某一个整数
这里稍微逆向思考一下，既然不容易直接求结果，可不可以我猜一个值(k)，然后判断能不能通过某种切法使最小的那一块value>=k呢？（也就是说，使16块的value都能大于等于k）
如果可以的话，我们就可以对[0, sum]这个区间进行二分查找。这个容易理解吧，当然逻辑上你从num开始递减遍历判断a肯定也是ok的，但是会超时，所以换成二分
二分的复杂度是log(sum)
接下来是重点：对于一个值，怎么判断能不能横竖切三刀，使16块的value都大于等于k呢
可以先横着切三刀，然后纵向贪心遍历一遍。这部分我也不用多说了，想不通的话看看代码就明白了。复杂度是n^4

*/

const int maxn = 75 + 5;
int rows, cols;
int Data[maxn][maxn], sum[maxn][maxn];

int GetArea(int row1, int col1, int row2, int col2)
{
	return (sum[row2][col2] - sum[row2][col1] - sum[row1][col2] + sum[row1][col1]);
}

/*
对于一个值，怎么判断能不能横竖切三刀，使16块的value都大于等于k呢
可以先横着切三刀，然后纵向贪心遍历一遍。
*/

bool Judge(int val)
{
	for (int j1 = 1; j1 <= cols - 3; j1++)
	{
		for (int j2 = j1 + 1; j2 <= cols - 2; j2++)
		{
			for (int j3 = j2 + 1; j3 <= cols - 1; j3++) //纵着切三刀
			{
				int peri = 0, cnt = 0; //peri是当前满足都大于val的情况下的当前最小行
				for (int i = 1; i <= rows; i++) //遍历行的位置
				{
					//现在就是，贪心去找，看这样纵着切完了后，横着切得能不能满足条件，最开始就是从第一行切
					//说白了就是，固定了纵向切得位置，现在看peri,到i，能不能满足条件，可以的话就记下当前peri的位置
					int cub1 = GetArea(peri, 0, i, j1); //当前行的四块面积
					int cub2 = GetArea(peri, j1, i, j2);
					int cub3 = GetArea(peri, j2, i, j3);
					int cub4 = GetArea(peri, j3, i, cols);
					if (cub1 >= val && cub2 >= val && cub3 >= val && cub4 >= val) //每一块都大于当前选的值，就是满足的，那么peri就更新
					{
						peri = i; //满足了就更新peri
						cnt++;
					}
				}
				if (cnt >= 4) return true; //找到了4部分(纵着切是三个循环来控制的，现在是横着切)都满足的就返回true
			}
		}
	}
	return false;
}

int main()
{
	cin >> rows >> cols;
	for (int i = 1; i <= rows; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 1; j <= cols; j++)
			Data[i][j] = temp[j - 1] - '0';
	}
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= rows; i++)
		for (int j = 1; j <= cols; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + Data[i][j]; //sum[i][j] 是 [0,0] - [i,j]位置矩阵的sum

	int low = 0, high = sum[rows][cols], mid, ans;
	while (low <= high)
	{
		mid = (low + high) >> 1;
		if (Judge(mid)) //二分查找符合条件的值
		{
			low = mid + 1;
			ans = mid;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << ans << endl;

	return 0;
}