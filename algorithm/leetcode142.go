// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

// 说明：不允许修改给定的链表。

 

// 示例 1：

// 输入：head = [3,2,0,-4], pos = 1
// 输出：tail connects to node index 1
// 解释：链表中有一个环，其尾部连接到第二个节点。

// 示例 2：

// 输入：head = [1,2], pos = 0
// 输出：tail connects to node index 0
// 解释：链表中有一个环，其尾部连接到第一个节点。

// 示例 3：

// 输入：head = [1], pos = -1
// 输出：no cycle
// 解释：链表中没有环。

 

// 进阶：
// 你是否可以不用额外空间解决此题？

package main

import (
	"fmt"
)

type ListNode struct {
    Val int
    Next *ListNode
}

func detectCycle1(head *ListNode) *ListNode {
	// 如果直接nil或者下一个节点为nil,那么就肯定没有环了
	if head == nil || head.Next == nil {
		return nil
	}

	// 定义两个节点,一个为快指针,一个慢指针
	fast := head
	slow := head
	for fast.Next != nil && fast.Next.Next != nil {
		// 快指针肯定跑得快,快指针如果走到了nil,那么说明没有环
		if fast.Next == nil {
			return nil
		}
		// 快指针每次跳两步
		fast = fast.Next.Next
		// 慢指针每次跳一步
		slow = slow.Next
		// 当 快指针和慢指针相遇了
		if fast == slow {
			// head 节点开始走,fast指针改成每次走一步,相遇的时候 就是环形的起点
			for head != fast {
				head = head.Next
				fast = fast.Next
			}
			return head
		}
	}
	return nil
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func detectCycle(head *ListNode) *ListNode {
    fast := head
    slow := head
    start := false
    found := false
    for fast != nil && slow != nil{
        if start == false {
            start = true
        }else if fast == slow {
            found = true
            break
        }
        slow = slow.Next
        fast = fast.Next
        if fast != nil {
            fast = fast.Next
        }
    }
    if found {
        fast = head
        for fast != slow {
            fast = fast.Next
            slow = slow.Next
        }
        return slow
    }
    return nil
}