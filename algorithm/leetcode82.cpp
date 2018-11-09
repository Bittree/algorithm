// 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

// 示例 1:

// 输入: 1->2->3->3->4->4->5
// 输出: 1->2->5
// 示例 2:

// 输入: 1->1->1->2->3
// 输出: 2->3

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
    unordered_map<int, pair<int, ListNode*>> record;
    ListNode* pItor = head, *ret = head, *last = nullptr;
    while(pItor)
    {
        if(record.find(pItor->val) == record.end())
        {
            record[pItor->val] = make_pair(1, last);
            last = pItor;
        }
        else
        {
            auto data = &record[pItor->val];
            if(data->first == 1) // 有重复节点，删除上一个节点
            {
                if(data->second != nullptr) // 上一个重复节点不是头节点
                {
                    if(last == data->second->next)  // 上一个重复节点是last节点
                    {
                        last = data->second;
                    }
                    data->second->next = data->second->next->next;
                }
                else    // 上一个重复节点是头节点
                {
                    ret = ret->next;
                    last = nullptr;
                }
                data->first = 0;
            }
            // 这个节点上一个重复的节点已经删除了，只需要删除当前节点
            if(last != nullptr)
            {
                last->next = pItor->next;
            }else{
                ret = ret->next;
            }
        }
        pItor = pItor->next;
    }
    return ret;
}