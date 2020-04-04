class Solution
{
public:
    void push(int node) {
        stack_push.push(node);
    }

    int pop() {
        if(!stack_pop.empty())
        {
            return popStack(stack_pop);
        }
        while(!stack_push.empty())
        {
            int tmp = stack_push.top();
            stack_push.pop();
            stack_pop.push(tmp);
        }
        return popStack(stack_pop);
        
    }

private:
    int popStack(stack<int>&s)
    {
        int res = s.top();
        s.pop();
        return res;
    }
    stack<int> stack_push;
    stack<int> stack_pop;
};