// 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

// 例如:
// 给定二叉树: [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回其层次遍历结果：

// [
//   [3],
//   [9,20],
//   [15,7]
// ]

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	var ret [][]int
	if root == nil {
		return ret
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
				// _, ok := records[i+1]
				// if !ok {
				// 	records[i+1] = make([]*TreeNode)
				// }
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
		//  else {
		// 	ret = append(ret, make([]int))
		// }
	}
	return ret
}

func main() {
	root := &TreeNode{Val: 3,
		Left: &TreeNode{Val: 9},
		Right: &TreeNode{Val: 20,
			Left:  &TreeNode{Val: 15},
			Right: &TreeNode{Val: 7}}}
	ret := levelOrder(root)
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
}
