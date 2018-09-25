// 验证给定的字符串是否为数字。

// 例如:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true

// 说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。

#include <iostream>
#include <string>

using namespace std;

bool check(string s, bool allowpoint)
{
	int len = s.length();
	if (len <= 0)
	{
		return false;
	}
	int index = 0;
	bool num1 = false;
	if (s[index] == '+' || s[index] == '-')
	{
		++index;
	}
	if (index >= len)
	{
		return false;
	}
	for (; index < len; ++index)
	{
		if (s[index] < '0' || s[index] > '9')
		{
			break;
		}
		else
		{
			num1 = true;
		}
	}
	if (index < len && !allowpoint)
	{
		return false;
	}
	if (index < len && s[index] == '.')
	{
		++index;
		int num2 = false;
		for (; index < len; ++index)
		{
			if (s[index] < '0' || s[index] > '9')
			{
				break;
			}
			else
			{
				num2 = true;
			}
		}
		if (!num1 && !num2)
		{
			return false;
		}
	}
	return index == len;
}

bool isNumber(string s)
{
	// 去掉头尾的空格，中间有空格的话就是错的
	while (s.length() > 0)
	{
		if (s[0] == ' ')
		{
			s = s.substr(1);
		}
		else
		{
			break;
		}
	}
	while (s.length() > 0)
	{
		if (s[s.length() - 1] == ' ')
		{
			s = s.substr(0, s.length() - 1);
		}
		else
		{
			break;
		}
	}
	if (s.length() <= 0)
	{
		return false;
	}
	auto epos = s.find('e');
	if (epos == string::npos)
	{
		return check(s, true);
	}
	else
	{
		// e前面允许有小数点，后面不允许有小数点，比如1.5e20
		return check(s.substr(0, epos), true) && check(s.substr(epos + 1), false);
	}
}

int main()
{
	string str = "0";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = " 0.1";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = "abc";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = "1 a";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = "2e10";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = "e";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = ".";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = " ";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = "e9";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = "3.";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	str = "4 1";
	cout << str << " : " << boolalpha << isNumber(str) << endl;

	return 1;
}