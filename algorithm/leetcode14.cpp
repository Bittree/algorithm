// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:

// 输入: ["flower","flow","flight"]
// 输出: "fl"
// 示例 2:

// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。
// 说明:

// 所有输入只包含小写字母 a-z 。

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string ret = "";
    bool flag = false;
    for(auto str : strs)
    {
        if(!flag) 
        {
            ret = str;
            flag = true;
            continue;
        }
        int slen = ret.length();
        int strlen = str.length();
        if(slen > strlen)
        {
            slen = strlen;
            ret = ret.substr(0, slen);
        }
        
        for(int i = 0; i < slen; ++i)
        {
            if(ret[i] != str[i])
            {
                if(i == 0)
                {
                    return "";
                }
                ret = ret.substr(0, i);
                break;
            }
        }
    }
    return ret;
}

int main()
{
    vector<string> arr;
    arr.push_back("aa");
    arr.push_back("a");
	cout << longestCommonPrefix("MCMXCIV") << endl;

	return 0;
}