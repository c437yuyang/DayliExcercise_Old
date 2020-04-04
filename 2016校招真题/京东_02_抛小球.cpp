/*
小东和三个朋友一起在楼上抛小球，他们站在楼房的不同层，假设小东站的楼层距离地面N米，球从他手里自由落下，每次落地后反跳回上次下落高度的一半，并以此类推直到全部落到地面不跳，求4个小球一共经过了多少米？(数字都为整数)

给定四个整数A,B,C,D，请返回所求结果。

测试样例：
100,90,80,70
返回：1020
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

//坑逼题目，说是全部整数，结果运算中间要用float 最后再ceil
//题目本身没啥好看的，很简单
class Balls {
public:
	int calcDistance(int A, int B, int C, int D) {
		// write code here
		return calcSingle(A) + calcSingle(B) + calcSingle(C) + calcSingle(D);
	}

	int calcSingle(double height) {
		double res = 0;
		double init = height;
		while (height > 0) {
			res += height * 2;
			height /= 2;
		}
		return ceil(res-init);
	}

};




int main() {

	Balls b;
	auto res = b.calcDistance(100, 90, 80, 70);


	return 0;
}