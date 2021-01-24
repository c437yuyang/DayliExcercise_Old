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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		if (postorder.empty() || inorder.empty())
			return nullptr;
		return buildTreeProcess(&postorder[0], &inorder[0],
			0, postorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* buildTreeProcess(int *posArr, int *inArr, int posStart, int posEnd, int inStart, int inEnd)
	{
		if (posStart == posEnd)
			return new TreeNode(posArr[posEnd]);

		int rootVal = posArr[posEnd];
		int inRootPos = inStart;
		for (; inRootPos <= inEnd && inArr[inRootPos] != rootVal; ++inRootPos);
		TreeNode *root = new TreeNode(rootVal);
		if (inRootPos - inStart > 0) //有左边
			root->left = buildTreeProcess(posArr, inArr, posStart, posStart + inRootPos - inStart - 1
				, inStart, inRootPos - 1);
		if (inEnd - inRootPos > 0) //有右边
			root->right = buildTreeProcess(posArr, inArr, posStart + inRootPos -inStart,
				posEnd - 1, inRootPos + 1, inEnd);
		return root;
	}

};