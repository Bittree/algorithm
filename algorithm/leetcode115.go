// 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。

// 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

// 示例 1:

// 输入: S = "rabbbit", T = "rabbit"
// 输出: 3
// 解释:

// 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
// (上箭头符号 ^ 表示选取的字母)

// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^

// 示例 2:

// 输入: S = "babgbag", T = "bag"
// 输出: 5
// 解释:

// 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。
// (上箭头符号 ^ 表示选取的字母)

// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^

package main

import "fmt"

// 递归碰到超长用例会超时
// func helper(s string, t string, s_index int, t_index int) int {
// 	if t_index >= len(t) {
// 		return 1
// 	}
// 	sum := 0
// 	for i := s_index; i < len(s); i++ {
// 		if s[i] == t[t_index] {
// 			ret := helper(s, t, i+1, t_index+1)
// 			sum += ret
// 		}
// 	}
// 	return sum
// }

// func numDistinct(s string, t string) int {
// 	return helper(s, t, 0, 0)
// }

// dp[i][j] s的前i+1个字符和t的前j+1个字符的匹配
// s[i] == t[j], dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
// s[i] != t[j], dp[i][j] = dp[i-1][j]
func numDistinct(s string, t string) int {
	s_len := len(s)
	t_len := len(t)
	dp := make([][]int, s_len+1)
	for i := 0; i <= s_len; i++ {
		dp[i] = make([]int, t_len+1)
		dp[i][0] = 1
	}
	for i := 1; i <= s_len; i++ {
		for j := 1; j <= t_len; j++ {
			if s[i-1] != t[j-1] {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
			}
		}
	}
	return dp[s_len][t_len]
}

func main() {
	s := "rabbbit"
	t := "rabbit"
	ret := numDistinct(s, t)
	fmt.Println("s: ", s, " t: ", t, " ret: ", ret)

	s = "babgbag"
	t = "bag"
	ret = numDistinct(s, t)
	fmt.Println("s: ", s, " t: ", t, " ret: ", ret)
}
