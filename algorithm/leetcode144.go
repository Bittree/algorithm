// 给定一个二叉树，返回它的 前序 遍历。

//  示例:

// 输入: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 

// 输出: [1,2,3]

// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

package main

import (
	"fmt"
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func preorderTraversal(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }
    records := []*TreeNode{root}
    ret := []int{}
    for len(records) > 0 {
        cur := records[len(records)-1]
        records = records[:len(records)-1]
        if cur.Right != nil {
            records = append(records, cur.Right)
        }
        if cur.Left != nil {
            records = append(records, cur.Left)
        }
        ret = append(ret, cur.Val)
    }
    return ret
}

func main() {
    node1 := &TreeNode{Val:1}
    node2 := &TreeNode{Val:2}
    node3 := &TreeNode{Val:3}
    node1.Right = node2
    node2.Left = node3
    ret := preorderTraversal(node1)
    for _, v := range ret {
        fmt.Print(v, " ")
    }
}