// 1、只允许使用c的语法，不许使用cpp的设施
// 2、value是一个最大32位的整型数据

#include <stdlib.h>
char* myitoa(int value, char* string, int radix)
{
    // 处理的进制最小为二进制，最大为36进制
	if (radix > 36 || radix < 2)
	{
		return NULL;
	}

    // 因为最大32位，所以这里开33字节的数组够用
    // 先将数据以倒序的方式处理到一个临时数组，之后再放到返回的字符串中，这个临时数组相当于一个栈
	char tmp[33];
	int flag = 0;

    // 这里v必须要用unsigned int，不能用int类型，因为为INT_MIN的时候int数据取绝对值处理会不正确
	unsigned int v = 0;
	if (value < 0)
	{
		flag = 1;
		v = -value;
	}
	else
	{
		flag = 0;
		v = value;
	}

	char* pTmp = tmp;
    // tmp == pTmp是为了能够正确处理value为0的情况
	while (v > 0 || pTmp == tmp)
	{
		auto mo = v % radix;
		if (mo < 10)
		{
			*pTmp++ = mo + '0';
		}
		else
		{
			*pTmp++ = mo + 'a' - 10;
		}
		v /= radix;
	}

    // 如果传入的指针没有开辟空间就动态开辟空间
	if (string == NULL)
	{
		string = (char*)malloc(pTmp - tmp + 1 + flag);
	}
	auto ret = string;
	if (flag)
	{
		*ret++ = '-';
	}
	while (pTmp > tmp)
	{
		*ret++ = *--pTmp;
	}
	*ret = 0;
	return string;
}

int main()
{
	char* result7 = myitoa(0, (char*)new char[2], 10);
	printf("%s\n", result7);
	char* result5 = myitoa(1000, (char*)new char[5], 10);
	printf("%s\n", result5);
	char* result6 = myitoa(-1000, (char*)new char[6], 10);
	printf("%s\n", result6);
	char* result = myitoa(INT_MAX, (char*)new char[11], 10);
	printf("%s\n", result);
	char* result1 = myitoa(INT_MIN, (char*)new char[12], 10);
	printf("%s\n", result1);
	char* result2 = myitoa(INT_MAX + 1, (char*)new char[12], 10);
	printf("%s\n", result2);
	char* result3 = myitoa(INT_MIN - 1, (char*)new char[11], 10);
	printf("%s\n", result3);
	char* result4 = myitoa(0, (char*)new char[2], 10);
	printf("%s\n", result4);
	return 0;
}