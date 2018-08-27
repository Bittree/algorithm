// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 如果数组中不存在目标值，返回 [-1, -1]。

// 示例 1:

// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]
// 示例 2:

// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]

#include<iostream>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int count = nums.size();
    int l = 0,  r = count-1;
    vector<int> ret(2, -1);
    while(l<=r)
    {
        int m = (r-l)/2+l;
        if(nums[m] > target)
        {
            r = m-1;
        }else if(nums[m] < target)
        {
            l = m+1;
        }else{
            if(m == 0 || nums[m-1]<target)
            {
                ret[0] = m;
            }
            if(m == count-1 || nums[m+1]>target)
            {
                ret[1] = m;
            }
            
            if(ret[0] == -1 && ret[1] != -1)
            {
                l = 0;
                r = m-1;
            }else if(ret[0] != -1 && ret[1] == -1)
            {
                l = m+1;
                r = count-1;
            }else if (ret[0] == -1 && ret[1] == -1)
            {
                l = 0;
                r = m - 1;
            }else{
                break;
            }
        }
    }
    return ret;
}

int main()
{
    vector<int> vec1;
    int target1 = 8;
    vec1.push_back(5);
    vec1.push_back(7);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(8);
    vec1.push_back(10);
    for(auto v : vec1)
    {
        cout << v << " ";
    }
    cout << ": " << target1 << endl;
    auto result1 = searchRange(vec1, target1);
    for(auto v : result1)
    {
        cout << v << " ";
    }

    cout << endl;

    vector<int> vec2;
    int target2 = 3;
    vec2.push_back(3);
    vec2.push_back(3);
    vec2.push_back(3);
    for(auto v : vec2)
    {
        cout << v << " ";
    }
    cout << ": " << target2 << endl;
    auto result2 = searchRange(vec2, target2);
    for(auto v : result2)
    {
        cout << v << " ";
    }

    return 1;
}