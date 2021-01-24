#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
#include <unordered_set>
#include <unordered_map>
using namespace yxp_utility;
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given1->2->3->3->4->4->5, return1->2->5.
Given1->1->1->2->3, return2->3.
*/

class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *cur = head;
		ListNode *pre = nullptr;
		while (cur != nullptr && cur->next != nullptr)
		{
			if (cur->val != cur->next->val)
			{
				pre = cur;
				cur = cur->next;
			}
			else
			{
				ListNode *tmp = cur; //从cur开始删
				while (tmp->next != nullptr && tmp->val == tmp->next->val)
				{
					auto nextSave = tmp->next;
					delete tmp;
					tmp = nextSave;
				}
				cur = tmp->next;
				delete tmp; //删除尾巴的
				if (pre != nullptr) 
					pre->next = cur;
				else //从头开始删的
					head = cur;
			}
		}
		return head;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);

	Solution s;

	auto i = s.deleteDuplicates(head);
	PrintList(i);

	ListNode *head1 = new ListNode(1);
	head1->next = new ListNode(1);
	i = s.deleteDuplicates(head1);
	PrintList(i);

	head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(2);
	i = s.deleteDuplicates(head1);
	PrintList(i);

	return 0;
}