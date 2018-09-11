// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

// 示例 1:

// 输入: num1 = "2", num2 = "3"
// 输出: "6"
// 示例 2:

// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
// 说明：

// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2)
{
    if(num1.empty() || num2.empty())
    {
        return "";
    }
    if(num1 == "0" || num2 == "0")
    {
        return "0";
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string ret;
    int len1 = num1.length(), len2 = num2.length(), carry = 0;
    for(int i = 0; i < len1; ++i)
    {
        int pos = i;
        for(int j = 0; j < len2; ++j)
        {
            int temp = (num1[i]-'0') * (num2[j]-'0') + carry;
            if(pos < ret.length())
            {
                temp += (ret[pos]-'0');
                ret[pos] = temp%10-'0';
            }else{
                ret.append(1, temp%10+'0');
            }
            carry = temp/10;
            pos++;
        }
        if(carry > 0)
        {
            ret.append(1, carry+'0');
        }
        carry = 0;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    string str1 = "2";
    string str2 = "3";
    cout << str1 << " + " << str2 << " : " << multiply(str1, str2) << endl;

    str1 = "123";
    str2 = "456";
    cout << str1 << " + " << str2 << " : " << multiply(str1, str2) << endl;

    return 1;
}