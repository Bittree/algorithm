// 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

// 示例 1:

// 输入: 2.00000, 10
// 输出: 1024.00000
// 示例 2:

// 输入: 2.10000, 3
// 输出: 9.26100
// 示例 3:

// 输入: 2.00000, -2
// 输出: 0.25000
// 解释: 2-2 = 1/22 = 1/4 = 0.25
// 说明:

// -100.0 < x < 100.0
// n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

#include <iostream>

using namespace std;

double myPow(double x, int n)
{
    if (x <= -100 || x >= 100)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (n == 1 || x == 0 || x == 1)
    {
        return x;
    }
    unsigned int un = n;
    if (n < 0)
    {
        x = 1 / x;
        un = -n;
    }
    double ret = 1;
    while (un > 1)
    {
        if (un % 2 == 1)
        {
            ret *= x;
            --un;
        }
        x *= x;
        un /= 2;
    }

    return ret * x;
}

int main()
{
    double x = 2.0;
    int n = 10;
    cout << x << ", " << n << ": " << myPow(x, n) << endl;

    x = 2.1;
    n = 3;
    cout << x << ", " << n << ": " << myPow(x, n) << endl;

    x = 2.0;
    n = -2;
    cout << x << ", " << n << ": " << myPow(x, n) << endl;

    x = 2.0;
    n = -2147483648;
    cout << x << ", " << n << ": " << myPow(x, n) << endl;

    return 1;
}