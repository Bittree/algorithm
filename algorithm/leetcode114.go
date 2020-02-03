// 给定一个二叉树，原地将它展开为链表。

// 例如，给定二叉树

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6

// 将其展开为：

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 关键是原地修改(in-place)，所以不能先序遍历存储节点(有额外存储空间)之后再改成链表，而是要在遍历过程中改
// morris遍历
func flatten(root *TreeNode) {
	for {
		if root == nil {
			break
		}
		if root.Left == nil {
			root = root.Right
		} else {
			prev := root.Left
			for {
				if prev.Right == nil {
					break
				} else {
					prev = prev.Right
				}
			}
			prev.Right = root.Right
			root.Right = root.Left
			root.Left = nil
			root = root.Right
		}
	}
}
