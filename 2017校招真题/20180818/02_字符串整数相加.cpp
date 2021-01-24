/*
�����һ���㷨�ܹ�����������ַ����洢������������Ӳ������ԷǷ��������򷵻�error
��������:
����Ϊһ�У����������ַ������ַ����ĳ�����[1,100]��
�������:
���Ϊһ�С��Ϸ���������ӽ�����Ƿ�������error
ʾ��1
����
123 123
abd 123
���
246
Error
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <cassert>
using namespace std;

//�����ֻ�ÿ���������

bool checkValid(const std::string&str1, const std::string&str2) {
	for (int i = 0; i < str1.length(); ++i) {
		if (str1[i] > '9' || str1[i] < '0') {
			if (i == 0) {
				if (str1[0] != '-')
					return false;
			} else {
				return false;
			}
		}
	}

	for (int i = 0; i < str2.length(); ++i) {
		if (str2[i] > '9' || str2[i] < '0') {
			if (i == 0) {
				if (str2[0] != '-')
					return false;
			} else {
				return false;
			}
		}
	}
	return true;
}
//ִ�����������,��������ǲ��޸�ԭʼ���룬��������޸ĵĻ�������ֱ��ǰ�油�㣬���
std::string AddNumsOfString1(const std::string&num1_integer, const std::string&num2_integer) {
	if (!checkValid(num1_integer, num2_integer))
		return "error";

	std::string out_integer = "";
	int min_length = std::min(num1_integer.length(), num2_integer.length());

	int carry = 0;
	int cur = 0;
	int offset = 0;
	if (num1_integer.length() > num2_integer.length()) {
		offset = num1_integer.length() - num2_integer.length();
	} else {
		offset = num2_integer.length() - num1_integer.length();
	}
	for (int i = min_length - 1; i >= 0; --i) {
		if (num1_integer.length() > num2_integer.length()) {
			cur = num1_integer[offset + i] - '0' + num2_integer[i] - '0';
		} else {
			cur = num1_integer[i] - '0' + num2_integer[offset + i] - '0';
		}
		cur += carry;
		carry = 0;
		if (cur >= 10) {
			cur -= 10;
			carry += 1;
		}
		out_integer.push_back((char)('0' + cur));
	}
	//�����λ����
	const std::string&longer = num1_integer.length() > num2_integer.length() ? num1_integer : num2_integer;
	for (int i = longer.length() - min_length - 1; i >= 0; --i) {
		if ((char)(longer[i] + carry) > '9') {
			out_integer.push_back((char)(longer[i] + carry - 10));
			carry = 1;
		} else {
			out_integer.push_back((char)(longer[i] + carry));
			carry = 0; //��ֵһ�κ�����Ϊ0
		}
	}
	//�и�λ���ֵĻ�����λ����0
	if (carry != 0)
		out_integer.push_back('1');
	std::reverse(out_integer.begin(), out_integer.end());
	return out_integer;
}

std::string AddNumsOfString(std::string&num1, std::string&num2) {
	if (!checkValid(num1, num2))
		return "error";
	bool num1Longer = num1.length() > num2.length();
	int maxLen = num1Longer ? num1.length() : num2.length();
	std::string res = "";
	if (num1Longer) {
		num2 = std::string(num1.length() - num2.length(), '0') + num2;
	} else {
		num1 = std::string(num2.length() - num1.length(), '0') + num1;
	}
	int carry = 0;
	for (int i = maxLen - 1; i >= 0; --i) {
		int cur = num1[i] + num2[i] - '0' - '0' + carry;
		carry = 0;
		if (cur >= 10) {
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


int main() {
	std::string str1, str2;
	while (std::cin >> str1 >> str2) {
		std::cout << AddNumsOfString(str1, str2) << std::endl;
	}
	return 0;
}