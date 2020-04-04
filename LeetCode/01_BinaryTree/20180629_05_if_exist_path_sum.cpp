/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree andsum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path5->4->11->2which sum is 22.
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
    bool finded = false;
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==nullptr)
            return false;
        pathSumProcess(root,0,sum);
        return finded;
    }
    
    void pathSumProcess(TreeNode *root,int curSum,int sum){
        if(finded)
            return;
        curSum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(curSum == sum){
                finded = true;
            }
            return;
        }
        if(root->left!=nullptr)
            pathSumProcess(root->left,curSum,sum);
        if(root->right!=nullptr)
            pathSumProcess(root->right,curSum,sum);
    }
    
};