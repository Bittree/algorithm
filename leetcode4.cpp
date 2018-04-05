// 有两个大小为 m 和 n 的排序数组 nums1 和 nums2 。

// 请找出两个排序数组的中位数并且总的运行时间复杂度为 O(log (m+n)) 。

// 示例 1:

// nums1 = [1, 3]
// nums2 = [2]

// 中位数是 2.0
 

// 示例 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// 中位数是 (2 + 3)/2 = 2.5
 

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int size = nums1.size() + nums2.size();
	bool isOdd = (size % 2 == 1);
	int index = size / 2 + (isOdd ? 1 : 0);
	int nums1_index = 0;
	int nums2_index = 0;
	double index_value = 0;
	while (index-- > 0)
	{
		if (nums2.size() <= nums2_index || nums1.size() > nums1_index && nums1[nums1_index] <= nums2[nums2_index])
		{
			if (index == 0)
			{
				if (isOdd)
				{
					return nums1[nums1_index];
				}
				else 
				{
					index_value = nums1[nums1_index];
				}
			}
			nums1_index++;
		}
		else if (nums1.size() <= nums1_index || nums2.size() > nums2_index && nums1[nums1_index] > nums2[nums2_index]) {
			if (index == 0)
			{
				if (isOdd)
				{
					return nums2[nums2_index];
				}
				else
				{
					index_value = nums2[nums2_index];
				}
			}
			nums2_index++;
		}
	}

	if (nums2.size() <= nums2_index || nums1.size() > nums1_index && nums1[nums1_index] <= nums2[nums2_index])
	{
		return (index_value + nums1[nums1_index]) / 2;
	}
	else if (nums1.size() <= nums1_index || nums2.size() > nums2_index && nums1[nums1_index] > nums2[nums2_index]) {
		return (index_value + nums2[nums2_index]) / 2;
	}

	return 0;
}

int main()
{
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(3);
	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(4);
	cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
