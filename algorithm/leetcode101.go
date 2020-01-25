package main

import "fmt"

// 给定一个二叉树，检查它是否是镜像对称的。

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3

// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3

// 说明:

// 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	if root == nil || (root.Left == nil && root.Right == nil) {
		return true
	} else if root.Left != nil && root.Right != nil && root.Left.Val == root.Right.Val {
		root.Left.Right, root.Right.Right = root.Right.Right, root.Left.Right
		return isSymmetric(root.Left) && isSymmetric(root.Right)
	} else {
		return false
	}
}

func isSymmetric2(root *TreeNode) bool {
	if(root == nil) {
        return true
    }
	records := []*TreeNode{root}
	for {
		if len(records) <= 0 {
			break
		}
		target := records[0]
		records = records[1:]

		if (target.Left != nil && target.Right == nil) || (target.Left == nil && target.Right != nil) || (target.Left != nil && target.Right != nil && target.Left.Val != target.Right.Val) {
			return false
		} else if target.Left != nil && target.Right != nil && target.Left.Val == target.Right.Val {
			target.Left.Right, target.Right.Right = target.Right.Right, target.Left.Right
			records = append(records, target.Left, target.Right)
		}
	}
	return true
}

func main() {
	root := &TreeNode{Val: 1,
		Left: &TreeNode{Val: 2,
			Left:  &TreeNode{Val: 3},
			Right: &TreeNode{Val: 4}},
		Right: &TreeNode{Val: 2,
			Left:  &TreeNode{Val: 4},
			Right: &TreeNode{Val: 3}}}
	ret := isSymmetric2(root)
	fmt.Println("ret: ", ret)
	// fmt.Println("root: ", root.Val)
	// fmt.Println("2Left: ", root.Left.Val)
	// fmt.Println("2Right: ", root.Right.Val)
	// fmt.Println("31Left: ", root.Left.Left.Val)
	// fmt.Println("31Right: ", root.Left.Right.Val)
	// fmt.Println("32Left: ", root.Right.Left.Val)
	// fmt.Println("32Right: ", root.Right.Right.Val)
}
