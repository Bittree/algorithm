// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回其自底向上的层次遍历为：

// [
//   [15,7],
//   [9,20],
//   [3]
// ]

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrderBottom(root *TreeNode) [][]int {
	var ret [][]int
	if root == nil {
		return ret
	}
	records := make(map[int][]*TreeNode)
	records[0] = []*TreeNode{root}
	layer := 0
	for ; ; layer++ {
		target := records[layer]
		for j := 0; j < len(target); j++ {
			targetNode := target[j]
			if targetNode != nil && (targetNode.Left != nil || targetNode.Right != nil) {
				if targetNode.Left != nil {
					records[layer+1] = append(records[layer+1], targetNode.Left)
				}
				if targetNode.Right != nil {
					records[layer+1] = append(records[layer+1], targetNode.Right)
				}
			}
		}
		_, ok := records[layer+1]
		if !ok {
			break
		}
	}
	for i := layer; i >= 0; i-- {
		cur := []int{}
		target, ok := records[i]
		if ok {
			for j := 0; j < len(target); j++ {
				cur = append(cur, target[j].Val)
			}
		}
		ret = append(ret, cur)
	}
	return ret
}

func main() {
	root := &TreeNode{Val: 3,
		Left: &TreeNode{Val: 9},
		Right: &TreeNode{Val: 20,
			Left:  &TreeNode{Val: 15},
			Right: &TreeNode{Val: 7}}}
	ret := levelOrderBottom(root)
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
}
