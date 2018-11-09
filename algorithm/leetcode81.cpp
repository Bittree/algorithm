// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

// 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

// 示例 1:

// 输入: nums = [2,5,6,0,0,1,2], target = 0
// 输出: true
// 示例 2:

// 输入: nums = [2,5,6,0,0,1,2], target = 3
// 输出: false
// 进阶:

// 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
// 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

#include<iostream>
#include<vector>

using namespace std;

bool search(vector<int>& nums, int target)
{
    int l = 0, r = nums.size()-1;
    while(l <= r)
    {
        int mid = l+(r-l)/2;
        if(nums[mid] == target)
        {
            return true;
        }
        if(nums[l] > nums[mid]) // mid右边递增，截断点在左边 比如 4 5 1 2 3
        {
            if(nums[mid] < target && target <= nums[r]) // mid在右边且在mid和r的中间
            {
                l = mid+1;
            }
            else    // mid在左边
            {
                r = mid-1;
            }
        }
        else if(nums[l] < nums[mid]) // mid左边递增，截断点在右边，比如 3 4 5 1 2
        {
            if(nums[mid] > target && target >= nums[l]) // target在左边且在l和m的中间
            {
                r = mid-1;
            }
            else // target在右边
            {
                l = mid+1;
            }
        }
        else
        {
            ++l;
        }
    }
    return false;
}

int main()
{
    int target = 0;
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    cout << "[";
    for(auto ele : vec)
    {
        cout << " " << ele;
    }
    cout << "], target: " << target << " " << boolalpha << search(vec, target) << endl;

    target = 3;
    cout << "[";
    for(auto ele : vec)
    {
        cout << " " << ele;
    }
    cout << "], target: " << target << " " << boolalpha << search(vec, target) << endl;

    vec.clear();
    vec.push_back(1);
    vec.push_back(1);
    target = 0;
    cout << "[";
    for(auto ele : vec)
    {
        cout << " " << ele;
    }
    cout << "], target: " << target << " " << boolalpha << search(vec, target) << endl;

    vec.clear();
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    target = 3;
    cout << "[";
    for(auto ele : vec)
    {
        cout << " " << ele;
    }
    cout << "], target: " << target << " " << boolalpha << search(vec, target) << endl;

    return 1;
}