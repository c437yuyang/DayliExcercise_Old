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
//注意，相同的全部都会被删掉，比如1->1  返回空链表
//这里的做法是针对没排序的链表也可以,因为用了map来记录
//如果是排序了的链表，可以直接处理
class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		std::unordered_map<int, int> map;
		ListNode * cur = head;
		while (cur != nullptr)
		{
			++map[cur->val];
			cur = cur->next;
		}
		cur = head;
		ListNode *pre = nullptr;
		while (cur != nullptr)
		{
			ListNode *curNextSave = cur->next;
			if (map[cur->val] > 1)
			{
				if (cur == head)
					head = curNextSave;
				else
					pre->next = curNextSave;
				delete cur; //OJ不能去delete
			}
			else
				pre = cur;
			cur = curNextSave;
		}
		return head;
	}
};
int main()
{

	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(1);

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