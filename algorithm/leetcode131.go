// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

// 返回 s 所有可能的分割方案。

// 示例:

// 输入: "aab"
// 输出:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

package main

import "fmt"

func isPalindrome(s string) bool {
	for l, r := 0, len(s)-1; l < r; l, r = l+1, r-1 {
		if s[l] != s[r] {
			return false
		}
	}
	return true
}

func dfs(s string) {
	size := len(s)
	if size <= 0 {
		newslice := make([]string, len(path))
		copy(newslice, path)
		records = append(records, newslice)
		return
	}
	for i := 1; i <= size; i++ {
		substr := s[0:i]
		if isPalindrome(substr) {
			path = append(path, substr)
			dfs(s[i:])
			path = path[:len(path)-1]
		}
	}
}

var records [][]string
var path []string

func partition(s string) [][]string {
	records = [][]string{}
	if len(s) <= 0 {
		return records
	}
	path = []string{}
	dfs(s)
	return records
}

func main() {
	s := "aab"
	ret := partition(s)
	fmt.Println("s: ", s)
	fmt.Println("[")
	for _, arr := range ret {
		fmt.Print("   [")
		for _, v := range arr {
			fmt.Print(v, " ")
		}
		fmt.Println("],")
	}
	fmt.Println("]")
}
