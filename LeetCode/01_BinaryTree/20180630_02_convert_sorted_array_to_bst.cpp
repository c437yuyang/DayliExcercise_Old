/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;




class Solution
{
public:
	TreeNode *sortedArrayToBST(std::vector<int> &num)
	{
		if (num.empty())
			return nullptr;
		return sortedArrayToBSTProcess(num, 0, num.size() - 1);
	}

	TreeNode* sortedArrayToBSTProcess(std::vector<int> &num, int i, int j)
	{
		if (i == j)
			return new TreeNode(num[i]);
		int mid = (int)ceil((i + j) / 2.0); //取下中位数
		TreeNode *root = new TreeNode(num[mid]);

		//左边一定有,因为是下中位数
		root->left = sortedArrayToBSTProcess(num, i, mid - 1);
		if (mid < j) //有右边
			root->right = sortedArrayToBSTProcess(num, mid + 1, j);
		return root;
	}

};

int main()
{
	Solution s;

	std::vector<int> num = { 1 };
	PrintTree(s.sortedArrayToBST(num));

	num.push_back(2);
	PrintTree(s.sortedArrayToBST(num));

	num.push_back(3);
	PrintTree(s.sortedArrayToBST(num));

	num.push_back(4);
	PrintTree(s.sortedArrayToBST(num));

	num.push_back(5);
	PrintTree(s.sortedArrayToBST(num));

	return 0;
}