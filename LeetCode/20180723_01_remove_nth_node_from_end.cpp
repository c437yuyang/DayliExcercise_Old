#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <stack>
using namespace std;



struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int k)
	{
		ListNode * cur1 = head;
		ListNode * cur2 = head;
		while (k-- > 1)
			cur1 = cur1->next;
		ListNode * cur2Pre = nullptr;
		while (cur1->next != nullptr)
		{
			cur1 = cur1->next;
			cur2Pre = cur2;
			cur2 = cur2->next;
		}
		if (cur2Pre == nullptr) //删除的是头结点
			head = head->next;
		else
			cur2Pre->next = cur2->next;

		return head;
	}
};
int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution s;
	head = s.removeNthFromEnd(head, 2);
	head = s.removeNthFromEnd(head, 2);


	return 0;
}
