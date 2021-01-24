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
	ListNode *detectCycle(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		if (head->next == head) //一个节点单独考虑
			return head;
		if (head->next->next == head) //只有两个节点单独考虑
			return head;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) //找到第一次相遇的点
				break;
		}
		
		if (fast == nullptr || fast->next == nullptr)
			return nullptr;

		slow = head; //一个节点再回到head
		while (slow != fast) //再次相遇就是入环点
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};

void testcase(std::vector<int>& v, int cycleIdx)
{

	ListNode * head = CreateList(v);
	ListNode * tail = GetListNodeAt(head, v.size() - 1);
	ListNode * cycle = GetListNodeAt(head, cycleIdx);
	tail->next = cycle;

	Solution s;
	ListNode * detected = s.detectCycle(head);

	std::cout << detected->val << std::endl;
	assert(v[cycleIdx] == detected->val);
}



int main()
{
	testcase(std::vector<int>{ -1,-7,7,-4,19,6,-9,-5,-2,-5 }, 6);
	testcase(std::vector<int>{ -21, 10, 17, 8, 4, 26, 5, 35, 33, -7, -16, 27, -12, 6, 29, -12, 5, 9, 20, 14, 14, 2, 13, -24, 21, 23, -21, 5 }, 24);

	return 0;
}