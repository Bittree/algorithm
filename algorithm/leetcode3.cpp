/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    //map[s]表示当前的字符s在串中出现的位置（从0开始），大于0表示出现过了
	//i表示当前字符的索引
	//j表示到当前字符一共有几个字符重复了
    int max = 0;
    int start_index = 0;
    int j=0;
    map<char,int> temp;
    for(int i=0;i < s.length();++i)
    {
        if(temp[s[i]] > 0)j = j>=temp[s[i]]?j:temp[s[i]];
        temp[s[i]]=i+1;
        max = max>=(i-j+1)?max:(i-j+1); 
    }
    return max;
}

int main()
{
    string str("abcaebcdbb");
    cout << lengthOfLongestSubstring(str) << endl;
    return 0;
}