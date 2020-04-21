// 对链表进行插入排序。

// 从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
// 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

// 插入排序算法：

//     插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//     每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//     重复直到所有输入数据插入完为止。

// 示例 1：

// 输入: 4->2->1->3
// 输出: 1->2->3->4

// 示例 2：

// 输入: -1->5->3->4->0
// 输出: -1->0->3->4->5

package main

import (
    "fmt"
)

type ListNode struct {
    Val int
    Next *ListNode
}

func insertionSortList(head *ListNode) *ListNode {
    cur := head
    var ret *ListNode
    for cur != nil {
        next := cur.Next
        cur.Next = nil
        if ret == nil {
            ret = cur
        }else{
            var prev *ListNode
            compare := ret
            for compare != nil {
                if compare.Val > cur.Val {
                    cur.Next = compare
                    if prev == nil {
                        ret = cur
                    }else{
                        prev.Next = cur
                    }
                    break
                }
                if compare.Next == nil {
                    compare.Next = cur
                    break
                }else{
                    prev = compare
                    compare = compare.Next
                }
            }
        }
        
        cur = next
    }
    return ret
}

// faster!
// func insertionSortList(head *ListNode) *ListNode {
// 	if head == nil {
// 		return head
// 	}
// 	preHead := &ListNode{Next: head}
// 	p1 := head

// 	for p2 := p1.Next; p2 != nil; p2 = p1.Next {
// 		if p2.Val >= p1.Val {
// 			p1.Next = p2
// 			p1 = p2
// 		} else {
// 			pre := p2.Next
// 			tmp := preHead
// 			//p2插入preHead
// 			for  tmp.Next.Val < p2.Val {
// 				tmp = tmp.Next
// 			}
// 			p2.Next =tmp.Next
// 			tmp.Next = p2
// 			p1.Next = pre
// 		}
// 	}

// 	return preHead.Next
// }