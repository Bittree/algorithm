// 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

// 说明:
// 1 ≤ m ≤ n ≤ 链表长度。

// 示例:

// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
// 输出: 1->4->3->2->5->NULL

#include<iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) 
{
    if(m==n)
    {
        return head;
    }
    ListNode* cur = head, *mtail = NULL, *last = NULL;
    int cur_index = 1;
    while(cur)
    {
        if(cur_index == m-1)
        {
            mtail = cur;
        }
        if(cur_index == n)
        {
            if(m==1)
            {
                head->next = cur->next;
                cur->next = last;
                head=cur;
            }
            else
            {
                mtail->next->next = cur->next;
                cur->next = last;
                mtail->next = cur;
            }
            return head;
        }
        if(cur_index >= m)
        {
            ListNode* next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        else
        {
            cur = cur->next;
        }
        ++cur_index;
    }
    return head;
}

void PrintList(ListNode* list)
{
    ListNode* cur = list;
    while(cur)
    {
        cout << cur->val;
        if(cur->next)
        {
            cout << "->";
        }
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    ListNode* head = NULL, *last = NULL;
    for(int i = 1; i <= 2; ++i)
    {
        ListNode* p = new ListNode(i);
        if(!head)
        {
            head = p;
        }
        if(last)
        {
            last->next = p;
            last = p;
        }
        else
        {
            last = head;
        }
    }
    PrintList(head);
    ListNode* ret = reverseBetween(head, 1, 2);
    PrintList(ret);
    return 1;
}