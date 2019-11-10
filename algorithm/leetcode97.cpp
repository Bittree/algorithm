// 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

// 示例 1:

// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// 输出: true

// 示例 2:

// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// 输出: false

#include<iostream>
#include<string>

using namespace std;

// bool IsInterLeave(string& s1, int s1_index, string& s2, int s2_index, string& s3, int s3_index)
// {
//     for(int i = s3_index; i < s3.length(); ++i)
//     {
//         if(s1.size() > s1_index && s1[s1_index] == s3[i] && (s2.size() <= s2_index || s2[s2_index] != s3[i]))
//         {
//             ++s1_index;
//         }
//         else if(s2.size() > s2_index && s2[s2_index] == s3[i] && (s1.size() <= s1_index || s1[s1_index] != s3[i]))
//         {
//             ++s2_index;
//         }
//         else if((s1.size() <= s1_index || (s1.size() > s1_index && s1[s1_index] != s3[i])) && ((s2.size() > s2_index && s2[s2_index] != s3[i]) || s2.size() <= s2_index))
//         {
//             return false;
//         }
//         else
//         {
//             return IsInterLeave(s1, s1_index+1, s2, s2_index, s3, i+1) || IsInterLeave(s1, s1_index, s2, s2_index+1, s3, i+1);
//         }
//     }
//     return true;
// }

// bool isInterleave(string s1, string s2, string s3) 
// {
//     if(s1.size() + s2.size() != s3.size())
//     {
//         return false;
//     }
    
//     return IsInterLeave(s1, 0, s2, 0, s3, 0);
// }

// dp[0][0] = true
// dp[i][j] = (dp[i-1][j] && (s1[i] == s3[i+j]) || (dp[i][j-1] && (s2[j] == s3[i+j])))
bool isInterleave(string s1, string s2, string s3) 
{
    if(s1.size() + s2.size() != s3.size())
    {
        return false;
    }
    
    bool dp[s1.length()+1][s2.length()+1];
    for(int i = 0; i <= s1.length(); ++i)
    {
        for(int j = 0; j <= s2.length(); ++j)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if(i > 0 && j == 0)
            {
                dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i-1]);
            }
            else if(i == 0 && j > 0)
            {
                dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[j-1]);
            }
            else
            {
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
    }
    return dp[s1.length()][s2.length()];
}

int main()
{
    //string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    //string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    //string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    string s1 = "aabc";
    string s2 = "abad";
    string s3 = "aabcabad";
    bool ret = isInterleave(s1, s2, s3);
    cout << boolalpha << ret << endl;

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    ret = isInterleave(s1, s2, s3);
    cout << boolalpha << ret;
    return 1;
}