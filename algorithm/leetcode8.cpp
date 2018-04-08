// 实现 atoi，将字符串转为整数。

// 提示：仔细考虑所有输入情况。如果你想挑战自己，请不要看下面并自己考虑所有可能的输入情况。

// 说明：这题解释的比较模糊（即没有指定输入格式）。你得事先汇集所有的输入情况。

 

// atoi的要求：

// 这个函数需要丢弃之前的空白字符，直到找到第一个非空白字符。之后从这个字符开始，选取一个可选的正号或负号后面跟随尽可能多的数字，并将其解释为数字的值。

// 字符串可以在形成整数的字符后包括多余的字符，将这些字符忽略，这些字符对于函数的行为没有影响。

// 如果字符串中的第一个非空白的字符不是有效的整数，或者没有这样的序列存在，字符串为空或者只包含空白字符则不进行转换。

// 如果不能执行有效的转换，则返回 0。如果正确的值超过的可表示的范围，则返回 INT_MAX（2147483647）或 INT_MIN（-2147483648）。

#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str) {
	int startIndex = -1, ret = 0, mul = 1;
	int len = str.length();
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '-')
		{
			if (startIndex == -1)
			{
				mul = -1;
				startIndex = i + 1;
			}
			break;
		}
		else if (str[i] == '+') {
			if (startIndex == -1)
			{
				mul = 1;
				startIndex = i + 1;
			}
			break;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			if (startIndex == -1)
			{
				startIndex = i;
				mul = 1;
			}
			break;
		}
		else {
			if (str[i] != ' ' && startIndex == -1)
			{
				return 0;
			}
		}
	}
	if (startIndex >= 0) {
		for (int j = startIndex; j < len; ++j)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{
				if (ret + (str[j] - '0') / 10.0 > INT_MAX / 10.0)
				{
					return mul > 0 ? INT_MAX : INT_MIN;
				}
				ret = ret * 10 + (str[j] - '0');
			}
			else {
				break;
			}
		}
		return ret * mul;
	}

	return 0;
}

int main()
{
	cout << myAtoi("2147483648") << endl;
	cout << myAtoi("-2147483647") << endl;
    return 0;
}