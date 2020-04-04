/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
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

//我做的，不对
//比如当中序是321的时候
class Solution
{
public:

	TreeNode *pre = nullptr;
	TreeNode *bigger = nullptr;
	void recoverTree(TreeNode *root)
	{
		if (root == nullptr)
			return;

		if (root->left == nullptr && root->right == nullptr)
			return;
		if (root->left == nullptr && root->val > root->right->val)
			std::swap(root->val, root->right->val);
		if (root->right == nullptr && root->val < root->left->val)
			std::swap(root->val, root->left->val);


		inOrderTraverse1(root);
	}

	void inOrderTraverse(TreeNode * root)
	{
		if (root == nullptr)
			return;
		inOrderTraverse(root->left);
		if (pre == nullptr)
			pre = root;
		else
		{
			if (pre->val > root->val) //我这里是找到了一个大的就去交换，应该要同时找到一对大的小的才进行交换 
			{
				if (pre->val - root->val == 1)
				{
					std::swap(pre->val, root->val);
					return;
				}
				else
				{
					if (bigger == nullptr)
						bigger = root;
					else
					{
						std::swap(bigger->val, root->val);
						return;
					}
				}
			}
			pre = root;
		}
		inOrderTraverse(root->right);
	}

	//还是错的，比如 1,0这种两个的需要单独处理， 123也不行，我这个方法需要至少出现两次逆序，其实不用
	//就看下面的解法，其实意思到了，没coding对
	void inOrderTraverse1(TreeNode * root)
	{
		if (root == nullptr)
			return;
		inOrderTraverse(root->left);
		if (pre == nullptr)
		{
			pre = root;
			inOrderTraverse(root->right);
			return;
		}
		if (pre->val > root->val) //我这里是找到了一个大的就去交换，应该要同时找到一对大的小的才进行交换 
		{
			if (bigger == nullptr)
				bigger = pre;
			else
				std::swap(bigger->val, root->val);
		}
		pre = root;
		inOrderTraverse(root->right);
	}
};


//牛客看到的正确的，这样能够避免我的错误
//比如中序321的时候，firstBigger是第一个出现前比后大的大者
//lastSmaller是最后一个前比后大的小者
//交换这两个就一定正确
//例子(都是中序):
//(1) 2 1 3 4 5
//(2) 1 5 3 4 2
//(3) 5 2 3 4 1
//为了空间复杂度更好，应该用morris 遍历
//就是要找两个点，一个是偏大的，一个是偏小了的
class Solution1
{
public:
	TreeNode *pre, *firstBigger, *lastSmaller;
	void recoverTree(TreeNode *root)
	{
		pre = firstBigger = lastSmaller = NULL;
		dfs(root);
		if (firstBigger&&lastSmaller) swap(firstBigger->val, lastSmaller->val);
	}
	void dfs(TreeNode *root)
	{
		if (!root) return;
		dfs(root->left);
		if (pre && pre->val > root->val)
		{
			if (!firstBigger) //偏大的找第一个，出现了就再也不更改
				firstBigger = pre; 
			lastSmaller = root;
		}
		pre = root;
		dfs(root->right);
	}
};

void test1()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution s;
	s.recoverTree(root);

	PrintTree(root);
}

void test2()
{
	TreeNode * root = new TreeNode(2);
	root->left = new TreeNode(3);
	root->right = new TreeNode(1);
	Solution1 s;
	s.recoverTree(root);

	PrintTree(root);
}

int main()
{
	test1();
	test2();


	return 0;
}