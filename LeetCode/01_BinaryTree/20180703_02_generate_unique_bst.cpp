/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
	vector<TreeNode *> generateTrees(int n)
	{
		if (n == 0)
			return std::vector<TreeNode *>(1, nullptr);
		return generateTreesProcess(1, n);
	}

	vector<TreeNode *> generateTreesProcess(int start, int cnt)
	{
		if (cnt == 1)
		{
			TreeNode * root = new TreeNode(start);
			std::vector<TreeNode*> res;
			res.push_back(root);
			return res;
		}
		std::vector<TreeNode*> res;
		for (int i = start; i < start + cnt; ++i)
		{
			if (i == start) //选start作为root,则只可能生成右子树
			{
				std::vector<TreeNode*> rightChilds = generateTreesProcess(start + 1, cnt - 1);
				for (size_t j = 0; j < rightChilds.size(); ++j)
				{
					TreeNode *root = new TreeNode(i);
					res.push_back(root);
					res.back()->right = rightChilds[j];
				}
			}
			else if (i == start + cnt - 1)
			{
				std::vector<TreeNode*> leftChilds = generateTreesProcess(start, cnt - 1);
				for (size_t j = 0; j < leftChilds.size(); ++j)
				{
					TreeNode *root = new TreeNode(i);
					res.push_back(root);
					res.back()->left = leftChilds[j];
				}
			}
			else
			{
				std::vector<TreeNode*> rightChilds = generateTreesProcess(i + 1, start + cnt - i - 1); //注意这里cnt的取值!!!
				std::vector<TreeNode*> leftChilds = generateTreesProcess(start, i - start);
				for (size_t j = 0; j < leftChilds.size(); ++j)
				{
					for (size_t k = 0; k < rightChilds.size(); ++k)
					{
						TreeNode *root = new TreeNode(i);
						res.push_back(root);
						res.back()->left = leftChilds[j];
						res.back()->right = rightChilds[k];
					}
				}
			}

		}
		return res;
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(1);
	Solution s;
	auto b = s.generateTrees(4);

	return 0;
}