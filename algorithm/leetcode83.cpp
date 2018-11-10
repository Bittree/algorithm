// 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

// 示例 1:

// 输入: 1->1->2
// 输出: 1->2
// 示例 2:

// 输入: 1->1->2->3->3
// 输出: 1->2->3

#include<iostream>
#include<unordered_map>
#include <utility>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* last = nullptr, *itor = head;
    while(itor)
    {
        if(last && last->val == itor->val)
        {
            last->next = itor->next;
        }
        else
        {
            last = itor;
        }
        itor = itor->next;
    }
    return head;
}