// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 进阶:

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

#include <iostream>
#include <vector>

using namespace std;

// O(n)
// int maxSubArray(vector<int> &nums)
// {
//     int size = nums.size();
//     if (size <= 0)
//     {
//         return 0;
//     }
//     int sum = nums[0], ret = nums[0];
//     for (int i = 1; i < size; ++i)
//     {
//         if (sum < 0)
//         {
//             sum = nums[i];
//         }
//         else
//         {
//             sum += nums[i];
//         }
//         if (ret < sum)
//         {
//             ret = sum;
//         }
//     }
//     return ret;
// }

// 分冶法
int maxSub(vector<int> &nums, int left, int right)
{
    if (left == right)
    {
        return nums[left];
    }
    int middle = (left + right) / 2;
    int leftMaxSum = maxSub(nums, left, middle);
    int rightMaxSum = maxSub(nums, middle + 1, right);

    int leftSum = nums[middle], leftMax = nums[middle];
    for (int i = middle - 1; i >= left; --i)
    {
        leftSum += nums[i];
        if (leftSum > leftMax)
        {
            leftMax = leftSum;
        }
    }

    int rightSum = nums[middle + 1], rightMax = nums[middle + 1];
    for (int i = middle + 2; i <= right; ++i)
    {
        rightSum += nums[i];
        if (rightSum > rightMax)
        {
            rightMax = rightSum;
        }
    }

    int ret = leftMaxSum < rightMaxSum ? rightMaxSum : leftMaxSum;
    ret = ret < (leftMax + rightMax) ? (leftMax + rightMax) : ret;
    return ret;
}

int maxSubArray(vector<int> &nums)
{
    return maxSub(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout << "[ ";
    for (auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << "] : " << maxSubArray(nums) << endl;

    return 1;
}