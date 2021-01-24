#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>


//用迭代器删除vector中偶数的元素
void delete_even(std::vector<int> &v)
{
	if (v.size() == 0)
		return;

	//auto it = v.begin();

	//while (it != v.end())
	//{
	//	if (!(*it & 1))
	//		it = v.erase(it);
	//	else
	//		++it;
	//}

	//简单一点可以直接:
	auto iter = std::remove_if(v.begin(), v.end(), [](int val)
	{
		if ((val & 1) == 0) //注意优先级
			return true;
		else return false;
	});

	v.erase(iter, v.end());

}

int main()
{
	int arr[] = { 8,5,9,7,1,8,7,10,3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::vector<int> v(arr, arr + n);
	std::for_each(v.begin(), v.end(), [](int val) { std::cout << val << " "; });
	std::cout << std::endl;
	delete_even(v);
	std::for_each(v.begin(), v.end(), [](int val) { std::cout << val << " "; });
	std::cout << std::endl;

	return 0;
}