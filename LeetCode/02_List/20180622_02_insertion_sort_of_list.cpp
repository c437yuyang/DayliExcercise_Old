/*
Sort a linked list using insertion sort.
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
	ListNode *insertionSortList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *newHead = head;
		head = head->next; //当前指针先移向下一个
		newHead->next = nullptr; //已排序的next=nullptr
		while (head != nullptr)
		{
			ListNode *headNextSave = head->next;
			ListNode *newCur = newHead;
			ListNode *prev = nullptr;
			while (newCur != nullptr && head->val > newCur->val)
			{
				prev = newCur;
				newCur = newCur->next;
			}
			if (prev == nullptr)//当前数就是最小数
			{
				ListNode *newHeadSave = newHead;
				newHead = head; //指向当前数
				newHead->next = newHeadSave; //连接
			}
			else
			{
				ListNode *prevNextSave = prev->next;
				prev->next = head;
				prev->next->next = prevNextSave;
			}
			head = headNextSave;
		}
		return newHead;
	}
};

int main()
{
	ListNode * head = new ListNode(10);
	head->next = new ListNode(5);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(6);
	head->next->next->next->next = new ListNode(9);
	head->next->next->next->next->next = new ListNode(2);
	head->next->next->next->next->next->next = new ListNode(4);

	PrintList(head);

	Solution s;
	head = s.insertionSortList(head);
	PrintList(head);
	DestroyList(head);

	return 0;
}