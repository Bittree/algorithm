// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

// 说明：

//     分隔时可以重复使用字典中的单词。
//     你可以假设字典中没有重复的单词。

// 示例 1：

// 输入:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// 输出:
// [
//   "cats and dog",
//   "cat sand dog"
// ]

// 示例 2：

// 输入:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// 输出:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// 解释: 注意你可以重复使用字典中的单词。

// 示例 3：

// 输入:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出:
// []

package main

import (
	"fmt"
)

var records map[string][]string
func wordBreak(s string, wordDict []string) []string {
	records = make(map[string][]string)
	if len(s)>0 && len(wordDict)>0 {
		return helper(s, wordDict)
	}
	return []string{}
}

func helper(s string, wordDict []string) []string {
	_, ok := records[s]
	if ok {
		return records[s]
	}
	if len(s)<=0 {
		return []string{""}
	}
	tmp := []string{}
	for _, word := range wordDict {
		wordlen := len(word)
		var target string
		if wordlen > len(s) {
			target = s
		}else{
			target = s[:wordlen]
		}
		if word == target {
			words := helper(s[wordlen:], wordDict)
			for _, v := range words {
				if len(v) <= 0 {
					tmp = append(tmp, word)
				}else{
					tmp = append(tmp, word+" "+v)
				}
			}
		}
	}
	records[s] = tmp
	return tmp
}

func main() {
	s := "catsanddog"
	wordDict := []string{"cat", "cats", "and", "sand", "dog"}
	ret := wordBreak(s, wordDict)
	fmt.Println("[")
	for _, v := range ret {
		fmt.Println("	[", v, "]")
	}
	fmt.Println("]")
}