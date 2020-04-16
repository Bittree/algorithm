// 给定一个二叉树，返回它的 后序 遍历。

// 示例:

// 输入: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 

// 输出: [3,2,1]

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

func reverse(from *TreeNode, to *TreeNode) {
    if from == to {
        return
    }
    prev := from
    cur := from.Right
    for {
        temp := cur.Right
        cur.Right = prev
        prev = cur
        cur = temp
        if prev == to {
            break
        }
    }
}

func reverseAccess(from *TreeNode, to *TreeNode, ret []int) []int {
    reverse(from, to)
    cur := to
    for {
        ret = append(ret, cur.Val)
        if cur == from {
            break
        }
        cur = cur.Right
    }
    reverse(to, from)
    return ret
}

// morris遍历
func postorderTraversal(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }
    ret := []int{}
    temp := &TreeNode{Left:root}
    cur := temp
    var prev *TreeNode
    for cur != nil {
        if cur.Left == nil {
            cur = cur.Right
        }else{
            prev = cur.Left
            for prev.Right != nil && prev.Right != cur {
                prev = prev.Right
            }

            if prev.Right == nil {
                prev.Right = cur
                cur = cur.Left
            }else{
                ret = reverseAccess(cur.Left, prev, ret)
                prev.Right = nil
                cur = cur.Right
            }
        }
    }
    return ret
}

func main() {
    node1 := &TreeNode{Val:1}
    node2 := &TreeNode{Val:2}
    node3 := &TreeNode{Val:3}
    node1.Right = node2
    node2.Left = node3
    ret := postorderTraversal(node1)
    for _, v := range ret {
        fmt.Print(v, " ")
    }
}