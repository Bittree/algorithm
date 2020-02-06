// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

// 在杨辉三角中，每个数是它左上方和右上方的数的和。

// 示例:

// 输入: 3
// 输出: [1,3,3,1]

// 进阶：

// 你可以优化你的算法到 O(k) 空间复杂度吗？

package main

import "fmt"

func getRow(rowIndex int) []int {
	ret := make([]int, rowIndex+1)
	for i := 0; i <= rowIndex; i++ {
		ret[0] = 1
		ret[i] = 1
		for j := i - 1; j > 0; j-- {
			ret[j] += ret[j-1]
		}
	}
	return ret
}

func main() {
	ret := getRow(5)
	for _, v := range ret {
		fmt.Print(v, " ")
	}
}
