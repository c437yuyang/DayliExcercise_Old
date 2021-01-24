/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
			return false;
		if (head->next == head) //一个节点单独考虑
			return true;
		if (head->next->next == head) //只有两个节点单独考虑
			return true;
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
			return false;
        return true;
    }
};