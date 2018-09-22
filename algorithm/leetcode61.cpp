// 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

// 示例 1:

// 输入: 1->2->3->4->5->NULL, k = 2
// 输出: 4->5->1->2->3->NULL
// 解释:
// 向右旋转 1 步: 5->1->2->3->4->NULL
// 向右旋转 2 步: 4->5->1->2->3->NULL
// 示例 2:

// 输入: 0->1->2->NULL, k = 4
// 输出: 2->0->1->NULL
// 解释:
// 向右旋转 1 步: 2->0->1->NULL
// 向右旋转 2 步: 1->2->0->NULL
// 向右旋转 3 步: 0->1->2->NULL
// 向右旋转 4 步: 2->0->1->NULL

#include <iostream>
#include <array>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k)
{
	if (!head || k == 0)
	{
		return head;
	}
	int count = 0;
	auto pTmp = head;
	ListNode* pTail = NULL;
	while (pTmp)
	{
		++count;
		if (pTmp->next == NULL)
		{
			pTail = pTmp;
		}
		pTmp = pTmp->next;
	}
	pTmp = head;
	k = k % count;
	if (k == 0)
	{
		return head;
	}
	count -= k;
	--count;
	while (count--)
	{
		pTmp = pTmp->next;
	}
	auto pRet = pTmp->next;
	pTmp->next = NULL;
	pTail->next = head;
	return pRet;
}

int main()
{
	array<int, 5> arr = { 1, 2, 3, 4, 5 };
	int k = 2;
	ListNode* head = nullptr, *ptmp = nullptr;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (head)
		{
			ptmp->next = new ListNode(arr[i]);
			ptmp = ptmp->next;
		}
		else {
			head = new ListNode(arr[i]);
			ptmp = head;
		}
	}
	auto result = rotateRight(head, k);
	while (result)
	{
		cout << result->val << " ";
		ListNode* pCur = result;
		result = result->next;
		delete pCur;
	}
	cout << endl;

	array<int, 3> arr2 = { 0, 1, 2 };
	k = 4;
	head = nullptr, ptmp = nullptr;
	for (int i = 0; i < arr2.size(); ++i)
	{
		if (head)
		{
			ptmp->next = new ListNode(arr2[i]);
			ptmp = ptmp->next;
		}
		else {
			head = new ListNode(arr2[i]);
			ptmp = head;
		}
	}
	result = rotateRight(head, k);
	while (result)
	{
		cout << result->val << " ";
		ListNode* pCur = result;
		result = result->next;
		delete pCur;
	}
	cout << endl;

	return 1;
}