// 给定一个非空二叉树，返回其最大路径和。

// 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

// 示例 1:

// 输入: [1,2,3]

//        1
//       / \
//      2   3

// 输出: 6

// 示例 2:

// 输入: [-10,9,20,null,null,15,7]

//    -10
//    / \
//   9  20
//     /  \
//    15   7

// 输出: 42

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var maxNum int

func max(a int, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func maxSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := max(0, maxSum(root.Left))
	right := max(0, maxSum(root.Right))
	ret := max(left, right) + root.Val
	maxNum = max(max(left+right+root.Val, maxNum), ret)
	return ret
}

func maxPathSum(root *TreeNode) int {
	maxNum = ^int(^uint(0) >> 1)
	maxSum(root)
	return maxNum
}

func main() {
	root := &TreeNode{Val: 1, Left: &TreeNode{Val: 2}, Right: &TreeNode{Val: 3}}
	ret := maxPathSum(root)
	fmt.Println(ret)

	root = &TreeNode{Val: -10, Left: &TreeNode{Val: 9}, Right: &TreeNode{Val: 20, Left: &TreeNode{Val: 15}, Right: &TreeNode{Val: 7}}}
	ret = maxPathSum(root)
	fmt.Println(ret)

	root = &TreeNode{Val: -3}
	ret = maxPathSum(root)
	fmt.Println(ret)

	root = &TreeNode{Val: 1, Left: &TreeNode{Val: -2}, Right: &TreeNode{Val: 3}}
	ret = maxPathSum(root)
	fmt.Println(ret)
}
