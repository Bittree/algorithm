// 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

// 说明：解集不能包含重复的子集。

// 示例:

// 输入: [1,2,2]
// 输出:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

#include<iostream>
#include <string>
#include<vector>
#include <algorithm> 
#include <map>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<vector<int>> ret;
    vector<int> vec;
    ret.push_back(vec);
    map<int, int> record;
    for(int i = 0; i<nums.size(); ++i)
    {
        ++record[nums[i]];
    }
    for(auto ele : record)
    {
        for (int i = ret.size()-1; i >= 0; --i)
        {
            vector<int> new_vec  = ret[i];
            for(int i = 0; i < ele.second; ++i)
            {
                new_vec.push_back(ele.first);
                ret.push_back(new_vec);
            }
        }
    }
    return ret;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    auto result = subsetsWithDup(vec);
    for(int i = 0; i < result.size(); ++i)
    {
        cout << "[";
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j];
            if(j < result[i].size()-1)
            {
                cout << ",";
            }
        }
        cout << "]";
        if(i < result.size()-1)
        {
            cout << ",";
        }
        cout << endl;
    }
    return 1;
}