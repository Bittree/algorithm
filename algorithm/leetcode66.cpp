// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

// 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

// 你可以假设除了整数 0 之外，这个整数不会以零开头。

// 示例 1:

// 输入: [1,2,3]
// 输出: [1,2,4]
// 解释: 输入数组表示数字 123。
// 示例 2:

// 输入: [4,3,2,1]
// 输出: [4,3,2,2]
// 解释: 输入数组表示数字 4321。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    vector<int> ret(digits.rbegin(), digits.rend());
    int carry = 1, index = 0, size = digits.size();
    while (carry > 0)
    {
        if (index < size)
        {
            int sum = carry + ret[index];
            carry = sum / 10;
            ret[index] = sum % 10;
        }
        else
        {
            ret.push_back(carry % 10);
            carry = carry / 10;
        }
        ++index;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    for (auto ele : vec)
    {
        cout << ele;
    }
    cout << " : ";
    auto result = plusOne(vec);
    for (auto ele : result)
    {
        cout << ele;
    }
    cout << endl;

    vec.clear();
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    for (auto ele : vec)
    {
        cout << ele;
    }
    cout << " : ";
    result = plusOne(vec);
    for (auto ele : result)
    {
        cout << ele;
    }
    cout << endl;

    vec.clear();
    vec.push_back(9);
    for (auto ele : vec)
    {
        cout << ele;
    }
    cout << " : ";
    result = plusOne(vec);
    for (auto ele : result)
    {
        cout << ele;
    }
    cout << endl;

    return 1;
}