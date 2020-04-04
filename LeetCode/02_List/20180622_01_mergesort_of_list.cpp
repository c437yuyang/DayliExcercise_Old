/*
Sort a linked list in O(n log n) time using constant space complexity.

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;

class Solution
{
  public:
	ListNode *sortList(ListNode *head)
	{
		return mergeSortOfList(head);
	}

	ListNode *mergeSortOfList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *mid = findMid(head);
		ListNode *midAdd1 = mid->next;
		mid->next = nullptr;
		head = mergeSortOfList(head); //记住 现在排序完成是返回值来标志头，要取得返回值，不像数组排序是void!!!
		midAdd1 = mergeSortOfList(midAdd1);
		return mergeList(head, midAdd1);
	}

	ListNode *mergeList(ListNode *head1, ListNode *head2)
	{
		if (head1 == nullptr)
			return head2;
		if (head2 == nullptr)
			return head1;
		ListNode *newHead = nullptr;
		if (head1->val < head2->val)
		{
			newHead = head1;
			head1 = head1->next;
		}
		else
		{
			newHead = head2;
			head2 = head2->next;
		}
		ListNode *newCur = newHead;
		while (head1 != nullptr && head2 != nullptr)
		{
			if (head1->val < head2->val)
			{
				newCur->next = head1;
				head1 = head1->next;
			}
			else
			{
				newCur->next = head2;
				head2 = head2->next;
			}
			newCur = newCur->next;
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

	ListNode *findMid(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow; //最后slow停留的位置就是中间节点
	}
};

int main()
{
	ListNode *head = new ListNode(10);
	head->next = new ListNode(5);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(6);
	head->next->next->next->next = new ListNode(9);
	head->next->next->next->next->next = new ListNode(2);
	head->next->next->next->next->next->next = new ListNode(4);

	PrintList(head);

	Solution s;
	head = s.sortList(head);
	PrintList(head);
	DestroyList(head);
	return 0;
}