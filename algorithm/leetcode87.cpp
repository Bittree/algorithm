// 给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

// 下图是字符串 s1 = "great" 的一种可能的表示形式。

//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t

// 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

// 例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t

// 我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

// 同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。

//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a

// 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

// 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

// 示例 1:

// 输入: s1 = "great", s2 = "rgeat"
// 输出: true

// 示例 2:

// 输入: s1 = "abcde", s2 = "caebd"
// 输出: false

#include<iostream>
#include <string>
#include<vector>

using namespace std;

bool isScramble(string s1, string s2) 
{
    if(s1.size() != s2.size())
    {
        return false;
    }
    if(s1 == s2)
    {
        return true;
    }
    vector<int> table(26, 0);
    for(int i = 0; i < s1.size(); ++i)
    {
        ++table[s1[i]-'a'];
    }
    for(int i = 0; i < s2.size(); ++i)
    {
        --table[s2[i]-'a'];
    }
    for(int i = 0; i < 26; ++i)
    {
        if(table[i] > 0)
        {
            return false;
        }
    }
    int size = s1.size();
    for(int i = 1; i < s1.size(); ++i)
    {
        if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, size - i), s2.substr(i, size - i))) ||
        (isScramble(s1.substr(0, i), s2.substr(size-i, i)) && isScramble(s1.substr(i, size-i), s2.substr(0, size-i))))
        {
            return true;
        }       
    }
    return false;
}

int main()
{
    bool ret = isScramble("abb", "bba");
    cout << boolalpha << ret <<endl;
    return 1;
}