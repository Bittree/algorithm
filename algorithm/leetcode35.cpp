// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

// 你可以假设数组中无重复元素。

// 示例 1:

// 输入: [1,3,5,6], 5
// 输出: 2
// 示例 2:

// 输入: [1,3,5,6], 2
// 输出: 1
// 示例 3:

// 输入: [1,3,5,6], 7
// 输出: 4
// 示例 4:

// 输入: [1,3,5,6], 0
// 输出: 0

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int size = nums.size();
    for(int i = 0; i < size; ++i)
    {
        if(target <= nums[i])
        {
            return i;
        }
    }
    return size;
}

int searchInsert2(vector<int>& nums, int target)
{                    
    int begin = 0;
    int end = nums.size() - 1;
    int mid = 0;
    int pos = 0;
    
    while ( begin <= end)
    {
        mid = (begin + end)/2;
        
        if ( nums[mid] == target)
        {
            return mid;
        }
        else if ( nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {                
            begin = mid + 1;
        }
    }
    
    return begin;
}

int main()
{
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    vec1.push_back(6);
    for(auto v : vec1)
    {
        cout << v << " ";
    }
    cout << endl;
    cout << "target: " << 5 << endl;
    cout << "result: " << searchInsert(vec1, 5) << endl;

    cout << "target: " << 2 << endl;
    cout << "result: " << searchInsert(vec1, 2) << endl;

    cout << "target: " << 7 << endl;
    cout << "result: " << searchInsert(vec1, 7) << endl;

    cout << "target: " << 0 << endl;
    cout << "result: " << searchInsert(vec1, 0) << endl;
}