#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
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

#pragma region 上中位数版本
//class Solution
//{
//	//上中位数的情况，1->2 ,重建为1,#,2
//public:
//	TreeNode *sortedListToBST(ListNode *head)
//	{
//		return sortedListToBSTProcess(head);
//	}
//
//	TreeNode * sortedListToBSTProcess(ListNode *head)
//	{
//		if (head == nullptr) //0节点
//			return nullptr;
//		if (head->next == nullptr) //1节点
//			return new TreeNode(head->val);
//
//
//		ListNode *midPre = findMidPre(head);
//		ListNode *mid = findMid(head);
//		ListNode *right = mid->next;
//		TreeNode *root = new TreeNode(mid->val);
//		if (midPre == nullptr) //没有前半部分了
//		{
//			root->right = sortedListToBSTProcess(right);
//			return root;
//		}
//		//有左子树
//		midPre->next = nullptr;//断开连接
//		root->left = sortedListToBSTProcess(head);
//		root->right = sortedListToBSTProcess(right);
//		return root;
//	}
//
//	//找到中间节点的前一个
//	ListNode *findMidPre(ListNode *head)
//	{
//		if (head == nullptr || head->next == nullptr)
//		{
//			return nullptr; //只有一个节点，应该充当右孩子
//		}
//		ListNode *fast = head;
//		ListNode *slow = head;
//		ListNode *prev = nullptr;
//		while (fast->next != nullptr && fast->next->next != nullptr)
//		{
//			fast = fast->next->next;
//			prev = slow;
//			slow = slow->next;
//		}
//		return prev;
//	}
//
//	ListNode *findMid(ListNode *head)
//	{
//		if (head == nullptr || head->next == nullptr)
//		{
//			return head;
//		}
//		ListNode *fast = head;
//		ListNode *slow = head;
//		while (fast->next != nullptr && fast->next->next != nullptr)
//		{
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//		return slow;
//	}
//};
#pragma endregion

//OJ是下中位数用的
class Solution
{
	//下中位数的情况，1->2 重建为 2,1
public:
	TreeNode *sortedListToBST(ListNode *head)
	{
		return sortedListToBSTProcess(head);
	}
	//思路就是每次找到中间节点充当root,对左右子树递归
	TreeNode * sortedListToBSTProcess(ListNode *head)
	{
		if (head == nullptr) //0节点
			return nullptr;
		if (head->next == nullptr) //1节点
			return new TreeNode(head->val);

		ListNode *midPre = findMidPre(head);
		ListNode *mid = findMid(head);
		ListNode *right = mid->next;
		TreeNode *root = new TreeNode(mid->val);
		if (midPre != nullptr) //没有前半部分了
		{
			//有左子树
			midPre->next = nullptr;//断开连接
			root->left = sortedListToBSTProcess(head);
		}
		if (right != nullptr)
			root->right = sortedListToBSTProcess(right);
		return root;
	}

	//找到中间节点的前一个
	ListNode *findMidPre(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *prev = nullptr;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		return prev;
	}

	ListNode *findMid(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return nullptr; //下中位数的时候只有一个节点就返回nullptr,一个节点是用去充当上半部分的
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

//牛客看到的，更简单
class Solution
{
public:
	TreeNode *sortedListToBST(ListNode *head)
	{
		return BST(head, NULL);
	}
	TreeNode *BST(ListNode *head, ListNode *tail)
	{
		if (head == tail) //这样就不用断开链表了,头尾相等，就不用再继续重建了
			return NULL;
		ListNode *s = head;
		ListNode *f = head;
		while (f != tail && f->next != tail)
		{
			s = s->next;
			f = f->next->next;
		}
		TreeNode *root = new TreeNode(s->val);
		root->left = BST(head, s);
		root->right = BST(s->next, tail);
		return root;
	}
};


int main()
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);

	auto headCopy = CopyList(head);
	TreeNode * root = Solution().sortedListToBST(headCopy);
	PrintTree(root);

	head->next->next = new ListNode(3);
	headCopy = CopyList(head);
	root = Solution().sortedListToBST(headCopy);
	PrintTree(root);

	head->next->next->next = new ListNode(4);
	headCopy = CopyList(head);
	root = Solution().sortedListToBST(headCopy);
	PrintTree(root);

	head->next->next->next->next = new ListNode(5);
	headCopy = CopyList(head);
	root = Solution().sortedListToBST(headCopy);
	PrintTree(root);

	head->next->next->next->next->next = new ListNode(6);
	headCopy = CopyList(head);
	root = Solution().sortedListToBST(headCopy);
	PrintTree(root);

	return 0;
}