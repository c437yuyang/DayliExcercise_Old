/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given1->2->3->4->5->NULL, m = 2 and n = 4,

return1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.


*/

#include <YXPUtility>
using namespace yxp_utility;
using namespace std;

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
	ListNode *reverseBetween(ListNode *head, int m, int n)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *cur = head;
		ListNode *revHeadPre = nullptr;
		ListNode *revTailNext = nullptr;
		ListNode *revHead = nullptr;
		ListNode *revTail = nullptr;
		int pos = 1;
		while (cur != nullptr)
		{
			if (pos == m - 1)
				revHeadPre = cur;
			if (pos == m)
				revHead = cur;
			if (pos == n)
				revTail = cur;
			if (pos == n + 1)
				revTailNext = cur;
			cur = cur->next;
			++pos;
		}
		if (revTailNext != nullptr)//断开尾部连接
			revTail->next = nullptr;

		revHead = ReverseList(revHead); //翻转链表

		if (revHeadPre != nullptr) //如果m不是第一个位置的话，就要把之前的再连接上
			revHeadPre->next = revHead;

		if (revTailNext != nullptr) //如果n不是最后一个位置的话,也要链接一下
		{
			ListNode *revCur = revHead;
			while (revCur->next != nullptr)
				revCur = revCur->next;
			revCur->next = revTailNext;
		}

		if (revHeadPre != nullptr)
			return head;
		else
			return revHead;
	}

	ListNode *ReverseList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *pre = nullptr;
		ListNode *cur = head;
		while (cur != nullptr)
		{
			ListNode *nextSave = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nextSave;
		}
		return pre;
	}


	//onepass解决的方法
	ListNode *reverseBetween1(ListNode *head, int m, int n)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode * dummy = new ListNode(0);
		dummy->next = head;
		int idx = 0;
		ListNode *cur = dummy;
		while (idx < m - 1) //找到m位置的前一个位置，准备开始翻转
		{
			cur = cur->next;
			++idx;
		}

		 reverseListOfLen(cur, n - m + 1);
		 return dummy->next;
	}

	void reverseListOfLen(ListNode *headPre, int len) //n是长度
	{
		int idx = 0;
		ListNode *pre = nullptr;
		ListNode *cur = headPre->next;
		ListNode *newTail = headPre->next; //当前的翻转区间的头就是反转后的尾
		while (idx < len)
		{
			ListNode *nextsave = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nextsave;
			++idx;
		}
		headPre->next = pre; //pre是当前翻转区间反转后的头部，完成串联
		newTail->next = cur; //因为当前cur存的就是不需要翻转的区间的下一个，因此让尾部的next指向cur完成尾巴的串联
	}

};

int main()
{
	
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	Solution s;
	ListNode *head1 = CopyList(head);
	head1 = s.reverseBetween(head1, 2, 4);
	PrintList(head1);

	head1 = CopyList(head);
	head1=s.reverseBetween(head1, 1, 4);
	PrintList(head1);

	head1 = CopyList(head);
	head1 = s.reverseBetween(head1, 2, 5);
	PrintList(head1);

	head1 = CopyList(head);
	head1= s.reverseBetween(head1, 1, 5);
	PrintList(head1);


	return 0;
}