/*
Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set toNULL.
Initially, all next pointers are set toNULL.
Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

1
/  \
2    3
/ \  / \
4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <queue>
struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
  public:
	//就是层序遍历
	void connect1(TreeLinkNode *root)
	{
		if (root == nullptr)
			return;
		std::queue<TreeLinkNode *> queue;
		queue.push(root);
		TreeLinkNode *prev = nullptr;
		while (!queue.empty())
		{
			size_t n = queue.size();
			for (size_t i = 0; i < n; ++i) //到数了就会结束循环
			{
				auto cur = queue.front();
				queue.pop();

				if (cur->left != nullptr)
					queue.push(cur->left);
				if (cur->right != nullptr)
					queue.push(cur->right);
				if (i == 0)
				{
					prev = cur;
					continue;
				}
				if (i == n - 1) //最后一个
					cur->next = nullptr;
				prev->next = cur; //不是第一个就要进行next串联
				prev = cur;
			}
		}
	}

	//O(1)的方法
	//其实就是，在每一层，先串联当前节点左右孩子，然后往右(找next如果有的话)，然后往下(找孩子)
	void connect(TreeLinkNode *root)
	{
		if (root == nullptr)
			return;

		int idx = 0;
		auto cur = root;
		TreeLinkNode *q = cur;
		while (cur->left != nullptr)
		{
			q = cur; //开始串联当前这一层
			while (q)
			{
				q->left->next = q->right;
				if (q->next)						//还有右边
					q->right->next = q->next->left; //连接5->6那种
				q = q->next;						//如果往右还有，就往右，否则走到null结束while
			}
			cur = cur->left; //往下走
		}
	}
};

int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);

	Solution s;
	s.connect2_1(root);

	return 0;
}