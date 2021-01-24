/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution
{
  public:
    // bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    // {
    //     if(pRoot2 == nullptr || pRoot1 == nullptr)
    //         return false;
    //     bool res = false;
    //     if(pRoot1->val == pRoot2->val)
    //     {
    //         res = IsSameTree(pRoot1,pRoot2);
    //         if(res)
    //             return res;
    //     }//不能有else,上面可能失败
    //     res = HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    //     return res;
    // }

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == nullptr || pRoot1 == nullptr)
            return false;
        return IsSameTree(pRoot1, pRoot2) || //利用短路极值进行的简化
               HasSubtree(pRoot1->left, pRoot2) ||
               HasSubtree(pRoot1->right, pRoot2);
    
    }

    bool IsSameTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return IsSameTree(pRoot1->left, pRoot2->left) && IsSameTree(pRoot1->right, pRoot2->right);
    }
};