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

using namespace std;

bool hasFound(const string& s, int start_index, vector<string>& words)
{
    int words_len = words.size();
    if(words_len == 0)
    {
        return true;
    }

    for(int i = 0; i < words_len; ++i)
    {
        string& word = words[i];
        int word_len = word.length();

        if(s.compare(start_index, word_len, word) == 0)
        {
            vector<string> tmp = words;
            tmp.erase(tmp.begin() + i);
            if(hasFound(s, start_index+word_len, tmp))
            {
                return true;
            }
        }
    }

    return false;
}

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> ret;
    int str_len = s.length();
    int words_len = words.size();
    if(str_len == 0 | words_len == 0)
    {
        return ret;
    }

    int words_total_len = 0;
    for(int i = 0; i < words_len; ++i)
    {
        words_total_len += words[i].length();
    }
    if(str_len < words_total_len)
    {
        return ret;
    }

    for(int i = 0; i < str_len - words_total_len + 1; ++i)
    {
        if(hasFound(s, i, words))
        {
            ret.push_back(i);
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