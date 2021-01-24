#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <ctime>
#include <YXPUtility>
using namespace std;
//https://www.cnblogs.com/TenosDoIt/p/3384141.html这里有解释

//FisherYates洗牌算法
void Shuffe(int* a, int n)
{
	for (int i = n - 1; i > 0; --i)
		swap(a[i], a[rand() % (i + 1)]); //把每次随机到的数，移动到末尾，然后下一次缩小范围，不参与随机
}

void Shuffle_InsideOut(char *arrSrc, const int len, char *arrDest)
{
    arrDest[0] = arrSrc[0];
    for(int i = 1; i < len; i++)
    {
        int k = rand()%(i + 1);
        arrDest[i] = arrDest[k];
        arrDest[k] = arrSrc[i];
    }
}

//测试洗牌算法
void TestShuffe()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Shuffe(a, sizeof(a) / sizeof(a[0]));
	yxp_utility::ArrayHelper::printArr(a, 10);
}

int main()
{
	srand((unsigned)time(NULL));//不加此语句的话，每次随机的数会不变
	for (int i=0;i<100;++i)
		TestShuffe();

	//也是一样的
	//std::shuffle()
	//std::random_shuffle()

	//可以用在生成一段范围的数值方面，比如如果要生成不重复的a-z
	//先把a-z放到一个数组里面，然后执行shuffle即可。
	//如果要大小写都要，可以再随机0,1来确定大小写这样来实现

	return 0;
}