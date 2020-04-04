#include <iostream>


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return pHead1;
        ListNode* head = pHead1->val < pHead2->val ? pHead1 : pHead2;
        if(pHead1->val<pHead2->val)
            pHead1 = pHead1->next;
        else
            pHead2 = pHead2->next;
        
        ListNode *cur = head;
        while(pHead1 != nullptr && pHead2 != nullptr)
        {
            if(pHead1->val < pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }else 
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        while(pHead1!=nullptr)
        {
            cur->next = pHead1;
            pHead1 = pHead1->next;
            cur=cur->next;
        }
        while(pHead2!=nullptr)
        {
            cur->next = pHead2;
            pHead2 = pHead2->next;
            cur=cur->next;
        }
        return head;
    }
};


int main()
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);    

    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);



    Solution s;
    auto head = s.Merge(head1,head2);


    return 0;
}