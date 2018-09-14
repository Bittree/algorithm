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

// 超时 O(n^2)
// int jump(vector<int>& nums)
// {
//     int size = nums.size();
//     if(size <= 1)
//     {
//         return 0;
//     }
//     vector<int> steps(size, numeric_limits<int>::max());
//     steps[0] = 0;
//     for(int i = 0; i < size-1; ++i)
//     {
//         int min_step = steps[i]+1;
//         int min_limit = (i+nums[i])<(size-1)?(i+nums[i]):(size-1);
//         for(int j = i+1; j <= min_limit; ++j)
//         {
//             if(steps[j] > min_step)
//             {
//                 steps[j] = min_step;
//             }
//         }
//     }
//     return steps[size-1];
// }

// 超时,最坏情况是【1,1,1,1,1,1,1,1......】,O(n^2)
// int jump(vector<int>& nums)
// {
//     int size = nums.size();
//     if(size <= 1)
//     {
//         return 0;
//     }
//     vector<int> min_steps;
//     min_steps.push_back(0);
//     for(int i = 0; i < size; ++i)
//     {
//         if(nums[i] <= 0)
//         {
//             continue;
//         }
//         int cur_steps = 0;
//         for(int j = 0; j < min_steps.size(); ++j)
//         {
//             if(i <= min_steps[j])
//             {
//                 cur_steps = j;
//                 break;
//             }
//         }
//         int max_index = nums[i]+i;
//         if(max_index >= size-1)
//         {
//             return cur_steps+1;
//         }else{
//             if(max_index > min_steps[cur_steps])
//             {
//                 if(min_steps.size() < cur_steps+2)
//                 {
//                     min_steps.push_back(max_index);
//                     continue;
//                 }
//                 if(max_index > min_steps[cur_steps+1])
//                 {
//                     min_steps[cur_steps+1] = max_index;
//                 }
//             }
//         }
//     }
//     return -1;
// }

int jump(vector<int>& nums) 
{
    int times = 0;
    int reached = 0;
    int max = 0;
    for(int i=0;i< nums.size();i++){
        if(reached < i){
            times++;
            reached = max;
        }
        max = max<i+nums[i]?i+nums[i]:max;
    }
    return times;
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

    nums.clear();
    for(int i = 25000; i>0; --i)
    {
        nums.push_back(i);
    }
    nums.push_back(1);
    nums.push_back(0);
    cout << "[ ";
    for(auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << jump(nums) << endl;
}