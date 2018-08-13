// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

// 返回被除数 dividend 除以除数 divisor 得到的商。

// 示例 1:

// 输入: dividend = 10, divisor = 3
// 输出: 3
// 示例 2:

// 输入: dividend = 7, divisor = -3
// 输出: -2
// 说明:

// 被除数和除数均为 32 位有符号整数。
// 除数不为 0。
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

#include <iostream>
#include<limits.h>

using namespace std;

// 是否是正数
int isPositive(int num)
{
    return (num >> 31) == 0;
}

// 两数相加，异或表示加不算进位的结果，与表示相加进位的结果
int add(int num1, int num2)
{
    int s=0, c=0;
    while(num2 != 0)
    {
        s = num1 ^ num2;
        c = (num1 & num2) << 1;
        num1 = s;
        num2 = c;
    }
    return num1;
}

// 求负数，连符号位一起取反之后加1
int negtive(int num)
{
    return add(~num, 1);
}

int sub(int num1, int num2)
{
    return add(num1, negtive(num2));
}

int abs(int num)
{
    if(isPositive(num))
    {
        return num;
    }else{
        return negtive(num);
    }
}

int divide(int dividend, int divisor)
{
    if(dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }

    bool diffSign = false;
    if(isPositive(dividend) != isPositive(divisor))
    {
        diffSign = true;
    }
    unsigned int u_dividend = abs(dividend);
    unsigned int u_divisor = abs(divisor);

    int ret = 0, count = 31;
    while(count >= 0)
    {
        if((u_dividend >> count) >= u_divisor)
        {
            ret = add(ret, (1<<count));
            u_dividend = sub(u_dividend, (u_divisor << count));
        }
        count = sub(count, 1);
    }

    return diffSign ? negtive(ret) : ret;
}

int main()
{
    cout << INT_MAX << "/" << INT_MIN << " = " << divide(INT_MAX, INT_MIN) << endl;
    cout << INT_MIN << "/" << INT_MAX << " = " << divide(INT_MIN, INT_MAX) << endl;
    cout << INT_MAX << "/" << INT_MAX << " = " << divide(INT_MAX, INT_MAX) << endl;
    cout << INT_MIN << "/" << INT_MIN << " = " << divide(INT_MIN, INT_MIN) << endl;
    cout << INT_MIN << "/" << -1 << " = " << divide(INT_MIN, -1) << endl;
    cout << INT_MIN << "/" << 1 << " = " << divide(INT_MIN, 1) << endl;
    cout << INT_MAX << "/" << -1 << " = " << divide(INT_MAX, -1) << endl;
    cout << INT_MAX << "/" << 1 << " = " << divide(INT_MAX, 1) << endl;
    cout << 0 << "/" << INT_MAX << " = " << divide(0, INT_MAX) << endl;
    cout << 0 << "/" << INT_MIN << " = " << divide(0, INT_MIN) << endl;
	return 0;
}
