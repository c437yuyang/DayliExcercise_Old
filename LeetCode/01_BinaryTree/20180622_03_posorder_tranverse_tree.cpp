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
	std::vector<int> postorderTraversal(TreeNode *root)
	{
		if (root == nullptr)
			return{};
		std::stack<TreeNode*> stack;
		std::stack<TreeNode*> stackReverse;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode * cur = stack.top();
			stackReverse.push(cur);
			stack.pop();
			if (cur->left != nullptr)
				stack.push(cur->left);
			if (cur->right != nullptr)
				stack.push(cur->right);
		}
		std::vector<int> res;
		res.reserve(stackReverse.size());
		while (!stackReverse.empty())
		{
			res.push_back(stackReverse.top()->val);
			stackReverse.pop();
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
	ArrayHelper::printArr(s.postorderTraversal(root));

	return 0;
}