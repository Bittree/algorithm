// 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

// 示例 :

// 给定这个链表：1->2->3->4->5

// 当 k = 2 时，应当返回: 2->1->4->3->5

// 当 k = 3 时，应当返回: 3->2->1->4->5

// 说明 :

// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CreateList(vector<int> arr)
{
    int size = arr.size();
    ListNode* pHead = nullptr;
    ListNode* pTmp = nullptr;
    for(int i = 0; i < size; ++i)
    {
        if(!pHead)
        {
            pHead = new ListNode(arr[i]);
            pTmp = pHead;
        }else{
            pTmp->next = new ListNode(arr[i]);
            pTmp = pTmp->next;
        }
    }
    return pHead;
}

void DestoryList(ListNode* pList)
{
    ListNode* pTmp = pList;
    while(pTmp)
    {
        ListNode* tmp = pTmp;
        delete tmp;
        pTmp = pTmp->next;
    }
}

void PrintList(ListNode* pList)
{
    ListNode* pTmp = pList;
    while(pTmp)
    {
        cout << pTmp->val << " ";
        pTmp = pTmp->next;
    }
    cout << endl;
}

ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* pHead = nullptr;
	ListNode* pLast = nullptr;
	ListNode* pCur = head;
	while (pCur)
	{
		bool isEnough = true;
		ListNode* pTmp = pCur;
		ListNode* pLastTmp = nullptr;
		for (int i = k; i > 0; i--)
		{
			if (!pTmp)
			{
				isEnough = false;
				break;
			}
			pLastTmp = pTmp;
			pTmp = pTmp->next;
		}
		if (isEnough)
		{
			ListNode* pNext = pLastTmp;
			if (pHead)
			{
				pLast->next = pNext;
			}
			else {
				pHead = pNext;
			}

			ListNode* pItor = pCur->next;
			ListNode* pItorLast = pCur;
			for (int i = k - 1; i > 0; i--)
			{
				ListNode* pItorNext = pItor->next;
				pItor->next = pItorLast;
				pItorLast = pItor;
				pItor = pItorNext;
			}

			pCur->next = pTmp;
		}
		else {
			if (pHead)
			{
				pLast->next = pCur;
			}
			else {
				pHead = pCur;
			}
		}
		pLast = pCur;
		pCur = pTmp;
	}
	return pHead;
}

int main()
{
    vector<int> arr = {1,2,4,5,6,7,8};
    ListNode* data = CreateList(arr);
    PrintList(data);
    ListNode* ret = reverseKGroup(data);
    PrintList(ret);
    DestoryList(ret);
}