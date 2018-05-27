// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int ret = INT_MAX;
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = i+1, k = nums.size()-1; j < k;)
        {
            int sum = nums[i] + nums[j] + nums[k];
            ret = fabs(target-sum)<fabs(target-ret)?sum:ret;
            if(sum < target)
            {
                j++;
            }else if(sum > target){
                k--;
            }else{
                return sum;
            }
        }
    }
    return ret;
}

int main()
{
    vector<int> arg;
	arg.push_back(-3);
	arg.push_back(-2);
	arg.push_back(-5);
	arg.push_back(3);
	arg.push_back(-4);
	cout << threeSumClosest(arg, -1) << endl;

    return 0;
}