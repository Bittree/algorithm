// 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

// 示例 1:

// 输入: [1,2,0]
// 输出: 3
// 示例 2:

// 输入: [3,4,-1,1]
// 输出: 2
// 示例 3:

// 输入: [7,8,9,11,12]
// 输出: 1
// 说明:

// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

#include<iostream>
#include<vector>
#include <map>

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    map<int, int> num_map;
    int max = 0;
    for(auto ele : nums)
    {
        num_map[ele] = 1;
        if(ele > max)
        {
            max = ele;
        }
    }
    for(int i = 1; i < max+2; ++i)
    {
        if(num_map[i] == 1)
        {
            continue;
        }
        return i;
    }
}