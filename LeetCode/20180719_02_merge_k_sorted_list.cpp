/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
	ListNode *mergeKLists(std::vector<ListNode *> &lists)
	{
		if (lists.empty())
			return nullptr;
		if (lists.size() == 1)
			return lists[0];

		ListNode *newHead = nullptr;
		ListNode *cur = nullptr;
		while (!checkEmpty(lists))
		{
			if (newHead == nullptr)
			{
				newHead = getMinListNode(lists);
				cur = newHead;
			}
			else
			{
				cur->next = getMinListNode(lists);
				cur = cur->next;
			}
		}
		return newHead;
	}

	ListNode *getMinListNode(std::vector<ListNode *> &lists)
	{
		ListNode * minNode = nullptr;
		size_t minIdx = -1;
		for (size_t i = 0; i < lists.size(); ++i)
		{
			if (minNode == nullptr && lists[i] != nullptr)
			{
				minNode = lists[i];
				minIdx = i;
			}
			else
			{
				if (lists[i] == nullptr)
					continue;
				if (minNode->val > lists[i]->val)
				{
					minNode = lists[i];
					minIdx = i;
				}
			}
		}

		lists[minIdx] = lists[minIdx]->next;
		return minNode;
	}

	bool checkEmpty(const std::vector<ListNode *> &lists)
	{
		for (size_t i = 0; i < lists.size(); ++i)
		{
			if (lists[i] != nullptr)
				return false;
		}
		return true;
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
	ListNode*head1 = new ListNode(1);
	head1->next = new ListNode(3);
	head1->next->next = new ListNode(5);
	head1->next->next->next = new ListNode(7);

	ListNode*head2 = new ListNode(2);
	head2->next = new ListNode(4);
	head2->next->next = new ListNode(6);
	std::vector<ListNode*> v = { head1,head2 };
	//head->next->next->next->next = new ListNode(5);
	Solution s;
	auto res = s.mergeKLists(v);
	PrintList(res);
}

