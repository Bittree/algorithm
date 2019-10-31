// 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

// 示例:

// 输入: "25525511135"
// 输出: ["255.255.11.135", "255.255.111.35"]

#include<iostream>
#include<vector>
#include <string>

using namespace std;

vector<string> restoreIpAddresses(string s)
{
	vector<string> ret;
	for (int i = 1; i < 4; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			for (int k = 1; k < 4; ++k)
			{
				for (int l = 1; l < 4; ++l)
				{
					if (i+j+k+l==s.length())
					{
						string a = s.substr(0, i);
						string b = s.substr(i, j);
						string c = s.substr(i+j, k);
						string d = s.substr(i+j+k, l);
						if (stoi(a) <= 255 && stoi(b) <= 255 && stoi(c) <= 255 && stoi(d) <= 255)
						{
							ret.push_back(a+'.'+b+'.'+c+'.'+d);
						}
					}
				}
			}
		}
	}
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