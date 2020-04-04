/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head == nullptr)
            return std::vector<int>();
        std::stack<ListNode*> stack;
        std::vector<int> res;
        while(head!=nullptr)
        {
            stack.push(head);
            head = head->next;
        }
        while(!stack.empty())
        {
            ListNode* cur = stack.top();
            stack.pop();
            std::cout << cur->val << std::endl;
            res.push_back(cur->val);
        }
        return res;
        
    }
};