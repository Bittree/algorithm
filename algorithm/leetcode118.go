// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

// 在杨辉三角中，每个数是它左上方和右上方的数的和。

// 示例:

// 输入: 5
// 输出:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

package main

import "fmt"

func generate(numRows int) [][]int {
	ret := make([][]int, numRows)
	if numRows < 1 {
		return ret
	}
	for i := 0; i < numRows; i++ {
		arr := make([]int, i+1)
		arr[0] = 1
		arr[i] = 1
		for j := 1; j < i; j++ {
			arr[j] = ret[i-1][j-1] + ret[i-1][j]
		}
		ret[i] = arr
	}
	return ret
}

func main() {
	ret := generate(5)
	for _, arr := range ret {
		fmt.Print("[")
		for _, v := range arr {
			fmt.Print(v, " ")
		}
		fmt.Println("],")
	}
}
