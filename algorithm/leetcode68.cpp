// 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

// 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

// 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

// 文本的最后一行应为左对齐，且单词之间不插入额外的空格。

// 说明:

// 单词是指由非空格字符组成的字符序列。
// 每个单词的长度大于 0，小于等于 maxWidth。
// 输入单词数组 words 至少包含一个单词。
// 示例:

// 输入:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// 输出:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// 示例 2:

// 输入:
// words = ["What","must","be","acknowledgment","shall","be"]
// maxWidth = 16
// 输出:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
//      因为最后一行应为左对齐，而不是左右两端对齐。
//      第二行同样为左对齐，这是因为这行只包含一个单词。
// 示例 3:

// 输入:
// words = ["Science","is","what","we","understand","well","enough","to","explain",
//          "to","a","computer.","Art","is","everything","else","we","do"]
// maxWidth = 20
// 输出:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]

#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int size = words.size();
    vector<string> ret;
    int cur_len = 0;
    vector<string> cur_words;
    for (int i = 0; i < size; ++i)
    {
        int word_len = words[i].length();
        if (cur_len + word_len > maxWidth)
        {
            string str;
            int cur_size = cur_words.size();
            int total_blank = maxWidth - (cur_len - cur_size);
            int blank_size = cur_size > 1 ? (total_blank / (cur_size - 1)) : total_blank;
            int remainder = cur_size > 1 ? (total_blank % (cur_size - 1)) : 0;
            for (int j = 0; j < cur_size; ++j)
            {
                str.append(cur_words[j]);
                if (total_blank > 0)
                {
                    str.append(blank_size, ' ');
                    total_blank -= blank_size;
                }
                if (remainder > 0)
                {
                    str.append(1, ' ');
                    --remainder;
                    --total_blank;
                }
            }
            ret.push_back(str);
            cur_words.clear();
            cur_len = 0;
            --i;
        }
        else if (cur_len + word_len == maxWidth)
        {
            string str;
            for (auto ele : cur_words)
            {
                str.append(ele);
                str.append(1, ' ');
            }
            str.append(words[i]);
            ret.push_back(str);
            cur_words.clear();
            cur_len = 0;
        }
        else
        {
            cur_words.push_back(words[i]);
            // 加上一个空格做间隔
            cur_len += (word_len + 1);
            if (i == size - 1)
            {
                string str;
                for (auto ele : cur_words)
                {
                    str.append(ele);
                    str.append(1, ' ');
                }
                str.append(maxWidth - cur_len, ' ');
                ret.push_back(str);
            }
        }
    }

    return ret;
}

int main()
{
    vector<string> words;
    int maxWidth = 0;

    words.clear();
    maxWidth = 16;
    array<string, 7> vec1 = {"This", "is", "an", "example", "of", "text", "justification."};
    for (auto ele : vec1)
    {
        words.push_back(ele);
    }
    auto result = fullJustify(words, maxWidth);
    for (auto ele : result)
    {
        cout << ele << endl;
    }
    cout << "------------------------------------" << endl;

    words.clear();
    maxWidth = 16;
    array<string, 6> vec2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    for (auto ele : vec2)
    {
        words.push_back(ele);
    }
    result = fullJustify(words, maxWidth);
    for (auto ele : result)
    {
        cout << ele << endl;
    }
    cout << "------------------------------------" << endl;

    words.clear();
    maxWidth = 20;
    array<string, 18> vec3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    for (auto ele : vec3)
    {
        words.push_back(ele);
    }
    result = fullJustify(words, maxWidth);
    for (auto ele : result)
    {
        cout << ele << endl;
    }

    return 1;
}