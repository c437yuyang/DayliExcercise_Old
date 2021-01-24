/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are+,-,*,/. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <stack>

class Solution
{
  public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        if (tokens.empty())
            return 0;
        std::stack<std::string> stack;
        size_t idx = 0;
        while (idx < tokens.size())
        {
            if (!isOperator(tokens[idx]))
                stack.push(tokens[idx]);
            else
            {
                int right = stoi(stack.top());
                stack.pop();
                int left = stoi(stack.top());
                stack.pop();
                stack.push(std::to_string(calcByOperator(tokens[idx], left, right)));
            }
            ++idx;
        }
        return stoi(stack.top());
    }

    bool isOperator(const std::string &str)
    {
        if (str == "+" || str == "-" || str == "*" | str == "/")
            return true;
        return false;
    }

    int calcByOperator(const std::string &oper, int left, int right)
    {
        if (oper == "+")
            return left + right;
        else if (oper == "-")
            return left - right;
        else if (oper == "*")
            return left * right;
        else
            return left / right;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> tokens{"2", "1", "+", "3", "*"};
    std::cout << s.evalRPN(tokens) << std::endl;
    tokens = {"4", "13", "5", "/", "+"};
    std::cout << s.evalRPN(tokens) << std::endl;

    return 0;
}
