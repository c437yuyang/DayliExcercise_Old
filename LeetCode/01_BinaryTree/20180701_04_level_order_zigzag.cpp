/*
Given a binary tree, return the zigzag curLevel order traversal of its nodes' values. (ie, from left to right, then right to left for the next curLevel and alternate between).

For example:
Given binary tree{3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag curLevel order traversal as:

[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int> > zigzagcurLevelOrder(TreeNode *root) {
        if(root == nullptr)
            return {};
        vector<vector<int> > res;
        std::queue<TreeNode *> queue;
        std::stack<TreeNode *> stack;
        bool left2Right = true;
        queue.push(root);
        while(!queue.empty()){
            size_t n = queue.size();
            std::vector<int> curLevel;
            for(size_t i=0;i<n;++i){
                auto cur = queue.front();
                queue.pop();
                if(cur->left != nullptr)
                    queue.push(cur->left);
                if(cur->right != nullptr)
                    queue.push(cur->right);
                if(!left2Right){ //如果是从右到左的，就先压栈，再pop出来
                    stack.push(cur);
                }else{
                    curLevel.push_back(cur->val);
                }
            }
            if(!left2Right){
                while(!stack.empty()){
                    auto tmp = stack.top();
                    stack.pop();
                    curLevel.push_back(tmp->val);
                }
            }
            res.push_back(curLevel);
            left2Right = !left2Right;
        }
        return res;
    }
    
    
    
    
};