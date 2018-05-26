
// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i)
    {
        if(i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }
        for(int j = i + 1, k = nums.size() - 1; j < k; )
        {
            if(j > i + 1 && nums[j] == nums[j-1])
            {
                j++;
                continue;
            }
            if(k < nums.size() - 1 && nums[k] == nums[k+1])
            {
                k--;
                continue;
            }
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0)
            {
                j++;
            }else if(sum > 0) {
                k--;
            }else{
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                ret.push_back(v);
                j++;
                k--;
            }
        }
    }
    return ret;
}

int main()
{
    vector<int> arg;
	arg.push_back(-2);
	arg.push_back(0);
	arg.push_back(1);
	arg.push_back(1);
	arg.push_back(2);
	auto ret = threeSum(arg);
	cout << "[ ";
	for (auto i = ret.begin(); i != ret.end(); ++i) 
	{
		for (auto j = i->begin(); j != i->end(); ++j)
		{
			cout << *j << " ";
		}
	}
	cout << " ]";

	return 0;
}