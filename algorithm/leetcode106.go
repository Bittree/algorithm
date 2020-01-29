// 根据一棵树的中序遍历与后序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 中序遍历 inorder = [9,3,15,20,7]
// 后序遍历 postorder = [9,15,7,20,3]

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

func buildTreehelper(postorder []int, inorderMap map[int]int, post_index *int, in_left int, in_right int) *TreeNode {
	if in_left == in_right {
		return nil
	}
	target := postorder[*post_index]
	*post_index--
	cur_node := &TreeNode{Val: target}
	inorder_index := inorderMap[target]
	cur_node.Right = buildTreehelper(postorder, inorderMap, post_index, inorder_index+1, in_right)
	cur_node.Left = buildTreehelper(postorder, inorderMap, post_index, in_left, inorder_index)
	return cur_node
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	records := make(map[int]int)
	for i := 0; i < len(inorder); i++ {
		records[inorder[i]] = i
	}
	post_index := len(postorder) - 1
	return buildTreehelper(postorder, records, &post_index, 0, len(inorder))
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
	postOrder := []int{9, 15, 7, 20, 3}
	inOrder := []int{9, 3, 15, 20, 7}
	root := buildTree(inOrder, postOrder)
	ret := levelOrder(root)
	for _, v := range ret {
		fmt.Println("   ")
		for _, node := range v {
			fmt.Print(node, " ")
		}
	}
}
