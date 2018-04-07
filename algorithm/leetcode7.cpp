// 给定一个范围为 32 位 int 的整数，将其颠倒。

// 例 1:

// 输入: 123
// 输出:  321
 

// 例 2:

// 输入: -123
// 输出: -321
 

// 例 3:

// 输入: 120
// 输出: 21
 

// 注意:

// 假设我们的环境只能处理 32 位 int 范围内的整数。根据这个假设，如果颠倒后的结果超过这个范围，则返回 0。

#include <iostream>

using namespace std;

int reverse(int x) {
	int ret = 0;
	while (x != 0)
	{
		if (ret > INT_MAX / 10 || ret < INT_MIN / 10) 
		{
			return 0;
		}
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

int main()
{
	cout << reverse(1534236469) << endl;
    return 0;
}