// 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

// 示例:

// 输入: "25525511135"
// 输出: ["255.255.11.135", "255.255.111.35"]

#include<iostream>
#include<vector>
#include <string>

using namespace std;

bool isVaildIP(string str)
{
	try
	{
		int num = stoi(str);
		if (num >= 0 && num <= 255)
		{
			return true;
		}
		return false;
	}
	catch (exception e)
	{
		return false;
	}
}

void restore(vector<string>& ret, string& s, vector<int> arr)
{
	int size = arr.size();
	if (size >= 3)
	{
		string result = s;
		result.insert(arr[2], ".");
		result.insert(arr[1], ".");
		result.insert(arr[0], ".");
		return;
	}
	for (int i = 0; i < 3; ++i)
	{
		if (size == i)
		{
			int index = i - 1;
			if (i > 0 && arr[index] >= s.length() - 1)
			{
				return;
			}
			for (int j = 1; j <= 3 && arr[index] + j < s.length(); ++j)
			{
				string str = s.substr(arr[index], j);
				if (!isVaildIP(str))
				{
					break;
				}
				arr.push_back(arr[index] + j);
				restore(ret, s, arr);
				arr.pop_back();
			}
			break;
		}
	}
}

vector<string> restoreIpAddresses(string s)
{
	vector<string> ret;
	if (s.length() < 4 || s.length() > 12)
	{
		return ret;
	}
	vector<int> arr;
	restore(ret, s, arr);
	return ret;
}

int main()
{
	vector<string> ret = restoreIpAddresses("25525511135");
	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}
	return 1;
}