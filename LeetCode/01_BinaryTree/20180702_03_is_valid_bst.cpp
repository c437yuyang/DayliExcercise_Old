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
	TreeNode *pre = nullptr;
	bool valid = true;
	bool isValidBST(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		isValidBSTProcess(root);
		return valid;
	}
	//中序遍历就是
	void isValidBSTProcess(TreeNode*root)
	{
		if (!valid || root == nullptr)
			return;
		isValidBSTProcess(root->left);
		if (pre != nullptr && pre->val >= root->val)
		{
			valid = false;
			return;
		}
		pre = root;
		isValidBSTProcess(root->right);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(1);
	Solution s;
	auto b = s.isValidBST(root);

	return 0;
}