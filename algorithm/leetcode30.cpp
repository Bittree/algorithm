// 给定一个字符串 s 和一些长度相同的单词 words。在 s 中找出可以恰好串联 words 中所有单词的子串的起始位置。

// 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

// 示例 1:

// 输入:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// 输出: [0,9]
// 解释: 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
// 输出的顺序不重要, [9,0] 也是有效答案。
// 示例 2:

// 输入:
//   s = "wordgoodstudentgoodword",
//   words = ["word","student"]
// 输出: []

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> ret;
    int str_len = s.length();
    int words_len = words.size();
    if(str_len == 0 | words_len == 0)
    {
        return ret;
    }

    int word_len = words[0].length();
    int words_total_len = word_len * words_len;
    if(str_len < words_total_len)
    {
        return ret;
    }

    unordered_map<string, int> word_map;
    for(int i = 0; i < words_len; ++i)
    {
        word_map[words[i]]++;
    }

    unordered_map<string, int> tmp_map;
    for(int i = 0; i < str_len - words_total_len + 1; ++i)
    {
        
        int j = i;
        tmp_map.clear();
        while(j - i + 1 <= words_total_len)
        {
            string substr = s.substr(j, word_len);
            tmp_map[substr]++;
            if(tmp_map[substr] > word_map[substr])
            {
                break;
            }else{
                j += word_len;
            }
            if(j - i + 1 > words_total_len)
            {
                ret.push_back(i);
            }
        }
    }

    return ret;
}

int main()
{
    vector<string> words1;
    words1.push_back("bar");
    words1.push_back("foo");
    auto result1 = findSubstring("barfoothefoobarman", words1);
    for(auto ele : result1)
    {
        cout << ele << endl;
    }

    vector<string> words2;
    words2.push_back("word");
    words2.push_back("student");
    auto result2 = findSubstring("wordgoodstudentgoodword", words2);
    for(auto ele : result2)
    {
        cout << ele << endl;
    }

    return 0;
}