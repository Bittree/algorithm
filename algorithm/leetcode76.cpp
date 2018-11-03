// 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

// 示例：

// 输入: S = "ADOBECODEBANC", T = "ABC"
// 输出: "BANC"
// 说明：

// 如果 S 中不存这样的子串，则返回空字符串 ""。
// 如果 S 中存在这样的子串，我们保证它是唯一的答案。

#include<iostream>
#include<string>
#include<unordered_map>
#include<limits>

using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> tmap, smap;
    for(char key : t)
    {
        tmap[key]++;
    }
    int slen = s.length(), tlen = t.length(), count = 0, begin = 0, end = 0, minlen = numeric_limits<int>::max(), minbegin = 0, minend = 0;
    for(; end < slen; ++end)
    {
        if(tmap.find(s[end]) == tmap.end())
        {
            continue;
        }
        if(smap.find(s[end]) == smap.end())
        {
            smap[s[end]] = 0;
        }
        smap[s[end]]++;
        // 只有当前字符在目标字符串内且还没达到目标字符串内该字符的数量，才把符合条件的字符数量加1
        if(tmap[s[end]] >= smap[s[end]])
        {
            count++;
        }
        // 如果符合条件的字符数到了目标字符串的长度，说明应该好了，可以尝试缩小当前窗口
        if(count >= tlen)
        {
            // 如果字符不在目标字符串内，或者当前字符串内的这个字符多于目标字符串内的这个字符
            // 说明这个字符可以被舍弃，窗口左边界可以向右滑动
            while(tmap.find(s[begin]) == tmap.end() || tmap[s[begin]] == 0 || tmap[s[begin]] < smap[s[begin]])
            {
                if(tmap[s[begin]] < smap[s[begin]])
                {
                    --smap[s[begin]];
                }
                ++begin;
            }
            // 这时已经是当前最短的字符串了，和之前记录的比较一下
            if(end-begin+1 < minlen)
            {
                minlen = end-begin+1;
                minbegin = begin;
                minend = end;
            }
        }
    }
    return minlen == numeric_limits<int>::max()? "": s.substr(minbegin, minend-minbegin+1);
}

int main()
{
    string input = "ADOBECODEBANC", target = "ABC";
    string result = minWindow(input, target);
    cout << "input: " << input << ", target: " << target << ", result: " << result << endl;

    return 1;
}