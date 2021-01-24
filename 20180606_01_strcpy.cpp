#include <iostream>
char *myStrcpy(char *dst, const char* src)
{
	if (dst == nullptr)
		throw std::exception("invalid dst");
	if (src == nullptr)
		throw new std::exception("invalid source");

	if (src == dst)
		return dst;

	char *dst_cur = dst;
	const char *src_cur = src;
	if (src < dst)
	{
		int len = 0;
		while (*src_cur++ != '\0')
			++len;
		*(dst + len) = '\0';
		while (len--)
			*(dst_cur + len) = *(src + len);
	}
	else
	{
		while (*src_cur != '\0')
			*(dst_cur++) = *(src_cur++);
		*dst_cur = '\0';
	}

	return dst;
}


int main()
{
	const char *str1 = "abcde";
	char str2[6];

	myStrcpy(str2, str1);
	std::cout << str2 << std::endl;


	char str3[6];
	const char * str4 = "abcde";
	myStrcpy(str3, str4); //是没有验证到第一种if情况的这样
	std::cout << str3 << std::endl;

	char *str5 = new char[6];
	strcpy_s(str5, 6, "abcde");

	char *str6 = new char[6];
	myStrcpy(str6, str5);
	std::cout << str6 << std::endl;

	delete[] str5;
	delete[] str6;

	return 0;
}