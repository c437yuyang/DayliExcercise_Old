/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int height = 0;
        return check(root, height);
    }

    bool check(TreeNode *root, int &height)
    {
        if (root == nullptr)
        {
            height = 0;
            return true;
        }
        int leftH, rightH;
        if (!check(root->left, leftH))
        {
            return false;
        }
        if (!check(root->right, rightH))
        {
            return false;
        }
        if (abs(leftH - rightH) > 1)
            return false;
        height = std::max(leftH, rightH) + 1;
        return true;
    }
};