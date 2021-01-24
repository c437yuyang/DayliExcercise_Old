#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:
	std::vector<int> preorderTraversal(TreeNode *root)
	{
		if (root == nullptr)
			return{};
		std::stack<TreeNode*> stack;
		std::vector<int> res;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode* cur = stack.top();
			res.push_back(cur->val);
			stack.pop();
			if (cur->right != nullptr)
				stack.push(cur->right);
			if (cur->left != nullptr)
				stack.push(cur->left);
		}
		return res;
	}
};


int main()
{
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution s;
	ArrayHelper::printArr(s.preorderTraversal(root));

	return 0;
}