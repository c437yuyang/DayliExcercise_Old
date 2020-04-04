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

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
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
	//head->next->next->next->next = new ListNode(5);
	Solution s;
	auto res = s.swapPairs(head);
	PrintList(res);

    return 0;
}

