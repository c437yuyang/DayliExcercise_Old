
/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


//长度不同时也需要考虑如{1,1}{9}->{0,2}

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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode *head = nullptr;
		ListNode *cur = nullptr;
		//ListNode *cur = 
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr) //需要考虑长度不一样
		{
			int val1 = 0, val2 = 0;
			if (l1 != nullptr)
			{
				val1 = l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				val2 = l2->val;
				l2 = l2->next;
			}

			int val = val1 + val2 + carry;
			carry = 0;
			if (val >= 10)
			{
				val -= 10;
				carry = 1;
			}
			if (head == nullptr) //起始位置单独处理
			{
				cur = new ListNode(val);
				head = cur;
			}
			else
			{
				cur->next = new ListNode(val);
				cur = cur->next;
			}
		}

		if (carry > 0) //最后还有进位
		{
			cur->next = new ListNode(carry);
			cur = cur->next;
			cur->next = nullptr;
		}
		else
		{
			cur->next = nullptr;
		}

		return head;
	}
};



int main()
{
	ListNode *head1 = new ListNode(2);
	head1->next = new ListNode(4);
	head1->next->next = new ListNode(3);

	ListNode *head2 = new ListNode(5);
	head2->next = new ListNode(6);
	head2->next->next = new ListNode(4);

	Solution S;
	auto head = S.addTwoNumbers(head1, head2);



	yxp_utility::PrintList(head);

	return 0;
}