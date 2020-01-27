// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回锯齿形层次遍历如下：

// [
//   [3],
//   [20,9],
//   [15,7]
// ]

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(root *TreeNode) [][]int {
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
	for i := 0; i <= layer; i++ {
		cur := []int{}
		target, ok := records[i]
		if ok {
			if i%2 == 0 {
				for j := 0; j < len(target); j++ {
					cur = append(cur, target[j].Val)
				}
			} else {
				for j := len(target) - 1; j >= 0; j-- {
					cur = append(cur, target[j].Val)
				}
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
	ret := zigzagLevelOrder(root)
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
}
