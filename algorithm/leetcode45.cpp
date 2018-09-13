// 给定一个非负整数数组，你最初位于数组的第一个位置。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。

// 示例:

// 输入: [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 说明:

// 假设你总是可以到达数组的最后一个位置。

#include<iostream>
#include<vector>
#include <limits>

using namespace std;

int jump(vector<int>& nums)
{
    int size = nums.size();
    if(size <= 1)
    {
        return 0;
    }
    vector<int> steps(size, numeric_limits<int>::max());
    steps[0] = 0;
    for(int i = 0; i < size-1; ++i)
    {
        int min_step = steps[i]+1;
        int min_limit = (i+nums[i])<(size-1)?(i+nums[i]):(size-1);
        for(int j = i+1; j <= min_limit; ++j)
        {
            if(steps[j] > min_step)
            {
                steps[j] = min_step;
            }
        }
    }
    return steps[size-1];
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    cout << "[ ";
    for(auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << jump(nums) << endl;

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    cout << "[ ";
    for(auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << jump(nums) << endl;

    nums.clear();
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(3);
    cout << "[ ";
    for(auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << jump(nums) << endl;
}