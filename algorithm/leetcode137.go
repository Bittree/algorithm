// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

// 说明：

// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// 示例 1:

// 输入: [2,2,3,2]
// 输出: 3

// 示例 2:

// 输入: [0,1,0,1,0,1,99]
// 输出: 99

package main

import (
	"fmt"
	"strconv"
)

func singleNumber(nums []int) int {
	var sum int
	ret := 0
	size := strconv.IntSize
	for i := 0; i < size; i++ {
		sum = 0
		for _, v := range nums {
			sum += (v >> i) & 1
		}
		ret |= (sum % 3) << i
	}
	return ret
}

func main() {
	nums := []int{-2, -2, 1, 1, -3, 1, -3, -3, -4, -2}
	ret := singleNumber(nums)
	fmt.Println(ret)
}
