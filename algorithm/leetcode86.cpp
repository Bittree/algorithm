#include<iostream>
#include<string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
	ListNode *smallptr = NULL;
	ListNode *bigptr = NULL;
	ListNode *cur = head;
	ListNode *cur_small = NULL;
	ListNode *cur_big = NULL;
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			if (smallptr == NULL)
			{
				smallptr = cur;
				cur_small = smallptr;
			}
			else
			{
				cur_small->next = cur;
				cur_small = cur;
			}
		}
		else
		{
			if (bigptr == NULL)
			{
				bigptr = cur;
				cur_big = bigptr;
			}
			else
			{
				cur_big->next = cur;
				cur_big = cur;
			}
		}
		cur = cur->next;
	}
	if (cur_big)
	{
		cur_big->next = NULL;
	}
	if (cur_small)
	{
		cur_small->next = bigptr;
	}
	else
	{
		smallptr = bigptr;
	}
	return smallptr;
}

int main()
{
	ListNode* head = new ListNode(1);
	//ListNode* cur = head;
	//cur->next = new ListNode(4);
	//cur = cur->next;
	//cur->next = new ListNode(3);
	//cur = cur->next;
	//cur->next = new ListNode(2);
	//cur = cur->next;
	//cur->next = new ListNode(5);
	//cur = cur->next;
	//cur->next = new ListNode(2);
	//cur = cur->next;
	ListNode* result = partition(head, 0);
	while (result)
	{
		cout << result->val << endl;
		result = result->next;
	}

	return 1;
}