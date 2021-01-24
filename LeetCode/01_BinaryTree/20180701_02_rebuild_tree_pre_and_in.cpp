class Solution
{
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		if (preorder.empty() || inorder.empty())
			return nullptr;
		return buildTreeProcess(&preorder[0], &inorder[0],
			0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* buildTreeProcess(int *preArr, int *inArr, int preStart, int preEnd, int inStart, int inEnd)
	{
		if (preArr == nullptr)
			return nullptr;
		if (preStart == preEnd)
		{
			return new TreeNode(preArr[preEnd]);
		}
		int rootVal = preArr[preStart];
		int inRootPos = inStart;
		for (; inRootPos <= inEnd && inArr[inRootPos] != rootVal; ++inRootPos);
		TreeNode *root = new TreeNode(rootVal);
		if (inRootPos - inStart > 0) //有左边
			root->left = buildTreeProcess(preArr, inArr, preStart + 1, preStart + inRootPos - inStart, inStart, inRootPos - 1);
		if (inEnd - inRootPos > 0) //有右边
			root->right = buildTreeProcess(preArr, inArr, preStart + inRootPos - inStart + 1, preEnd, inRootPos + 1, inEnd);
		return root;
	}

};