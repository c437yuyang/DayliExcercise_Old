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
排序链表，删除重复节点，保留一个，1-2-2-3-3-5,得到1-2-3-5
*/


class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		//首先头部肯定不会被删掉
		ListNode *cur = head;
		ListNode *pre = nullptr;
		while (cur != nullptr)
		{
			if (pre != nullptr
				&& cur->val == pre->val)
			{
				auto nextSave = cur->next;
				delete cur;
				cur = nextSave;
				pre->next = nextSave;
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}
		}
		pre->next = nullptr;
		return head;
	}

};

int main()
{

	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(3);

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