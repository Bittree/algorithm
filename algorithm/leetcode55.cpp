// 给定一个非负整数数组，你最初位于数组的第一个位置。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个位置。

// 示例 1:

// 输入: [2,3,1,1,4]
// 输出: true
// 解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
// 示例 2:

// 输入: [3,2,1,0,4]
// 输出: false
// 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

#include <iostream>
#include <vector>

using namespace std;

// bool jump(vector<int> &nums, int pos)
// {
//     int size = nums.size();
//     if (size <= 0 || pos >= size - 1)
//     {
//         return true;
//     }
//     if (nums[pos] > 0)
//     {
//         for (int i = pos + 1; i <= pos + nums[pos]; ++i)
//         {
//             if (jump(nums, i))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool canJump(vector<int> &nums)
// {
//     return jump(nums, 0);
// }

bool canJump(vector<int> &nums)
{
    int size = nums.size();
    if (size <= 0)
    {
        return true;
    }
    vector<int> vec(size, 0);
    vec[0] = 1;
    int cur = 1;
    for (int i = 0; i < size - 1; ++i)
    {
        while (vec[i] > 0 && cur < size && nums[i] + i >= cur)
        {
            vec[cur++] = vec[i] + 1;
        }
    }
    return vec[size - 1] > 0;
}

// better
// bool canJump(vector<int>& nums)
// {
//     if(nums.size()<=1)
//         return true;

//     int theMax = nums[0];
//     for(int i = 0; i <= theMax; i++)
//     {
//         theMax = max(theMax, nums[i]+i);
//         if(theMax >= nums.size()-1)
//             return true;
//     }
//     return false;
// }

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    cout << "[ ";
    for (auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << boolalpha << canJump(nums) << endl;

    nums.clear();
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(4);
    cout << "[ ";
    for (auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << boolalpha << canJump(nums) << endl;

    nums.clear();
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(3);
    cout << "[ ";
    for (auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << boolalpha << canJump(nums) << endl;
    return 1;
}