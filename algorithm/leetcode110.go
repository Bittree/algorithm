// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

//     一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

// 示例 1:

// 给定二叉树 [3,9,20,null,null,15,7]

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回 true 。

// 示例 2:

// 给定二叉树 [1,2,2,3,3,null,null,4,4]

//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4

// 返回 false 。

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func helper(root *TreeNode) (int, bool) {
	if root == nil {
		return 0, true
	} else {
		left, leftok := helper(root.Left)
        right, rightok := helper(root.Right)
        result := leftok && rightok
        if result {
            if left > right {
                if left-right > 1 {
                    return left + 1, false
                } else {
                    return left + 1, true
                }
            } else {
                if right-left > 1 {
                    return right + 1, false
                } else {
                    return right + 1, true
                }
            }
        }else{
            return 0, false
        }
	}
}

func isBalanced(root *TreeNode) bool {
	_, ok := helper(root)
	return ok
}

func main() {
	root := &TreeNode{Val: 3,
		Left: &TreeNode{Val: 9},
		Right: &TreeNode{Val: 20,
			Left:  &TreeNode{Val: 15},
			Right: &TreeNode{Val: 7}}}
	fmt.Println(isBalanced(root))
}
