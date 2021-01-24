/*
Given a binary tree, return the bottom-up level order traversal 
of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree{3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as"{1,2,3,#,#,4,#,#,5}".
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if(root==nullptr)
            return {};
        std::vector<std::vector<int> > res;
        std::queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty())
        {
            size_t n = queue.size();
            std::vector<int> curLevel;
            for(size_t i=0;i<n;++i){
                TreeNode*cur = queue.front();
                queue.pop();
                if(cur->left!=nullptr){
                    queue.push(cur->left);
                }
                if(cur->right!=nullptr){
                    queue.push(cur->right);
                }
                curLevel.push_back(cur->val);
            }
            res.insert(res.begin(),curLevel);
        }
        return res;
        
    }
};