// 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

// '?' 可以匹配任何单个字符。
// '*' 可以匹配任意字符串（包括空字符串）。
// 两个字符串完全匹配才算匹配成功。

// 说明:

// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
// 示例 1:

// 输入:
// s = "aa"
// p = "a"
// 输出: false
// 解释: "a" 无法匹配 "aa" 整个字符串。
// 示例 2:

// 输入:
// s = "aa"
// p = "*"
// 输出: true
// 解释: '*' 可以匹配任意字符串。
// 示例 3:

// 输入:
// s = "cb"
// p = "?a"
// 输出: false
// 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// 示例 4:

// 输入:
// s = "adceb"
// p = "*a*b"
// 输出: true
// 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
// 示例 5:

// 输入:
// s = "acdcb"
// p = "a*c?b"
// 输入: false

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// 超时
bool match(string& s, string& p, int spos, int ppos)
{
    int slen = s.length(), plen = p.length();
    if(slen == 0 && (plen == 0 || p.compare("*") == 0))
    {
        return true;
    }
    while(ppos < plen && spos < slen)
    {
        if(p[ppos] == '?')
        {
            spos++;
			ppos++;
        }else if(p[ppos] == '*')
        {
            if(ppos == plen-1)
            {
                return true;
            }
            if(ppos == 0 || ppos>0 && p[ppos-1]!='*')
            {
                for(int j = spos+1; j < slen; ++j)
                {
                    if(match(s, p, j, ppos+1))
                    {
                        return true;
                    }
                }
            }
			ppos++;
        }else{
            if(p[ppos] != s[spos])
            {
                return false;
            }
            spos++;
			ppos++;
        }
    }

    if(spos >= slen && ppos < plen)
    {
        for(int i = ppos; i < plen; ++i)
        {
            if(p[i] != '*')
            {
                return false;
            }
        }
        return true;
    }else if(spos == slen && ppos == plen)
    {
        return true;
    }

    return false;
}

// bool isMatch(string s, string p)
// {
//     return match(s, p, 0, 0);
// }

bool isMatch(string s, string p)
{
    auto slen = s.length() + 1;
	auto plen = p.length() + 1;
	vector<vector<bool>> f(slen, vector<bool>(plen, false));
	f[0][0] = true;
    for(int j = 1; j < plen; j++)
    {
        if(p[j-1] == '*')
        {
            f[0][j] = true;
        }else{
            break;
        }
    }
	for (int i = 1; i < slen; i++)
	{
		for (int j = 1; j < plen; j++)
		{
			if(p[j-1] != '*')
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                {
                    f[i][j] = f[i-1][j-1];
                }
            }else{
                f[i][j] = f[i-1][j] || f[i][j-1];
            }
		}
	}
    return f[slen - 1][plen - 1];
}

int main()
{
    string s = "aa", p = "a";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "aa", p = "a*";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "cb", p = "?a";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "adceb", p = "*a*b";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "acdcb", p = "a*c?b";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "ab", p = "?*";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "aa", p = "aa";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "", p = "";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "", p = "*";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "a", p = "a*";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "b", p = "?";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "aaaa", p = "***a";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    s = "aab", p = "c*a*b";
    cout << "s = " << s << " p = " << p << " : " << boolalpha << isMatch(s, p) << endl;

    return 1;
}