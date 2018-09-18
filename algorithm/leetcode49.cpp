// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 说明：

// 所有输入均为小写字母。
// 不考虑答案输出的顺序。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ret;
    map<string, vector<string>> map;
    for (string &str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        if (map.find(key) == map.end())
        {
            vector<string> tmp(1, str);
            map[key] = tmp;
        }
        else
        {
            map[key].push_back(str);
        }
    }

    for (auto itor = map.begin(); itor != map.end(); ++itor)
    {
        ret.push_back(itor->second);
    }

    return ret;
}

int main()
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    auto result = groupAnagrams(strs);
    cout << "[" << endl;
    for (auto vec : result)
    {
        cout << "[ ";
        for (auto ele : vec)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
        ;
    }
    cout << "]" << endl;

    return 1;
}