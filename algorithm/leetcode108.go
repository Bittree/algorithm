// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

// 示例:

// 给定有序数组: [-10,-3,0,5,9],

// 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) <= 0 {
		return nil
	}
	mid := len(nums) / 2
	return &TreeNode{Val: nums[mid], Left: sortedArrayToBST(nums[:mid]), Right: sortedArrayToBST(nums[mid+1:])}
}

func printTree(root *TreeNode) {
	var ret [][]int
	if root == nil {
		return
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
	}
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
}

func main() {
	arr := []int{-10, -3, 0, 5, 9}
	node := sortedArrayToBST(arr)
	printTree(node)
}
