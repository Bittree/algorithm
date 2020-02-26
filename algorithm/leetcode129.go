// 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

// 例如，从根到叶子节点路径 1->2->3 代表数字 123。

// 计算从根到叶子节点生成的所有数字之和。

// 说明: 叶子节点是指没有子节点的节点。

// 示例 1:

// 输入: [1,2,3]
//     1
//    / \
//   2   3
// 输出: 25
// 解释:
// 从根到叶子节点路径 1->2 代表数字 12.
// 从根到叶子节点路径 1->3 代表数字 13.
// 因此，数字总和 = 12 + 13 = 25.

// 示例 2:

// 输入: [4,9,0,5,1]
//     4
//    / \
//   9   0
//  / \
// 5   1
// 输出: 1026
// 解释:
// 从根到叶子节点路径 4->9->5 代表数字 495.
// 从根到叶子节点路径 4->9->1 代表数字 491.
// 从根到叶子节点路径 4->0 代表数字 40.
// 因此，数字总和 = 495 + 491 + 40 = 1026.

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumNumbers(root *TreeNode) int {
	if root == nil {
		return 0
	}
	records := []*TreeNode{root}
	ret := 0
	for {
		if len(records) <= 0 {
			break
		}
		target := records[0]
		if target.Left != nil {
			target.Left.Val += (target.Val * 10)
			records = append(records, target.Left)
		}
		if target.Right != nil {
			target.Right.Val += (target.Val * 10)
			records = append(records, target.Right)
		}
		if target.Left == nil && target.Right == nil {
			ret += target.Val
		}
		records = records[1:]
	}
	return ret
}

func main() {
	var nums *TreeNode
	var ret int

	nums = &TreeNode{Val: 4, Left: &TreeNode{Val: 9, Left: &TreeNode{Val: 5}, Right: &TreeNode{Val: 1}}, Right: &TreeNode{Val: 0}}
	ret = sumNumbers(nums)
	fmt.Println(ret)
}
