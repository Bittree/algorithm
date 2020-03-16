// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

// 说明：

//     拆分时可以重复使用字典中的单词。
//     你可以假设字典中没有重复的单词。

// 示例 1：

// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

// 示例 2：

// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//      注意你可以重复使用字典中的单词。

// 示例 3：

// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false

package main

import (
	"fmt"
)

func wordBreak(s string, wordDict []string) bool {
	n := len(s)
	if n <= 0 {
		return true
	}
	records := make(map[string]bool)
	for _, v := range wordDict {
		records[v] = true
	}
	dp := make([]bool, n+1)
	dp[0] = true
	for i := 0; i < n; i++ {
		for j := i+1; j < n+1; j++ {
			if dp[i] {
				_, ok := records[s[i:j]]
				if ok {
					dp[j] = true
				}
			}
		}
	}
	return dp[n]
}

func main() {
	s := "leetcode"
	wordDict := []string{"leet", "code", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}
	ret := wordBreak(s, wordDict)
	fmt.Println(ret)
}
