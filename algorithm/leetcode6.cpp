// 将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：（下面这样的形状）

// P   A   H   N
// A P L S I I G
// Y   I   R
// 之后按逐行顺序依次排列："PAHNAPLSIIGYIR"

 

// 实现一个将字符串进行指定行数的转换的函数:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) 应当返回 "PAHNAPLSIIGYIR" 。

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows) {
	if (numRows <= 1)
	{
		return s;
	}
	int groupSize = (numRows - 2) * 2 + 2;
	vector<string> result(numRows, "");
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		int groupIndex = i % groupSize;
		if (groupIndex >= numRows)
		{
			groupIndex = (numRows - 1) * 2 - groupIndex;
		}
		result[groupIndex].push_back(s[i]);
	}
	string ret;
	for (auto str : result)
	{
		ret += str;
	}
	return ret;
}

int main()
{
	cout << convert("ABCD", 3).c_str() << endl;
    return 0;
}