// 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

// 说明:

//     初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//     你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

// 示例:

// 输入:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// 输出: [1,2,2,3,5,6]

#include<iostream>
#include <string>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
        int index1 = m-1, index2 = n-1;
        for(int i = m+n-1; i>=0; --i)
        {
            if(index1 < 0 && index2 < 0)
            {
                return;
            }
            else if(index1 >= 0 && index2 < 0)
            {
                nums1[i] = nums1[index1--];
            }
            else if(index1 < 0 && index2 >= 0)
            {
                nums1[i] = nums2[index2--];
            }
            else
            {
                if(nums1[index1] <= nums2[index2])
                {
                    nums1[i] = nums2[index2--];
                }else{
                    nums1[i] = nums1[index1--];
                }
            }
        }
}

int main()
{
    vector<int> vec1,vec2;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(0);
    vec1.push_back(0);
    vec1.push_back(0);
    vec2.push_back(2);
    vec2.push_back(5);
    vec2.push_back(6);
    merge(vec1, 3, vec2, 3);
    for(int i = 0; i < vec1.size(); ++i)
    {
        cout << vec1[i] << endl;
    }
    return 1;
}