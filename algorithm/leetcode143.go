// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 示例 1:

// 给定链表 1->2->3->4, 重新排列为 1->4->2->3.

// 示例 2:

// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

package main

import (
	"fmt"
)

type ListNode struct {
    Val int
    Next *ListNode
}

// 最快的方法，用快慢指针找到中间的节点，然后把后半部分节点入栈，再把前半部分节点和栈中节点接起来
func reorderList1(head *ListNode) {
	if head == nil {
		return
	}
	slow, fast := head, head
	for fast != nil {
		slow = slow.Next
		fast = fast.Next
		if fast != nil {
			fast = fast.Next
		}
	}

	var stack []*ListNode
	for slow != nil {
		stack = append(stack, slow)
		slow = slow.Next
	}

	t := head
	for len(stack) > 0 {
		n := t.Next
		p := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		t.Next = p
		p.Next = n
		t = n
	}
	t.Next = nil
}

func reorderList(head *ListNode)  {
    // 双端队列
    if head == nil {
        return
    }
    records := []*ListNode{}
    cur := head
    for cur != nil {
        records = append(records, cur)
        cur = cur.Next
    }
    len := len(records)
    if len <= 2 {
        return
    }
    cur = head
    for i,j := 1, len-1; i <= j; i, j = i+1,j-1 {
        cur.Next = records[j]
        if i < j {
            records[j].Next = records[i]
        }
        cur = records[i]
        cur.Next = nil
    }
}

func main() {
    node1 := &ListNode{Val: 1}
    node2 := &ListNode{Val: 2}
    //node3 := &ListNode{Val: 3}
    //node4 := &ListNode{Val: 4}
    //node5 := &ListNode{Val: 5}
    node1.Next = node2
    //node2.Next = node3
    //node3.Next = node4
    //node4.Next = node5
    reorderList(node1)
    cur := node1
    for cur != nil {
        fmt.Print(cur.Val, "-->")
        cur = cur.Next
    }
}