// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

// 说明：

// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// 示例 1:

// 输入: [2,2,1]
// 输出: 1

// 示例 2:

// 输入: [4,1,2,1,2]
// 输出: 4

package main

import "fmt"

// 因为一个数最多出现两次，所以可以用异或的性质，两个数相同异或结果为0
func singleNumber(nums []int) int {
	ret := 0
	for _, v := range nums {
		ret ^= v
	}
	return ret
}

func main() {
	nums := []int{4, 1, 2, 1, 2}
	ret := singleNumber(nums)
	fmt.Println(ret)
}
