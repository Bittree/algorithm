// 给定一个二叉树，找出其最大深度。

// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

// 说明: 叶子节点是指没有子节点的节点。

// 示例：
// 给定二叉树 [3,9,20,null,null,15,7]，

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回它的最大深度 3 。

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
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
	return layer + 1
}

func main() {
	root := &TreeNode{Val: 3,
		Left: &TreeNode{Val: 9},
		Right: &TreeNode{Val: 20,
			Left:  &TreeNode{Val: 15},
			Right: &TreeNode{Val: 7}}}
	ret := maxDepth(root)
	fmt.Println("maxDepth: ", ret)
}
