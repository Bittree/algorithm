// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

// 示例:

// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode* pLast = nullptr;
	ListNode* pHead = nullptr;
	vector<ListNode*> tmp = lists;
	for (auto itor = tmp.begin(); itor!= tmp.end();)
	{
		if (!*itor)
		{
			itor = tmp.erase(itor);
		} 
		else
		{
			++itor;
		}
	}
	function<bool(ListNode*, ListNode*)> greater = [](ListNode* nodeA, ListNode* nodeB) { return nodeA->val > nodeB->val; };
	make_heap(tmp.begin(), tmp.end(), greater);
	while (tmp.size() > 0)
	{
		if (!pHead)
		{
			pHead = tmp[0];
			pLast = tmp[0];
		}
		else {
			pLast->next = tmp[0];
			pLast = tmp[0];
		}

		pop_heap(tmp.begin(), tmp.end(), greater);
		tmp.pop_back();
		auto pNext = pLast->next;
		if (pNext)
		{
			tmp.push_back(pNext);
			push_heap(tmp.begin(), tmp.end(), greater);
		}
	}
	return pHead;
}

int main()
{
	vector<ListNode*> lists;
	vector<vector<int>> data;
	data.push_back({1,4,5});
	data.push_back({ 1,3,4 });
	data.push_back({ 2,6 });
	
	for (auto vec : data)
	{
		ListNode* pList = nullptr;
		ListNode* pLast = nullptr;
		for (auto ele : vec)
		{
			ListNode* pNode = new ListNode(ele);
			if (!pList)
			{
				pList = pNode;
				pLast = pNode;
			} 
			else
			{
				pLast->next = pNode;
				pLast = pNode;
			}
		}
		lists.push_back(pList);
	}

	auto ret = mergeKLists(lists);
	while (ret)
	{
		cout << ret->val << " ";
		auto pNext = ret->next;
		delete ret;
		ret = pNext;
	}
	cout << endl;
	return 0;
}