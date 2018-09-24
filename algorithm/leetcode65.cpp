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

bool isNumber(string s)
{
	int slen = s.size();
	bool dot = false, hase = false, hasnum = false;
	for (int i = 0; i < slen; ++i)
	{
		if (s[i] == '.')
		{
			if (i < slen - 1 && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
			{
				return false;
			}
			if (dot)
			{
				return false;
			}
			else {
				dot = true;
				continue;
			}
		}
		if (s[i] == 'e')
		{
			if (i >= slen - 1 || !(s[i + 1] >= '0' && s[i + 1] <= '9') || !hasnum)
			{
				return false;
			}
			if (hase)
			{
				return false;
			}
			else {
				hase = true;
				continue;
			}
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			hasnum = true;
			continue;
		}
		if (s[i] == ' ')
		{
			continue;
		}
		return false;
	}
	return hasnum;
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