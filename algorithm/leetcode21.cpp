#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* pHead = nullptr;
    ListNode* pTmp = nullptr;
    ListNode* pNext = nullptr;
    while(l1 || l2)
    {
        if(l1 && !l2)
        {
            pTmp = l1;
            l1 = l1->next;
        }else if(!l1 && l2)
        {
            pTmp = l2;
            l2 = l2->next;
        }else{
            if(l1->val <= l2->val)
            {
                pTmp = l1;
                l1 = l1->next;
            }else{
                pTmp = l2;
                l2 = l2->next;
            }
        }
        
        if(!pHead)
        {
            pHead = pTmp;
            pNext = pTmp;
        }else{
            pNext->next = pTmp;
            pNext = pTmp;
        }
    }
    return pHead;
}

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

int main()
{
    vector<int> arr1 = {1,2,4};
    vector<int> arr2 = {1,3,4};
    ListNode* l1 = CreateList(arr1);
    ListNode* l2 = CreateList(arr2);
    PrintList(l1);
    PrintList(l2);
    ListNode* ret = mergeTwoLists(l1, l2);
    PrintList(ret);
    DestoryList(ret);
}