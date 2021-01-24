struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr || k <= 0)
            return nullptr;
        unsigned int n = 0;
        ListNode * cur1 = pListHead;
        ListNode * cur2 = pListHead;
        unsigned int tmp = k-1;
        while(tmp > 0 && cur1->next != nullptr)
        {
            cur1 = cur1->next;
            --tmp;
        }
        if(tmp > 0)
            return nullptr;
        while(cur1->next!=nullptr)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        return cur2;
    }
    
    
    
};