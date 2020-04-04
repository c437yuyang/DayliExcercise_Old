/*
Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path1->2->3which represents the number123.

Find the total sum of all root-to-leaf numbers.

For example,

1
/ \
2   3

The root-to-leaf path1->2represents the number12.
The root-to-leaf path1->3represents the number13.

Return the sum = 12 + 13 =25.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <numeric>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    int sumNumbers(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        std::vector<long long> v;
        traverseTree(root, 0, v);
        long long res = std::accumulate(v.begin(), v.end(), 0);
        return res;
    }

    void traverseTree(TreeNode *root, long long cur, std::vector<long long> &v)
    {
        cur = cur * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            v.push_back(cur);
            return;
        }

        if (root->left != nullptr)
            traverseTree(root->left, cur, v);
        if (root->right != nullptr)
            traverseTree(root->right, cur, v);
    }
};

void test1()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    assert(Solution().sumNumbers(root) == 25);
}

void test2()
{
    TreeNode *root = nullptr;

    assert(Solution().sumNumbers(root) == 0);
}

void test3()
{
    TreeNode *root = new TreeNode(3);

    assert(Solution().sumNumbers(root) == 3);
}

int main()
{
    test1();
    test3();
    test2();
    return 0;
}