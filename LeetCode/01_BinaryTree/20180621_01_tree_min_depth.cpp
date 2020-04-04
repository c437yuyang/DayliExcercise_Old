/*
Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

struct TreeNode
{
	int elem;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int val) :elem(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	int run(TreeNode *root)
	{
		if (root == nullptr)
			return 0; //一定要有，OJ判断直接就错误!!!
		int minDepth = std::numeric_limits<int>::max();
		getMinDepth(root, 1, minDepth);
		return minDepth;
	}

	void getMinDepth(TreeNode *root, int curLevel, int &minDepth)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			minDepth = std::min(curLevel, minDepth);
			return;
		}
		if (root->left != nullptr)
			getMinDepth(root->left, curLevel + 1, minDepth);
		if (root->right != nullptr)
			getMinDepth(root->right, curLevel + 1, minDepth);
	}
};

int main()
{
	Solution s;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	//root->right->right = new TreeNode(6);

	std::cout << s.run(root) << std::endl;
	return 0;
}