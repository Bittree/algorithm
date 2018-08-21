// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

// 必须原地修改，只允许使用额外常数空间。

// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    int nums_size = nums.size();
    int tmp_index = -1;
    for(int i = nums_size-1; i > 0; --i)
    {
        if(nums[i] > nums[i-1])
        {
            tmp_index = i-1;
            break;
        }    
    }
    
    if(tmp_index == -1)
    {
        sort(nums.begin(), nums.end());
    }else{
        for(int i = nums_size-1; i > 0; --i)
        {
            if(nums[i] > nums[tmp_index])
            {
                swap(nums[i], nums[tmp_index]);
                break;
            }
        }
        sort(nums.begin()+tmp_index+1, nums.end());
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(0);
    for(auto v : arr)
    {
        cout << v << " ";
    }
    cout << ":";
    nextPermutation(arr);
    for(auto v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}