//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 */
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr && carry == 0)return nullptr;
        if(l1 == nullptr && carry == 0)return l2;
        if(l2 == nullptr && carry == 0)return l1;
        ListNode* l3 = new ListNode(0);
        if(l3 == nullptr)return nullptr;
        
        if(l1 == nullptr && l2 == nullptr)
        {
            l3->val = carry;
            carry = l3->val/10;
            l3->val%=10;
            l3->next = nullptr;
        }
        else if(l1 != nullptr && l2 == nullptr)
        {
            l3->val = l1->val + carry;
            carry = l3->val/10;
            l3->val%=10;
            l3->next = addTwoNumbers(l1->next,nullptr);
        }
        else if(l1 == nullptr && l2 != nullptr)
        {
            l3->val = l2->val + carry;
            carry = l3->val/10;
            l3->val%=10;
            l3->next = addTwoNumbers(nullptr,l2->next);
        }
        else
        {
            l3->val = l1->val + l2->val +carry;
            carry = l3->val/10;
            l3->val%=10;
            l3->next = addTwoNumbers(l1->next,l2->next);
        }
        return l3;
    }
    int carry;
    Solution() {
        carry = 0;
    }
};
int main()
{
        Solution* s1 = new Solution();
        ListNode* l1 = new ListNode(5);
        ListNode* l2 = new ListNode(5);
        ListNode* l3 = nullptr;
        ListNode* l4 = nullptr;
        l3 = s1->addTwoNumbers(l1,l2);
        l4 = l3;
        while(l4)
        {
           cout<< l4->val << " ";
           l4 = l4->next;
        }
        cout<<endl;
        return 0;
}
