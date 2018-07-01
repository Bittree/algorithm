// 实现 strStr() 函数。

// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1:

// 输入: haystack = "hello", needle = "ll"
// 输出: 2
// 示例 2:

// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1
// 说明:

// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    int needlelen = needle.length();
    if(needlelen <= 0)
    {
        return 0;
    }
    
    int haystacklen = haystack.length();
    for(int i = 0; i <= haystacklen - needlelen; ++i)
    {
        bool found = true;
        for(int tmp = 0; tmp < needlelen; ++tmp)
        {
            if(haystack[i+tmp] != needle[tmp])
            {
                found = false;
                break;
            }
        }
        if(found)
        {
            return i;
        }
    }
    
    return -1;
}

int main()
{
    int  ret1 = strStr("hello", "ll");
    int  ret2 = strStr("a", "a");
    int  ret3 = strStr("hello", "");
    int  ret4 = strStr("hello", "bb");

	return 0;
}