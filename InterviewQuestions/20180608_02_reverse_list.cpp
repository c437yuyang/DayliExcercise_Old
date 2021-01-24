struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *prev = nullptr;
        while(pHead != nullptr)
        {
            ListNode *next_save = pHead->next;
            pHead->next = prev;
            prev = pHead;
            pHead = next_save;
        }
        return prev;
        
    }
};