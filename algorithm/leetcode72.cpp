// 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符
// 示例 1:

// 输入: word1 = "horse", word2 = "ros"
// 输出: 3
// 解释: 
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')
// 示例 2:

// 输入: word1 = "intention", word2 = "execution"
// 输出: 5
// 解释: 
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int minDistance(string word1, string word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    if(len1 <= 0)
    {
        return len2;
    }
    if(len2 <= 0)
    {
        return len1;
    }
    vector<vector<int>> records(len1+1, vector<int>(len2+1, 0));
    for(int i = 0; i < len1+1; ++i)
    {
        records[i][0] = i;
    }
    for(int i = 0; i < len2+1; ++i)
    {
        records[0][i] = i;
    }
    for(int i = 1; i < len1+1; ++i)
    {
        for(int j = 1; j < len2+1; ++j)
        {
            records[i][j] = min(min(records[i-1][j]+1, records[i][j-1]+1), records[i-1][j-1]+(word1[i-1] == word2[j-1]? 0: 1));
        }
    }
    return records[len1][len2];
}

int main()
{
    string str1 = "horse";
    string str2 = "ros";
    cout << str1 << " and  " << str2 << " is " << minDistance(str1, str2) << endl;

    str1 = "intention";
    str2 = "execution";
    cout << str1 << " and  " << str2 << " is " << minDistance(str1, str2) << endl;

    return 1;
}