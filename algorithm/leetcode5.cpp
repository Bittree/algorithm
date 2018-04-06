// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 长度最长为1000。

// 示例:

// 输入: "babad"

// 输出: "bab"

// 注意: "aba"也是有效答案
 

// 示例:

// 输入: "cbbd"

// 输出: "bb"

#include <iostream>
#include <string>

string longestPalindrome(string s) {
        int max_start = 0, max_end = 0, max = 0;
	    int len = s.length();
	    for (int index = 0; index < len; ++index)
	    {
		    int c = 0;
		    for(int i = 0; i <= index && index + i < len; ++i)
		    {
			    if (s[index - i] != s[index + i])break;
			    c = i * 2 + 1;
		    }
		    if (c > max)
		    {
			    max = c;
			    max_start = index - c/2;
			    max_end = index + c/2;
		    }

		    c = 0;
		    for (int j = 0; j <= index && index + j + 1 < len; ++j)
		    {
			    if (s[index - j] != s[index + j + 1])break;
			    c = (j + 1) * 2;
		    }
		    if (c > max)
		    {
			    max = c;
			    max_start = index - (c/2 - 1);
			    max_end = index + (c/2 - 1) + 1;
		    }
	    }
	    string ret;
	    ret.append(s, max_start, max_end - max_start + 1);
	    return ret;
}

int main()
{
	cout << longestPalindrome("cbbd").c_str() << endl;
    cout << longestPalindrome("noon").c_str() << endl;
    cout << longestPalindrome("a").c_str() << endl;
    return 0;
}
