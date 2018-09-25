// 给定两个二进制字符串，返回他们的和（用二进制表示）。

// 输入为非空字符串且只包含数字 1 和 0。

// 示例 1:

// 输入: a = "11", b = "1"
// 输出: "100"
// 示例 2:

// 输入: a = "1010", b = "1011"
// 输出: "10101"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    string stra(a.rbegin(), a.rend()), strb(b.rbegin(), b.rend()), ret;
    int index = 0, carry = 0;
    while (index < stra.length() || index < strb.length() || carry > 0)
    {
        int numa = index < stra.length() ? stra[index] - '0' : 0;
        int numb = index < strb.length() ? strb[index] - '0' : 0;
        int sum = numa + numb + carry;
        ret.append(1, sum % 2 + '0');
        carry = sum / 2;
        ++index;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    string a = "11";
    string b = "1";
    string result = addBinary(a, b);
    cout << "a: " << a << ", b: " << b << ", result: " << result << endl;

    a = "1010";
    b = "1011";
    result = addBinary(a, b);
    cout << "a: " << a << ", b: " << b << ", result: " << result << endl;

    return 1;
}