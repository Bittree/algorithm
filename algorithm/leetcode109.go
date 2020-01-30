// 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

// 示例:

// 给定的有序链表： [-10, -3, 0, 5, 9],

// 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	last := head
	counter := 0
	mid := 0
	midptr := head
	var beforemidptr *ListNode
	for {
		if last.Next != nil {
			last = last.Next
			counter++
			if counter/2 > mid {
				mid++
				beforemidptr = midptr
				midptr = midptr.Next
			}
		} else {
			break
		}
	}

	var left *ListNode
	if beforemidptr != nil {
		beforemidptr.Next = nil
		left = head
	}

	return &TreeNode{Val: midptr.Val, Left: sortedListToBST(left), Right: sortedListToBST(midptr.Next)}
}

func printTree(root *TreeNode) {
	var ret [][]int
	if root == nil {
		return
	}
	records := make(map[int][]*TreeNode)
	records[0] = []*TreeNode{root}
	for i := 0; ; i++ {
		target := records[i]
		for j := 0; j < len(target); j++ {
			targetNode := target[j]
			if i >= len(ret) {
				ret = append(ret, []int{})
			}
			ret[i] = append(ret[i], targetNode.Val)
			if targetNode != nil && (targetNode.Left != nil || targetNode.Right != nil) {
				if targetNode.Left != nil {
					records[i+1] = append(records[i+1], targetNode.Left)
				}
				if targetNode.Right != nil {
					records[i+1] = append(records[i+1], targetNode.Right)
				}
			}
		}
		_, ok := records[i+1]
		if !ok {
			break
		}
	}
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
}

func main() {
	arr := []int{-10, -3, 0, 5, 9}
	var list *ListNode
	var last *ListNode
	for _, v := range arr {
		if list == nil {
			list = &ListNode{Val: v}
			last = list
		} else {
			last.Next = &ListNode{Val: v}
			last = last.Next
		}
	}
	// for {
	// 	if list != nil {
	// 		fmt.Print(" ", list.Val)
	// 		list = list.Next
	// 	} else {
	// 		break
	// 	}
	// }
	root := sortedListToBST(list)
	printTree(root)
}
