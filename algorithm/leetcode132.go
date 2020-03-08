// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

// 返回符合要求的最少分割次数。

// 示例:

// 输入: "aab"
// 输出: 1
// 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

package main

import "fmt"

func checkPalindrome(s string) [][]bool {
	len := len(s)
	ret := make([][]bool, len)
	for i := 0; i < len; i++ {
		ret[i] = make([]bool, len)
	}
	for right := 0; right < len; right++ {
		for left := 0; left <= right; left++ {
			if s[left] == s[right] && (right-left <= 2 || ret[left+1][right-1]) {
				ret[left][right] = true
			} else {
				ret[left][right] = false
			}
		}
	}
	return ret
}

func minCut(s string) int {
	len := len(s)
	if len < 2 {
		return 0
	}
	records := checkPalindrome(s)
	dp := make([]int, len)
	min := func(a, b int) int {
		if a < b {
			return a
		} else {
			return b
		}
	}
	for i := 0; i < len; i++ {
		if records[0][i] {
			dp[i] = 0
			continue
		}
		dp[i] = i
		for j := 0; j < i; j++ {
			if records[j+1][i] {
				dp[i] = min(dp[i], dp[j]+1)
			}
		}
	}
	return dp[len-1]
}

func main() {
	str := "aab"
	ret := minCut(str)
	fmt.Println(str, " : ", ret)
}
