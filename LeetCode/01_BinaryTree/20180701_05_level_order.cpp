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
    vector<vector<int> > levelOrder(TreeNode *root) {
        if(root == nullptr)
            return {};
        vector<vector<int> > res;
        std::queue<TreeNode *> queue;
        queue.push(root);
        while(!queue.empty()){
            size_t n = queue.size();
            std::vector<int> level;
            for(size_t i=0;i<n;++i){
                auto cur = queue.front();
                queue.pop();
                if(cur->left != nullptr)
                    queue.push(cur->left);
                if(cur->right != nullptr)
                    queue.push(cur->right);
                level.push_back(cur->val);
            }
            res.push_back(level);
        }
        return res;
    }
};