// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

// 你可以假设数组中不存在重复的元素。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 示例 1:

// 输入: nums = [4,5,6,7,0,1,2], target = 0
// 输出: 4
// 示例 2:

// 输入: nums = [4,5,6,7,0,1,2], target = 3
// 输出: -1

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    int num_count = nums.size();
    if(num_count <= 0)
    {
        return -1;
    }else if(num_count == 1)
    {
        return nums[0] == target?0:-1;
    }

    int index = num_count/2;
    int min = 0, max = num_count-1;
    bool hasReverse = false;
    // while(nums[index-1] < nums[index])
    // {
    //     if(nums[index] > nums[0])
    //     {
    //         if(max == index)
    //         {
    //             hasReverse = false;
    //             break;
    //         }
    //         min = index;
    //         index = (max-index+1)/2+index;
    //     }else{
    //         if(min == index)
    //         {
    //             hasReverse = false;
    //             break;
    //         }
    //         max = index;
    //         index = (index-min)/2+min;
    //     }
    // }
    int min_target = nums[0];
    while(min <= max)
    {
        int tmp_index = (max-min)/2+min;
        if(nums[tmp_index] < min_target)
        {
            hasReverse = true;
            min_target = nums[tmp_index];
            max = tmp_index-1;
            index = tmp_index;
        }else if(nums[tmp_index] > min_target)
        {
            min = tmp_index+1;
        }
        else{
            if(nums[0] == target)
            {
                return 0;
            }else if(nums[1] == target)
            {
                return 1;
            }else{
                return -1;
            }
        }
    }

    if(hasReverse)
    {
        if(target > nums[0])
        {
            min = 0;
            max = index-1;
        }else if(target < nums[0]){
            min = index;
            max = num_count-1;
        }else{
            return 0;
        }
    }else{
            min = 0;
            max = num_count-1;
    }
    
    while(min <= max)
    {
        int target_index = (max-min)/2+min;
        if(nums[target_index]<target)
        {
            min = target_index+1;
        }else if(nums[target_index]>target)
        {
            max = target_index-1;
        }else{
            return target_index;
        }
    }
    return -1;
}

int search2(vector<int>& nums, int target)
{
    if ( nums.size() == 0)
        return -1;
    
    if ( nums.size() == 1)
    {
        if ( target == nums[0])
            return 0;
        else
            return -1;
    }
    
    int begin = 0;
    int end = nums.size()-1;
    int mid;
            
    while ( begin <= end)
    {
        mid = (begin+end)/2;
        
        if ( nums[mid] == target)
            return mid;
        else if ( nums[begin] == target)
            return begin;
        else if ( nums[end] == target)
            return end;
        
        if ( nums[begin] == nums[end])
        {
            break;
        }
        else if ( nums[begin] < nums[end])
        {
            if ( nums[mid] > target)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        else 
        {
            if ( nums[mid] > nums[begin])
            {
                if ( target > nums[begin] && target < nums[mid])
                    end = mid - 1;
                else
                    begin = mid + 1;
            }
            else
            {
                if ( target < nums[end] && target > nums[mid])
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
        }
    }
            
    return -1;        
}

int main()
{
    vector<int> vec1;
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(7);
    vec1.push_back(0);
    vec1.push_back(1);
    vec1.push_back(2);
    for(auto v : vec1)
    {
        cout << v << " ";
    }
    cout << ": " << search(vec1, 0) << endl;

    vector<int> vec2;
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    vec2.push_back(7);
    vec2.push_back(0);
    vec2.push_back(1);
    vec2.push_back(2);
    for(auto v : vec2)
    {
        cout << v << " ";
    }
    cout << ": " << search(vec2, 3) << endl;

    vector<int> vec3;
    vec3.push_back(3);
    vec3.push_back(1);
    for(auto v : vec3)
    {
        cout << v << " ";
    }
    cout << ": " << search(vec3, 3) << endl;
}