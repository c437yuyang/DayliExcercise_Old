/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree andsum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
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
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(root == nullptr)
            return {};
        vector<vector<int> > res;
        pathSumProcess(root,sum,0,std::vector<int>(),res);
        return res;
    }
    
    void pathSumProcess(TreeNode *root,int sum,int curSum,vector<int> curPath,vector<vector<int> > &res)
    {        
        curSum += root->val;
        curPath.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(curSum == sum)
                res.push_back(curPath);
            return;
        }
        if(root->left!=nullptr)
            pathSumProcess(root->left,sum,curSum,curPath,res);
        if(root->right!=nullptr)
            pathSumProcess(root->right,sum,curSum,curPath,res);
    }
    
};