// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

// 说明：解集不能包含重复的子集。

// 示例:

// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ret;
    ret.push_back(vector<int>());
    int start = 0, size = nums.size();
    sort(nums.begin(), nums.end());
    for(int count = 1; count <= size; ++count)
    {
        while(start < ret.size() && ret[start].size() == count-1)
        {
            vector<int> tmp(ret[start++]);
            for(int j = size-1; j >= 0; --j)
            {
                if(!tmp.empty() && nums[j] <= tmp[tmp.size()-1])
                {
                    break;
                }
                tmp.push_back(nums[j]);
                ret.push_back(tmp);
                tmp.pop_back();
            }
        }
    }
    return ret;
}

// 最佳解法
// vector<vector<int>> subsets(vector<int>& nums) {
// 	vector<vector<int>> res(1);
// 	int size;
// 	sort(nums.begin(), nums.end());
// 	for (int i = 0; i < nums.size(); i++)
// 	{
// 		size = res.size();
// 		cout << size << endl;
// 		for (int j = 0; j < size; j++)
// 		{
// 			res.push_back(res[j]);
// 			res.back().push_back(nums[i]);
// 		}

// 	}
// 	//cout<<size<<endl;
// 	return res;
// }

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    auto ret = subsets(vec);
    cout << "[" << endl;
    for(auto arr : ret)
    {
        cout << "[ ";
        for(auto ele : arr)
        {
            cout << ele << " ";
        }
        cout << "]" << endl; 
    }
    cout << "]" << endl;
    return 1;
}