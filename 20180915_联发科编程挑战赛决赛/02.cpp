/*
括号的烦恼
题目描述
小明正在学习一种新的编程语言，称为M语言，它的代码中使用到了三种括号：

() 小括号
[] 中括号
{} 大括号
对于括号的使用，有两个基本原则：

第一、所有的括号必须成对出现

hello() { world
上面这段代码错在大括号没有关闭。

第二、不同类型的括号不能交叉使用，比如：

{ hello() [ world } ]
上面这段代码错在中括号与大括号存在交叉，可以纠正为：

{ hello() [ world ] }
粗心的小明经常在括号的使用上犯错，你能帮帮他吗？

输入说明
程序从当前路径下的data.txt文件中读取测试数据。

data.txt为单行的ASCII文本文件，长度不超过1KB。

输出说明
若测试数据的括号使用不当，则输出“NO”，然后输出一个空格，再输出第一个不符合预期的括号的位置（即该括号离文件开头的偏移，注意偏移以0开始）。

若测试数据没有问题，则输出“YES”

示例
data.txt文件内容为：hello() { world } 
预期输出为：YES 
测试数据中的括号使用没有问题。

data.txt文件内容为: (hi} 
预期输出为： NO 3 
预期是右小括号，但出现的是右花括号，错误。

data.txt文件内容为: hello() { world 
预期输出为： NO 8 花括号未关闭。

运行时间限制：1 秒   运行内存限制：128 MB。
*/

#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#include<stack>
#include<fstream>
using namespace std;

int isValid(string s,int &n)
{
     stack  <char> stack;
	 vector <int>  vec;
     for (int i=0;i<s.size();i++) 
     {
		char c=s[i];
		//左括号直接入栈，同时记录位置
        if (c == '(' || c == '{' || c == '[') 
        {
           stack.push(c);
		   vec.push_back(i);
        }
        //右括号判定栈是否为空或者栈顶是否为相应左括号
		if (c == ')' || c == '}' || c == ']')
		{
			if(stack.empty())
			{
				n = i;
                return 0;
			}
			else
			{
    		    char topchar = stack.top();
    			stack.pop();
    			vec.pop_back();
                bool b1 = (c == ')' && topchar != '(');
                bool b2 = (c == ']' && topchar != '[');
                bool b3 = (c == '}' && topchar != '{');
                if (b1 || b2 || b3) 
                {
    				n = i;
                    return 0;
                    
                }
			}
        }
    }
    //最后检查是否有多余的左括号
	 if(stack.empty())
	 {
		 return 1;
	 }
	 else
	 {
		 n=vec.front();
		 return 0;
	 }
}
int main()
{
	ifstream in("data.txt");
	string str;
	getline(in, str);
	int n=0;
    int flag=isValid(str,n);
	if(flag)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO " << n << endl;
	}
	return 0;
}