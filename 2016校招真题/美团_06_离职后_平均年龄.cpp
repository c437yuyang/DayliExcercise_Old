/*
已知某公司总人数为W，平均年龄为Y岁(每年3月末计算，同时每年3月初入职新人)，假设每年离职率为x，x>0&&x<1,每年保持所有员工总数不变进行招聘，新员工平均年龄21岁。
从今年3月末开始，请实现一个算法，可以计算出第N年后公司员工的平均年龄。(最后结果向上取整)。
输入描述:
输入W Y x N
输出描述:
输出第N年后的平均年龄
示例1
输入

5 5 0.2 3
输出

15
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


//我理解成了走的永远是老员工，其实不是
int solve(int peoplenum, double avgAge, double outRate, int years) {

	if (outRate*years <= 1.0) {
		auto stay = 1 - outRate*years;
		int all = (stay*peoplenum * avgAge + outRate*years*peoplenum * 21);
		return ceil(all*1.0 / peoplenum);
	}
	return 21;
}


//牛客看到的

//这个题着实让我弄了好一会，首先有三个误区，
//第一个误区，每年在招纳新员工的同时，老员工的年龄是要增长的
//第二个误区，为什么最后的公式与 W 无关。
//第三个误区，是这个向上取整，题目给出的用例是5 5 0.2 3
//然后我计算第一年的平均年龄是9，不用取整。
//然后计算第二年的平均年龄是11.4，这时候我直接向上取整了，变成了12
//所以下一年的平均年龄我误以为是12+1，导致我的计算结果不符合
//其实题目是想让你把最后一年计算出来的年龄向上取整。
//下面看一下代码
int Average(int W, double Y, double x, int N) {
	//W表示公司总人数，Y表示当年平均年龄，x表示离职率，N表示多年以后
	for (int i = 0; i < N; i++) {
		//原始公式是这个Y = ((Y+1)*(W-W*x) + 21*(W*x))/W;
		//先求的离职之后还没有纳新时所有员工的总年龄，
		//记得Y+1，老员工也是要长大的
		//求得老员工的总年龄，然后加上纳新的员工的总年龄
		//最后除去公司的总人数，就是当年公司的平均年龄。
		//这个年龄是不进行向上取整的，而且我们发现这个公式是可以化简的
		//*************************************
		//下面是化简之后的公式，可以发现公式是与W没有关系的，
		//这就是为啥有的人纳闷为啥别人直接给出公式为啥与W无关，
		//但是自己又感觉最后公式肯定与W有关的原因了。
		//所以传参的时候可以不用传W。此处只是为了说明，
		Y = (Y + 1)*(1 - x) + 21 * x;
	}
	//最后对求得的结果进行向上取整。返回就OK了
	return (int)ceil(Y);
}

int main() {
	int peoplenum; double avgAge; double outRate; int years;
	while (cin >> peoplenum >> avgAge >> outRate >> years) {
		//cout << solve(peoplenum, avgAge, outRate, years) << endl;
		cout << Average(peoplenum, avgAge, outRate, years) << endl;
	}


	return 0;
}