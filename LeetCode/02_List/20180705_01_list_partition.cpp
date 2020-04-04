/*

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 ="great":

great
/    \
gr    eat
/ \    /  \
g   r  e   at
/ \
a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node"gr"and swap its two children, it produces a scrambled string"rgeat".

rgeat
/    \
rg    eat
/ \    /  \
r   g  e   at
/ \
a   t
We say that"rgeat"is a scrambled string of"great".

Similarly, if we continue to swap the children of nodes"eat"and"at", it produces a scrambled string"rgtae".

rgtae
/    \
rg    tae
/ \    /  \
r   g  ta  e
/ \
t   a
We say that"rgtae"is a scrambled string of"great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given1->4->3->2->5->2and x = 3,
return1->2->2->4->3->5.
*/
class Solution
{
public:
	ListNode *partition(ListNode *head, int x)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode * cur = head;
		ListNode * lessCur = nullptr;
		ListNode * lessHead = nullptr;
		ListNode * biggerHead = nullptr;
		ListNode * biggerCur = nullptr;


		while (cur != nullptr)
		{
			ListNode * nextSave = cur->next;
			if (cur->val < x)
			{
				if (lessCur == nullptr)
				{
					lessCur = cur;
					lessHead = cur;
				}
				else
				{
					lessCur->next = cur;
					lessCur = lessCur->next;
				}
			}
			else
			{
				if (biggerHead == nullptr)
				{
					biggerHead = cur;
					biggerCur = cur;
				}
				else
				{
					biggerCur->next = cur;
					biggerCur = biggerCur->next;
				}
			}
			cur = cur->next;
		}

		if (biggerHead == nullptr)
			return lessHead; //这种情况下，lessCur就是原来的tail,因此本身也就指向了null
		if (lessHead == nullptr)
			return biggerHead; //同理
		biggerCur->next = nullptr;
		lessCur->next = biggerHead;
		return lessHead;
	}
};


int main()
{

	ListNode *head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);

	Solution s;

	auto i = s.partition(head, 1);
	PrintList(i);



	return 0;
}