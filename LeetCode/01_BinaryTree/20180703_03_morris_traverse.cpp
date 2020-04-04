class Solution
{
  public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		if (root == nullptr)
			return {};
		std::vector<int> res;
		TreeNode *cur = root;
		while (cur != nullptr)
		{
			if (cur->left != nullptr)
			{
				//找左孩子的最右节点
				TreeNode *mostRight = findMostRight(cur->left, cur);
				if (mostRight->right == nullptr)
				{
					mostRight->right = cur;
					cur = cur->left;
				}
				else
				{
					res.push_back(cur->val); //有左孩子的节点第二次来到的时候打印
					mostRight->right = nullptr;
					cur = cur->right;
				}
			}
			else
			{
				res.push_back(cur->val); //没有左孩子的节点只会到达一次，因此第一次就打印
				cur = cur->right;
			}
		}
		return res;
	}

	TreeNode *findMostRight(TreeNode *node, TreeNode *cur)
	{
		while (node->right != nullptr && node->right != cur) //注意，一定要判断一下不能回到自己!!!
			node = node->right;
		return node;
	}
};