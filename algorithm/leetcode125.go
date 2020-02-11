// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

// 说明：本题中，我们将空字符串定义为有效的回文串。

// 示例 1:

// 输入: "A man, a plan, a canal: Panama"
// 输出: true

// 示例 2:

// 输入: "race a car"
// 输出: false

package main

import "fmt"

func isAvailable(c byte) bool {
	if (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') {
		return true
	} else {
		return false
	}
}

func toLower(c byte) byte {
	if c >= 'A' && c <= 'Z' {
		return c - 'A' + 'a'
	}
	return c
}

func isPalindrome(s string) bool {
	n := len(s)
	if n <= 0 {
		return true
	}
	p1 := 0
	p2 := n - 1
	for {
		if p1 >= p2 {
			break
		}
		if !isAvailable(s[p1]) {
			p1++
		} else if !isAvailable(s[p2]) {
			p2--
		} else {
			if toLower(s[p1]) != toLower(s[p2]) {
				return false
			}
			p1++
			p2--
		}
	}
	return true
}

func main() {
	s := "A man, a plan, a canal: Panama"
	ret := isPalindrome(s)
	fmt.Println(s, " -> ", ret)

	s = "race a car"
	ret = isPalindrome(s)
	fmt.Println(s, " -> ", ret)

	s = "0P"
	ret = isPalindrome(s)
	fmt.Println(s, " -> ", ret)
}
