// 报数序列是指一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 被读作  "one 1"  ("一个一") , 即 11。
// 11 被读作 "two 1s" ("两个一"）, 即 21。
// 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

// 给定一个正整数 n ，输出报数序列的第 n 项。

// 注意：整数顺序将表示为一个字符串。

// 示例 1:

// 输入: 1
// 输出: "1"
// 示例 2:

// 输入: 4
// 输出: "1211"

#include<iostream>
#include<string>

using namespace std;

string countAndSay(int n)
{
    string cur = "";
    for(int i = 0; i < n; ++i)
    {
        if(cur.empty())
        {
            cur.append("1");
            continue;
        }

        string tmp;
        int index = 0, len = cur.length();
        while(index < len)
        {
            int count = 1;
            while(index+count<len && cur[index] == cur[index+count])
            {
                count++;
            }
            tmp.append(to_string(count));
            tmp += cur[index];
            index += count;
        }
        cur = tmp;
    }
    return cur;
}

int main()
{
    int input = 1;
    cout << input << " : " << countAndSay(input) << endl;

    input = 2;
    cout << input << " : " << countAndSay(input) << endl;

    input = 3;
    cout << input << " : " << countAndSay(input) << endl;

    input = 4;
    cout << input << " : " << countAndSay(input) << endl;

    input = 5;
    cout << input << " : " << countAndSay(input) << endl;
}