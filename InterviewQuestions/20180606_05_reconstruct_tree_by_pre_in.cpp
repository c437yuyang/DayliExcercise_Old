#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
using namespace std;

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
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		return reConstructProcess(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}

	TreeNode* reConstructProcess(vector<int>&pre, int pre_left, int pre_right,
		vector<int>&vin, int vin_left, int vin_right)
	{
		if (pre_left == pre_right && vin_left == vin_right)
		{
			return new TreeNode(pre[pre_left]);
		}

		int root_val = pre[pre_left];
		auto root = new TreeNode(root_val);
		int root_offset = (std::find(vin.begin() + vin_left, vin.begin() + vin_right + 1, root_val)
			- vin.begin() - vin_left); //根据pre找到的root在in中的偏移量
		if (root_offset > 0) //有左子树
		{
			root->left = reConstructProcess(pre, pre_left + 1, pre_left + root_offset,
				vin, vin_left, vin_left + root_offset - 1);
		}
		if (vin_left + root_offset < vin_right)
		{
			root->right = reConstructProcess(pre, pre_left + root_offset + 1, pre_right,
				vin, vin_left + root_offset + 1, vin_right);
		}
		return root;
	}
};



int main()
{
	Solution s;
	auto root = s.reConstructBinaryTree(std::vector<int>{1, 2, 4, 7, 3, 5, 6, 8},
		std::vector<int>{4, 7, 2, 1, 5, 3, 8, 6});

	return 0;
}