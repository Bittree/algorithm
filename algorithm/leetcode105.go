// 根据一棵树的前序遍历与中序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]

// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTreehelper(preorder []int, inorderMap map[int]int, pre_index *int, in_left int, in_right int) *TreeNode {
	if in_left == in_right {
		return nil
	}
	target := preorder[*pre_index]
	*pre_index++
	cur_node := &TreeNode{Val: target}
	inorder_index := inorderMap[target]
	cur_node.Left = buildTreehelper(preorder, inorderMap, pre_index, in_left, inorder_index)
	cur_node.Right = buildTreehelper(preorder, inorderMap, pre_index, inorder_index+1, in_right)
	return cur_node
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	records := make(map[int]int)
	for i := 0; i < len(inorder); i++ {
		records[inorder[i]] = i
	}
	pre_index := 0
	return buildTreehelper(preorder, records, &pre_index, 0, len(inorder))
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
	return ret
}

func main() {
	preOrder := []int{3, 9, 20, 15, 7}
	inOrder := []int{9, 3, 15, 20, 7}
	root := buildTree(preOrder, inOrder)
	ret := levelOrder(root)
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
}
