// 实现 int sqrt(int x) 函数。

// 计算并返回 x 的平方根，其中 x 是非负整数。

// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

// 示例 1:

// 输入: 4
// 输出: 2
// 示例 2:

// 输入: 8
// 输出: 2
// 说明: 8 的平方根是 2.82842...,
//      由于返回类型是整数，小数部分将被舍去。

#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x)
{
    return floor(sqrt(x));
}

// 牛顿法开平方
// int mySqrt(int x)
// {
//     if (x == 0)
//     {
//         return 0;
//     }
//     if (x == 1 || x == 2 || x == 3) {
//         return 1;
//     }

//     double ans = x / 2.0;
//     while (fabs(ans * ans - x) > 0.5) {
//         ans = (ans + x / ans) / 2;
//     }
//     return ans;
// }