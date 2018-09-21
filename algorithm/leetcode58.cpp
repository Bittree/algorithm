// 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

// 如果不存在最后一个单词，请返回 0 。

// 说明：一个单词是指由字母组成，但不包含任何空格的字符串。

// 示例:

// 输入: "Hello World"
// 输出: 5

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
    int len = s.length();
    if (len <= 0)
    {
        return 0;
    }
    int count = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        if (s[i] == ' ')
        {
            if (count > 0)
                break;
        }
        else
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string str = "Hello World";
    cout << str << " : " << lengthOfLastWord(str) << endl;

    return 1;
}