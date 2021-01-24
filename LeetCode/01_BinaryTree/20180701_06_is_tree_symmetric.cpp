/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3
*/

#include <YXPUtility>
using namespace yxp_utility;
using namespace std;
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
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
	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		return isSymmetricProcess(root->left, root->right);
	}

	bool isSymmetricProcess(TreeNode*left, TreeNode*right)
	{
		if (left == nullptr && right == nullptr)
			return true;
		if (left == nullptr || right == nullptr)
			return false;
		return (left->val == right->val) &&
			isSymmetricProcess(left->left, right->right) &&
			isSymmetricProcess(left->right, right->left);
	}

};

int main() 
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);

	Solution s;
	auto var = s.isSymmetric(root);


	return 0;
}