// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

// 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

// 示例 1:

// 给定 nums = [1,1,1,2,2,3],

// 函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

// 你不需要考虑数组中超出新长度后面的元素。
// 示例 2:

// 给定 nums = [0,0,1,1,1,1,2,3,3],

// 函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

// 你不需要考虑数组中超出新长度后面的元素。
// 说明:

// 为什么返回数值是整数，但输出的答案是数组呢?

// 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

// 你可以想象内部操作如下:

// // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
// int len = removeDuplicates(nums);

// // 在函数里修改输入数组对于调用者是可见的。
// // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }
    int read_index = 0, write_index = 0, total_count = 0, cur = nums[0], cur_num = 0;
    while(read_index < nums.size())
    {
        if(read_index > 1  && nums[read_index] == cur && cur_num >= 2)
        {
            ++read_index;
            continue;
        }
        if(cur !=  nums[read_index])
        {
            cur = nums[read_index];
            cur_num = 1;
        }else{
            ++cur_num;
        }
        if(write_index != read_index)
        {
            nums[write_index] = nums[read_index];
        }
        ++total_count;
        ++read_index;
        ++write_index;
    }
    return total_count;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    cout <<  "-----------------------------" << endl;
    cout << "[";
    for(auto ele : vec)
    {
        cout << " " << ele;
    }
    cout << " ]" << endl;
    auto result = removeDuplicates(vec);
    cout << "[";
    for(int i = 0; i < result; ++i)
    {
        cout << " " << vec[i];
    }
    cout << " ]" << endl;
    cout <<  "-----------------------------" << endl;

    vec.clear();
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    cout <<  "-----------------------------" << endl;
    cout << "[";
    for(auto ele : vec)
    {
        cout << " " << ele;
    }
    cout << " ]" << endl;
    result = removeDuplicates(vec);
    cout << "[";
    for(int i = 0; i < result; ++i)
    {
        cout << " " << vec[i];
    }
    cout << " ]" << endl;
    cout <<  "-----------------------------" << endl;

    return 1;
}