/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list:1->2->3->4->5

For k = 2, you should return:2->1->4->3->5

For k = 3, you should return:3->2->1->4->5
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		if (head == nullptr || head->next == nullptr || k <= 1)
			return head;

		ListNode *cur = head, *curSpanHead = head, *newHead = nullptr;
		int cnt = 0;
		ListNode*preSpanTail = nullptr;
		while (cur != nullptr)
		{
			++cnt;
			ListNode *nextSave = cur->next;
			if (cnt % k == 0)//一个区间翻转一次
			{
				cur->next = nullptr; //当前区间结尾next置为null,进行reverse
				auto newSpan = reverseList(curSpanHead);
				if (preSpanTail != nullptr)
					preSpanTail->next = newSpan.first; //连接前一个区间的尾和当前区间的头
				if (newHead == nullptr)
					newHead = newSpan.first; //设置返回的头结点
				newSpan.second->next = nextSave;//重新连接下一个区间
				preSpanTail = newSpan.second; //赋值
				curSpanHead = nextSave;
			}
			cur = nextSave;
		}
		return newHead == nullptr ? head : newHead; //有可能一次都没翻转，就返回原head
	}

	//翻转链表，返回头尾
	std::pair<ListNode *, ListNode *>reverseList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return{ head,head };

		ListNode *cur = head, *pre = nullptr;
		ListNode *newTail = nullptr;
		while (cur != nullptr)
		{
			ListNode *nextSave = cur->next;
			if (pre == nullptr)
				newTail = cur;
			cur->next = pre;
			pre = cur;
			cur = nextSave;
		}
		return{ pre,newTail };
	}
};

//牛客看到的这个版本还不错,递归实现的
class Solution
{
public:
	/// 参考翻转pairs，翻转x~x+(k-1）之间的节点， x->next = reverseKGroup(x+k,k)
	ListNode* reverse(ListNode *first, ListNode *last)
	{
		ListNode *pre = nullptr;
		while (first != last)
		{
			ListNode *temp = first->next;
			first->next = pre;
			pre = first;
			first = temp;
		}
		return pre;
	}
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		if (!head)
			return nullptr;
		ListNode *node = head;
		for (int i = 0; i < k; i++)
		{
			if (!node)
				return head;
			node = node->next;
		}
		ListNode *newHead = reverse(head, node);
		head->next = reverseKGroup(node, k);
		return newHead;
	}
};

void PrintList(ListNode *head)
{
	while (head != nullptr)
	{
		std::cout << head->val << " ";
		head = head->next;;
	}
	std::cout << std::endl;
}

int main()
{
	ListNode*head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution s;
	auto res = s.reverseKGroup(head, 4);
	PrintList(res);
}