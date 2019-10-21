// 一条包含字母 A-Z 的消息通过以下方式进行了编码：

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

// 给定一个只包含数字的非空字符串，请计算解码方法的总数。

// 示例 1:

// 输入: "12"
// 输出: 2
// 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

// 示例 2:

// 输入: "226"
// 输出: 3
// 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

#include<iostream>
#include <string>

using namespace std;

// DP题，分情况讨论，建立最优子结构：
// 若s[i] ='0', 如果s[i-1]='1' or '2',则dp[i]=dp[i-2],否则返回0；
// 若s[i-1] = '1'或者s[i-1]='2' && s[i]>='1'&&s[i]<='6', 则dp[i]=dp[i-1]+dp[i-2];因为当s[i]和s[i-1]作为两个数分开的时候是dp[i-1],合起来作为一个数的时候是dp[i-2]

int numDecodings(string s)
{
	int ret = 1, last = 1;
	if (s[0] == '0')
	{
		return 0;
	}
	for (int i = 1; i < s.size(); ++i)
	{
		int tmp = ret;
		if (s[i] == '0')
		{
			if (s[i - 1] != '1' && s[i - 1] != '2')
			{
				return 0;
			}
			else
			{
				ret = last;
			}
		}
		else if (s[i - 1] == '1' || (s[i - 1] == '2' && (s[i] >= '0' && s[i] <= '6')))
		{
			ret += last;
		}
		last = tmp;
	}
	return ret;
}

int main()
{
    string para = "27";
    int ret = numDecodings(para);
    cout << para << ":" << ret << endl;
    return 1;
}