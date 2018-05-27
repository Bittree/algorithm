// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

// 示例:

// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#include <iostream>
#include <vector>
#incldue <string>
using namespace std;
vector<string> letterCombinations(string digits) {
    vector<string> ret;
    vector<string> temple = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i = 0; i < digits.length(); ++i)
    {
        vector<string> tmp;
        if(digits[i] >= '1' && digits[i] <= '9')
        {
            int index = digits[i] - '2';
            string str = temple[index];
            if(ret.empty())
            {
                for(int j = 0; j < str.length(); ++j)
                {
                    string ele;
                    ele.push_back(str[j]);
                    ret.push_back(ele);
                }
            }else{
                for(int j = 0; j < ret.size(); ++j)
                {
                    for(int k = 0; k < str.length(); ++k)
                    {
                        tmp.push_back(ret[j] + str[k]);
                    }
                }
                ret = tmp;
            }
        }
    }
    return ret;
}
int main()
{
    auto ret = letterCombinations("123");
	cout << "[ ";
	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << " ";
	}
	cout << " ]";
}