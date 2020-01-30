// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 说明: 叶子节点是指没有子节点的节点。

// 示例:

// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回它的最小深度  2.

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	} else {
		left := minDepth(root.Left)
		right := minDepth(root.Right)
		if left == 0 && right > 0 {
			return right + 1
		} else if left > 0 && right == 0 {
			return left + 1
		} else if left > 0 && right > 0 {
			if left > right {
				return right + 1
			} else {
				return left + 1
			}
		} else {
			return 1
		}
	}
}

func main() {
	root := &TreeNode{Val: 3,
		Left: &TreeNode{Val: 9},
		Right: &TreeNode{Val: 20,
			Left:  &TreeNode{Val: 15},
			Right: &TreeNode{Val: 7}}}
	fmt.Println(minDepth(root))
}
