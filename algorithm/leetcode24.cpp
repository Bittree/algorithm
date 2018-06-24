// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

// 示例:

// 给定 1->2->3->4, 你应该返回 2->1->4->3.
// 说明:

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

ListNode* swapPairs(ListNode* head) {
    ListNode* pHead = nullptr;
    ListNode* pLast = nullptr;
    ListNode* pCur = head;
    while(pCur)
    {
        if(pCur->next)
        {
            ListNode* pNext = pCur->next;
            if(pHead)
            {
                pLast->next = pNext;
            }else{
                pHead = pNext;
            }
            pCur->next = pNext->next;
            pNext->next = pCur;
        }else{
            if(pHead)
            {
                pLast->next = pCur;
            }else{
                pHead = pCur;
            }
        }
        pLast = pCur;
        pCur = pCur->next;
    }
    return pHead;
}

int main()
{
    vector<int> arr = {1,2,4,5,6,7,8};
    ListNode* data = CreateList(arr);
    PrintList(data);
    ListNode* ret = swapPairs(data);
    PrintList(ret);
    DestoryList(ret);
}