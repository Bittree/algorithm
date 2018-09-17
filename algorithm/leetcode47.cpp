// 给定一个可包含重复数字的序列，返回所有不重复的全排列。

// 示例:

// 输入: [1,1,2]
// 输出:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// vector<vector<int>> permuteUnique(vector<int>& nums)
// {
//     vector<vector<int>> ret;
//     sort(nums.begin(), nums.end());
//     do{
//         ret.push_back(nums);
//     }while(next_permutation(nums.begin(), nums.end()));
//     return ret;
// }

void dfs(vector<vector<int>>& ret, vector<int>& nums, int start)
{
    int size = nums.size();
    if(start >= size-1)
    {
        ret.push_back(nums);
        return;
    }
    for(int i = start; i < size; ++i)
    {
        bool hassame = false;
        for(int j = i+1; j < size; ++j)
        {
            if(nums[j] == nums[i])
            {
                hassame = true;
                break;
            }
        }
        if(hassame)
        {
            continue;
        }
        swap(nums[start], nums[i]);
        dfs(ret, nums, start+1);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector<vector<int>> ret;
    vector<int> tmp = nums;
    dfs(ret, tmp, 0);
    return ret;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    cout << "[ ";
    for(auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << endl;
    auto ret = permuteUnique(nums);
    cout << "[ " << endl;
    for(auto vec : ret)
    {
        cout << "[ ";
        for(auto ele : vec)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    cout << endl;
    nums.clear();
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    cout << "[ ";
    for(auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << endl;
    ret = permuteUnique(nums);
    cout << "[ " << endl;
    for(auto vec : ret)
    {
        cout << "[ ";
        for(auto ele : vec)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 1;
}