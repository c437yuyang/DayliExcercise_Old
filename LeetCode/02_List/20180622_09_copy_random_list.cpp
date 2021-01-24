#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>



struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if (head == nullptr)
			return nullptr;
		//先拷贝一份原链表，形成1->1'->2->2'
		RandomListNode *cur = head;
		while (cur != nullptr)
		{
			RandomListNode* nextSave = cur->next;
			cur->next = new RandomListNode(cur->label);
			cur->next->next = nextSave;
			cur = nextSave;
		}

		//先修改random指针
		cur = head;
		while (cur != nullptr)
		{
			cur->next->random = cur->random == nullptr ? nullptr : cur->random->next;
			cur = cur->next->next; //注意这里前进两步
		}

		//修改next指针，把两个链表分开

		RandomListNode *oldHead = head;
		RandomListNode *newHead = head->next;
		RandomListNode *newHeadSave = newHead;
		while (oldHead != nullptr)
		{
			oldHead->next = oldHead->next == nullptr ? nullptr : oldHead->next->next;
			newHead->next = oldHead->next == nullptr ? nullptr : oldHead->next->next;
			oldHead = oldHead->next;
			newHead = newHead->next;
		}

		return newHeadSave;
	}
};


int main()
{


	return 0;
}