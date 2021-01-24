#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <cassert>
using namespace std;


//两个正整数相加
std::string AddIntegersOfString(std::string&num1, std::string&num2);
//两个正整数相减
std::string SubIntegersOfString(std::string &num1, std::string&num2);

bool checkIsInteger(const std::string &str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] > '9' || str[i] < '0') {
			if (i == 0) {
				if (str[0] != '-' && str[0] != '+')
					return false;
			} else {
				return false;
			}
		}
	}
	return true;
}

bool checkValid(const std::string&str1, const std::string&str2) {
	return checkIsInteger(str1) && checkIsInteger(str2);
}

//0也是true
bool isPositive(const std::string &str) {
	return str[0] == '+' ||
		(str[0] >= '0' && str[0] <= '9');
}
//-0是true
bool isNegative(const std::string &str) {
	return str[0] == '-';
}



//两个整数相加，正负均支持,支持+123，-456
std::string IntergeAdd(std::string&num1, std::string&num2) {
	if (!checkValid(num1, num2))
		return "error";

	if (isPositive(num1) && isPositive(num2))
		return AddIntegersOfString(num1, num2);
	else if (isNegative(num1) && isPositive(num2))
		return SubIntegersOfString(num2, num1.substr(1));
	else if (isPositive(num1) && isNegative(num2))
		return SubIntegersOfString(num1, num2.substr(1));
	else //两个都负
		return "-" + AddIntegersOfString(num1.substr(1), num2.substr(1));
}

//两个正整数相加
std::string AddIntegersOfString(std::string&num1, std::string&num2) {
	if (!checkValid(num1, num2))
		return "error";
	if (num1[0] == '+')
		num1 = num1.substr(1);
	if (num2[0] == '+')
		num2 = num2.substr(1);

	bool num1Longer = num1.length() > num2.length();
	int maxLen = num1Longer ? num1.length() : num2.length();
	std::string res = "";
	if (num1Longer) { //短的前面补零
		num2 = std::string(num1.length() - num2.length(), '0') + num2;
	} else {
		num1 = std::string(num2.length() - num1.length(), '0') + num1;
	}
	int carry = 0;
	for (int i = maxLen - 1; i >= 0; --i) {
		int cur = num1[i] + num2[i] - '0' - '0' + carry;
		carry = 0;
		if (cur >= 10) { //注意是>=
			cur -= 10;
			carry = 1;
		}
		res.push_back(cur + '0');
	}

	if (carry == 1)
		res.push_back('1');
	std::reverse(res.begin(), res.end());
	return res;
}

//两个正整数相减
std::string SubIntegersOfString(std::string &num1, std::string&num2) {

	if (!checkValid(num1, num2))
		return "error";

	if (num1[0] == '+')
		num1 = num1.substr(1);
	if (num2[0] == '+')
		num2 = num2.substr(1);

	//预处理，假设经过预处理后，两数长度相同，且num1>num2
	bool neg = false;
	if (num1.length() > num2.length()) {
		num2 = std::string(num1.length() - num2.length(), '0') + num2; //长度不够补零
	} else if (num2.length() > num1.length()) {
		neg = true;
		std::swap(num1, num2);
		num2 = std::string(num1.length() - num2.length(), '0') + num2;
	} else { //同长度
		if (num1 < num2) {//如果num1比num2小(长度相同直接比较ascii码)，就是负数
			std::swap(num1, num2); //交换
			neg = true;
		}
	}

	std::string res;
	int carry = 0;
	for (int i = num1.size() - 1; i >= 0; --i) {
		int cur = (num1[i] - '0') - (num2[i] - '0') - carry;
		carry = 0;
		if (cur < 0) {
			cur += 10;
			carry = 1;
		}
		res.push_back(cur + '0');
	}

	assert(carry == 0 && "suberror"); //假设了num1>num2,因此一定是carry==0最后
	while (res.size() > 1 && res.back() == '0') //去掉'0'
		res.pop_back();
	if (neg)
		res.push_back('-');
	std::reverse(res.begin(), res.end());
	return res;
}

int main() {
	//std::string str1, str2;
	//while (std::cin >> str1 >> str2) {
	//	std::cout << IntergeAdd(str1, str2) << std::endl;
	//}

	std::string str1 = "0", str2 = "0", res = "0";
	assert(IntergeAdd(str1, str2) == res);

	str1 = "+0", str2 = "-0", res = "0";
	assert(IntergeAdd(str1, str2) == res);

	str1 = "123", str2 = "78", res = "201";
	assert(IntergeAdd(str1, str2) == res);


	str1 = "123", str2 = "-78", res = "45";
	assert(IntergeAdd(str1, str2) == res);

	str1 = "123", str2 = "-178", res = "-55";
	assert(IntergeAdd(str1, str2) == res);

	str1 = "+123", str2 = "-178", res = "-55";
	assert(IntergeAdd(str1, str2) == res);

	str1 = "+1", str2 = "-178", res = "-177";
	assert(IntergeAdd(str1, str2) == res);

	str1 = "+0", str2 = "-178", res = "-178";
	assert(IntergeAdd(str1, str2) == res);
	return 0;
}