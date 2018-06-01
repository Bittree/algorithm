// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

// 注意：

// 答案中不可以包含重复的四元组。

// 示例：

// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getSum(vector<int> condidate)
{
	int total = 0, size = condidate.size();
	for (int i = 0; i < size; ++i)
	{
		total += condidate[i];
	}
	return total;
}

void dfs(vector<vector<int>>& ret, vector<int>& condidate, vector<int> numbers, int curIndex, int target)
{
	if (condidate.size() == 4)
	{
		int total = getSum(condidate);
		if (total == target)
		{
			ret.push_back(vector<int>(condidate));
		}
		return;
	}
	if (curIndex > numbers.size() - 1)
	{
		return;
	}
	for (int i = curIndex; i < numbers.size(); ++i)
	{
		if (i != curIndex && numbers[i] == numbers[i-1])
		{
			continue;
		}
		condidate.push_back(numbers[i]);
		if (getSum(condidate) > target && numbers[i] > 0)
		{
			if (!condidate.empty())
			{
				condidate.pop_back();
			}
			return;
		}
		dfs(ret, condidate, numbers, i+1, target);
		if (!condidate.empty())
		{
			condidate.pop_back();
		}
	}
}

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	std::sort(nums.begin(), nums.end());
	vector<vector<int>> ret;
	vector<int> condidate;
	dfs(ret, condidate, nums, 0, target);
	return ret;
}

vector<vector<int>> fourSum2(vector<int>& nums, int target)
{
	std::sort(nums.begin(), nums.end());
	vector<vector<int>> ret;
	map<int, vector<int>> records;
	int size = nums.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
		}
	}
	return ret;
}

int main()
{
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	vector<vector<int>> ret = fourSum(nums, 0);
	cout << "[" << endl;
	for (auto arr : ret)
	{
		cout << "[" << " ";
		for (auto ele : arr)
		{
			cout << ele << " ";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
	return 0;
}