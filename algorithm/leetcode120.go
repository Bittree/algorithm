// 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

// 例如，给定三角形：

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]

// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

// 说明：

// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

package main

import "fmt"

func minimumTotal(triangle [][]int) int {
	rowNums := len(triangle)
	for i := 1; i < rowNums; i++ {
		triangle[i][0] += triangle[i-1][0]
		for j := 1; j <= i; j++ {
			if len(triangle[i-1]) > j && triangle[i-1][j] < triangle[i-1][j-1] {
				triangle[i][j] += triangle[i-1][j]
			} else {
				triangle[i][j] += triangle[i-1][j-1]
			}
		}
	}
	ret := triangle[rowNums-1][0]
	for _, v := range triangle[rowNums-1] {
		if ret > v {
			ret = v
		}
	}
	return ret
}

func main() {
	triangle := [][]int{
		{-1},
		{-2, -3}}
	ret := minimumTotal(triangle)
	fmt.Println(ret)
}
