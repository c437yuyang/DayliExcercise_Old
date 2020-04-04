/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given1->2->3->4->5->NULLand k =2,
return4->5->1->2->3->NULL.
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
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution
{
  public:
	ListNode *rotateRight(ListNode *head, int k)
	{
		if (head == nullptr || head->next == nullptr || k < 1)
			return head;
		//先找到倒数第k个节点,lastK，倒数第k+1个节点lastK_1
		//然后让head = lastK,oldTail->next=oldHead,lastK_1->next = nullptr
		ListNode *cur = head;
		ListNode *tail = nullptr;
		int len = 0;
		while (cur != nullptr)
		{
			++len;
			cur = cur->next;
		}
		if (k > len)
			k %= len; //k大于len的话取模
		if (k < 1)
			return head;

		cur = head;
		while (cur != nullptr)
		{
			if (cur->next == nullptr)
				tail = cur;
			cur = cur->next;
			--k;
		}

		if (k >= 0) //k>0不存在倒数第k个,k==0，翻转第一个不用翻转
			return head;
		cur = head;
		ListNode *lastK = nullptr;
		ListNode *lastK_1 = nullptr;

		while (k < 0)
		{
			if (k == -1)
				lastK_1 = cur;
			++k;
			cur = cur->next;
		}
		lastK = cur;
		ListNode *newHead = lastK;
		tail->next = head;
		lastK_1->next = nullptr;
		return newHead;
	}
};

void test1()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution s;
	head = s.rotateRight(head, 10);
	PrintList(head);
}

int main()
{
	test1();

	return 0;
}