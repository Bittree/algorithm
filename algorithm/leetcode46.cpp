// 给定一个没有重复数字的序列，返回其所有可能的全排列。

// 示例:

// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ret;
    for(auto num : nums)
    {
        if(ret.empty())
        {
            ret.push_back(vector<int>(1, num));
            continue;
        }
        int ret_size = ret.size();
        for(int i = 0; i < ret_size; ++i)
        {
            int ele_size = ret[i].size();
            for(int j = 0; j < ele_size+1; ++j)
            {
                vector<int> tmp(ret[i]);
                tmp.insert(tmp.begin()+j, num);
                ret.push_back(tmp);
            }
        }
        ret.erase(ret.begin(), ret.begin()+ret_size);
    }
    return ret;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout << "[ ";
    for(auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << endl;
    auto ret = permute(nums);
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
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    cout << "[ ";
    for(auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << endl;
    ret = permute(nums);
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