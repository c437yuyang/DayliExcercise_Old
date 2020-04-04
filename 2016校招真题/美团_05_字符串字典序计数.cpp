/*看了之前50多个答案，发现大部分都是错误的，根据自己对题目的理解，给出了以下思路，目前
我还没有找到bug，欢迎牛友们检查，如有bug，我继续修改，答题思路是对的*/
/*首先是从之前的几个测试样例分析，其中一个为 str1 = cpqejrrgp, str2 = cpqejtrdg,
len1 = 9, len2 = 9，设所求满足情况的字符串代号为 str（str有35064种）。
第一步：首先找到两个字符串相对应位置的第一个不相等的位置，即若ab 和 ce,
第一个相对位置不相等的为值就是下标为0的地方 a 和 c 不一样，str1和str2中第一个相对不相等
的位置是下标为5的地方，即 r 和 t，设下标为k；
第二步：先求在此下标处，字符处于下标位置字符之间的情况，即str[k]>str1[k] && str[k]<str2[k]
的情况，这个最好算，只要k位置大于str1小于str2对应的k位置，后面的任一位置可以随意取，每个
位置有26种，例如str1[5]和str2[5]之间共有num1种（‘t’-'r'-1=1种即为's'这一种情况），
str[5]为s的时候，后面三位可以随意取；共有(str2[k] - str1[k] - 1)*pow(26, i - k)种，
其中i为len1到len2之间的取值，这里用一个for循环累加；
第三步：其次再求str[k]==str1[k]时有多少种，此时，str[k+1]需大于str1[k+1],k+2位，k+3位...
可以随意取，接着再求str[k]==str1[k]&&str[k+1]==str1[k+1]的情况，需str[k+2]大于str1[k+2]
，k+3以及之后的位置随意取，以此类推，直到算到k==len2-1的位置为止;
第四步：最后求str[k]==str2[k]的情况，此时，str[k+1]需要小于str2[k+1],k+2，k+3等之后的
位置随意取，接着再求str[k]==str2[k]&&str[k+1]==str2[k+1]的情况，需要str[k+2]小于str2[k+2],
后面的位置随意取，以此类推，直到算到k==len2-1的位置为止；
第五步：把所有情况相加，注意还有几处边界位置需要处理，具体参考以下代码
*/
#include<iostream>
#include<string>
#include<math.h>
using namespace std;


//牛客看到的，没怎么看懂
int main() {
	string str1, str2;
	int len1, len2;
	while (cin >> str1 >> str2 >> len1 >> len2) {
		if (str1.length() < len2)
			str1.append(len2 - str1.length(), 'a' - 1); //补的是不影响排序大小的
		if (str2.length() < len2)
			str2.append(len2 - str2.length(), 'z' + 1);
		long long sum = 0;
		int k = 0;
		//第一步，找第一个相对位置不相等的位置下标
		while (str1[k] == str2[k]) {
			k++;
		}
		if (str1[k] < str2[k] && len1 <= len2) {
			//第二步，计算str[k]>str1[k] && str[k]<str2[k]的情况
			for (int i = len1 - 1; i < len2; i++) {
				if (i == k) {
					if (k == len1 - 1 && k == len2 - 1)
						sum += str2[k] - str1[k] - 1;
					else
						sum += str2[k] - str1[k];
				} else
					sum += (str2[k] - str1[k] - 1)*pow(26, i - k);
			}
			k++;
			//第三步，计算str[k]==str1[k]时的情况和str[k]==str2[k]的情况
			for (int i = len1; i <= len2; i++) {
				for (int j = k; j < i; j++)
					sum += ('z' - str1[j])*pow(26, i - j - 1);
				for (int j = k; j < i; j++)
					sum += (str2[j] - 'a')*pow(26, i - j - 1);
			}
		}
		cout << sum << endl;//我这里没有对1000007取模，答案也是能过的，牛友们可自行添加
	}
	system("pause");
	return 0;
}