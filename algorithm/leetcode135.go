// 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

// 你需要按照以下要求，帮助老师给这些孩子分发糖果：

//     每个孩子至少分配到 1 个糖果。
//     相邻的孩子中，评分高的孩子必须获得更多的糖果。

// 那么这样下来，老师至少需要准备多少颗糖果呢？

// 示例 1:

// 输入: [1,0,2]
// 输出: 5
// 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。

// 示例 2:

// 输入: [1,2,2]
// 输出: 4
// 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
//      第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

package main

import "fmt"

// O(n^2)时间复杂度
func candy(ratings []int) int {
	size := len(ratings)
	if size <= 0 {
		return 0
	}
	result := make([]int, size)
	ret := 0
	new := 0
	for i := 0; i < size; i++ {
		if i > 0 && ratings[i] > ratings[i-1] {
			result[i] = result[i-1] + 1
			ret += result[i]
		} else if i > 0 && ratings[i] < ratings[i-1] {
			result[i] = 1
			ret++
			for j := i - 1; j >= 0; j-- {
				if ratings[j] > ratings[j+1] && result[j] <= result[j+1] {
					new = result[j+1] + 1
					ret += new - result[j]
					result[j] = new
				} else {
					break
				}
			}
		} else {
			result[i] = 1
			ret++
		}
	}
	return ret
}

// 这个更好，O(n)时间复杂度
// func candy(ratings []int) int {
//     final := len(ratings)
//     if final == 1 {
//         return 1
//     }

//     left := make([]int, final)
//     right := make([]int, final)

//     for i:=1;i<final;i++{
//         if ratings[i] > ratings[i-1] {
//             left[i]= left[i-1] + 1
//         }
//     }

//     for i:=final - 2;i>=0;i--{
//         if ratings[i] > ratings[i+1] {
//             right[i]= right[i+1] + 1
//         }
//     }
//     for i:=0;i<len(ratings);i++ {
//         if left[i] > right[i] {
//             final += left[i]
//         } else {
//             final += right[i]
//         }
//     }

//     return final
// }

func main() {
	ratings := []int{1, 2, 2}
	ret := candy(ratings)
	fmt.Println(ret)
}
