// 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符。
// '*' 匹配零个或多个前面的元素。
// 匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

// 说明:

// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
// 示例 1:

// 输入:
// s = "aa"
// p = "a"
// 输出: false
// 解释: "a" 无法匹配 "aa" 整个字符串。
// 示例 2:

// 输入:
// s = "aa"
// p = "a*"
// 输出: true
// 解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
// 示例 3:

// 输入:
// s = "ab"
// p = ".*"
// 输出: true
// 解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
// 示例 4:

// 输入:
// s = "aab"
// p = "c*a*b"
// 输出: true
// 解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
// 示例 5:

// 输入:
// s = "mississippi"
// p = "mis*is*p*."
// 输出: false

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 普通递归算法
bool isMatch(string s, string p) {
	auto slen = s.length();
	auto plen = p.length();
	if (plen == 0)
	{
		return slen == 0;
	}
	if (plen == 1)
	{
		if (s.compare(p) == 0 || (p.compare(".") == 0 && slen == 1))
		{
			return true;
		}
		else {
			return false;
		}
	}
	// 优化速度
	if (p[plen - 1] != '*' && p[plen - 1] != '.' && s.find(p[plen - 1]) == string::npos)
	{
		return false;
	}
	if (p[1] == '*')
	{
		while (s.length() > 0 && (p[0] == '.' || s[0] == p[0]))
		{
			if (isMatch(s, p.substr(2)))
			{
				return true;
			}
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
	else {
		if (slen > 0 && (p[0] == '.' || s[0] == p[0])) {
			return isMatch(s.substr(1), p.substr(1));
		}
		else {
			return false;
		}
	}
}

// dp算法
bool isMatch2(string s, string p)
{
	auto slen = s.length() + 1;
	auto plen = p.length() + 1;
	vector<vector<bool>> f(slen, vector<bool>(plen, false));
	f[0][0] = true;
	for (int i = 0; i < slen; i++)
	{
		for (int j = 1; j < plen; j++)
		{
			if (i > 0 && (s[i-1] == p[j-1] || p[j-1] == '.'))
			{
				f[i][j] = f[i - 1][j-1];
			}
			if (p[j-1] == '*')
			{
				if (i == 0 || s[i-1] != p[j-2] && p[j-2] != '.')
				{
					f[i][j] = f[i][j-2];
				} 
				else
				{
					f[i][j] = f[i-1][j] || f[i][j-1] || f[i][j-2];
				}
			}
		}
	}
    return f[slen - 1][plen - 1];
}

int main()
{
	cout << isMatch2("a", ".*..a*") << endl;

	return 0;
}