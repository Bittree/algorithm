// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

// 说明: 叶子节点是指没有子节点的节点。

// 示例:
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1

// 返回:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 后序遍历
// 用prev指针标识右子节点是否访问过
func pathSum(root *TreeNode, sum int) [][]int {
	ret := [][]int{}
	records := []*TreeNode{}
	var prev *TreeNode
	for {
		if root == nil && len(records) == 0 {
			break
		}
		for {
			if root != nil {
				records = append(records, root)
				sum -= root.Val
				root = root.Left
			} else {
				break
			}
		}
		root = records[len(records)-1]
		if root.Left == nil && root.Right == nil && sum == 0 {
			arr := []int{}
			for _, node := range records {
				arr = append(arr, node.Val)
			}
			ret = append(ret, arr)
		}
		if root.Right == nil || prev == root.Right {
			records = records[:len(records)-1]
			sum += root.Val
			prev = root
			root = nil
		} else {
			root = root.Right
		}
	}
	return ret
}

func main() {
	root := &TreeNode{Val: 5,
		Left: &TreeNode{Val: 4,
			Left: &TreeNode{Val: 11,
				Left:  &TreeNode{Val: 7},
				Right: &TreeNode{Val: 2}}},
		Right: &TreeNode{Val: 8,
			Left: &TreeNode{Val: 13},
			Right: &TreeNode{Val: 4,
				Left:  &TreeNode{Val: 5},
				Right: &TreeNode{Val: 1}}}}
	ret := pathSum(root, 22)
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
	fmt.Println("------------------------------")
	root = &TreeNode{Val: 1,
		Left: &TreeNode{Val: 2}}
	ret = pathSum(root, 1)
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
}
