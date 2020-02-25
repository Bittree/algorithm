// 给定一个未排序的整数数组，找出最长连续序列的长度。

// 要求算法的时间复杂度为 O(n)。

// 示例:

// 输入: [100, 4, 200, 1, 3, 2]
// 输出: 4
// 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

package main

import "fmt"

// 最坏情况o(n^n)，最好情况o(n)
func longestConsecutive(nums []int) int {
	records := make(map[int]int)
	ret := 0
	for _, num := range nums {
		_, exists := records[num]
		if exists {
			continue
		}
		cur := 1
		left, ok := records[num-1]
		if ok {
			cur += left
		}
		right, ok := records[num+1]
		if ok {
			cur += right
		}
		records[num] = cur
		if ret < cur {
			ret = cur
		}
		for i := 1; i <= left; i++ {
			records[num-i] = cur
		}
		for i := 1; i <= right; i++ {
			records[num+i] = cur
		}
	}
	return ret
}

// 最坏情况o(n^2),最好情况o(n),所以这种算法更好
// func longestConsecutive(nums []int) int {
// 	if len(nums) == 0 {
// 		return 0
// 	}

// 	numMap := make(map[int] bool)

// 	for _, v := range nums {
// 		_, ok := numMap[v]
// 		if !ok {
// 			numMap[v] = true
// 		}
// 	}

// 	maxLen := 1
// 	tempLen := 1
// 	for k, _ := range numMap {
// 		small := k-1
// 		_, ok := numMap[small]
// 		if ok {
// 			continue
// 		}
// 		val := k+1
// 		for true {
// 			_, ok := numMap[val]
// 			if ok {
// 				tempLen++
// 				if maxLen < tempLen {
// 					maxLen = tempLen
// 				}
// 				val++
// 			} else {
// 				tempLen = 1
// 				break
// 			}
// 		}
// 	}

// 	return maxLen
// }

func main() {
	nums := []int{100, 4, 200, 1, 3, 2}
	ret := longestConsecutive(nums)
	fmt.Println(ret)
}
