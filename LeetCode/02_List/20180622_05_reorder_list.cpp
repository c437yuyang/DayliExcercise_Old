/*
Given a singly linked list L: L 0→L 1→…→L n-1→L n,
reorder it to: L 0→L n →L 1→L n-1→L 2→L n-2→…

You must do this in-place without altering the nodes' values.

For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;
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
	/// <summary>
	/// 方法1，用了辅助数组
	/// </summary>
	/// <param name="head"></param>
	void reorderList1(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return;
		ListNode *tail = head;
		std::vector<ListNode*> list;
		while (tail != nullptr)
		{
			list.push_back(tail);
			tail = tail->next;
		}
		size_t headCur = 0;
		size_t tailCur = list.size() - 1;
		list[headCur++]->next = list[tailCur--];
		ListNode * tailSave = list[tailCur + 1];
		while (headCur < tailCur)
		{
			list[headCur - 1]->next->next = list[headCur];
			tailSave = list[tailCur];
			list[headCur++]->next = list[tailCur--];
		}

		if (!(list.size() & 1))
			list[headCur]->next = nullptr;
		else
		{
			tailSave->next = list[tailCur];
			list[tailCur]->next = nullptr;
		}
	}


	/// <summary>
	/// 方法2，快慢指针找中间节点，再把后面部分逆序，再merge
	/// </summary>
	/// <param name="head"></param>
	void reorderList2(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return;

		ListNode *mid = FindMid(head);
		ListNode *midAdd1 = mid->next;
		mid->next = nullptr;

		midAdd1 = ReverseList(midAdd1);
		head = MergeListNoOrder(head, midAdd1);
	}


	/// <summary>
	/// 快慢指针法找到中间节点
	/// </summary>
	ListNode *FindMid(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow; //最后slow停留的位置就是中间节点
	}

	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode *prev = nullptr;
		while (pHead != nullptr)
		{
			ListNode *next_save = pHead->next;
			pHead->next = prev;
			prev = pHead;
			pHead = next_save;
		}
		return prev;

	}

	/// <summary>
	/// 直接合并两个链表,head1优先
	/// </summary>
	/// <param name="head1"></param>
	/// <param name="head2"></param>
	/// <returns></returns>
	ListNode *MergeListNoOrder(ListNode *head1, ListNode*head2)
	{
		if (head1 == nullptr)
			return head2;
		if (head2 == nullptr)
			return head1;

		ListNode * newHead = head1;
		ListNode * newCur = newHead;
		head1 = head1->next;
		bool hea1First = false;
		while (head1 != nullptr && head2 != nullptr)
		{
			newCur->next = hea1First ? head1 : head2;
			if (hea1First)
				head1 = head1->next;
			else
				head2 = head2->next;
			newCur = newCur->next;
			hea1First = !hea1First;
		}
		while (head1 != nullptr)
		{
			newCur->next = head1;
			head1 = head1->next;
			newCur = newCur->next;
		}

		while (head2 != nullptr)
		{
			newCur->next = head2;
			head2 = head2->next;
			newCur = newCur->next;
		}
		return newHead;
	}

};


int main()
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	Solution s;
	//ArrayHelper::printArr(s.preorderTraversal(root));
	s.reorderList2(head);
	PrintList(head);

	return 0;
}