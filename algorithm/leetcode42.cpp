// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

// 图见https://leetcode-cn.com/problems/trapping-rain-water/description/

// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

// 示例:

// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int trap(vector<int>& height)
{
    multimap<int, int> sorted_height;
    for(int i = 0; i < height.size(); ++i)
    {
        sorted_height.insert(pair<int, int>(height[i], i));
    }
    
    int min = height.size()-1, max = 0, ret = 0;
    multimap<int,int>::reverse_iterator last_itor = sorted_height.rend();
    for(auto itor = sorted_height.rbegin(); itor != sorted_height.rend(); ++itor)
    {
        if(last_itor == sorted_height.rend())
        {
            last_itor = itor;
            max = itor->second;
            min = itor->second;
            continue;
        }
        if(itor->second < min)
        {
            for(int i = itor->second+1; i < min; ++i)
            {
                ret += (itor->first - height[i]);
            }
            min = itor->second;
        }
        if(itor->second > max)
        {
            for(int i = max+1; i < itor->second; ++i)
            {
                ret += (itor->first - height[i]);
            }
            max = itor->second;
        }
    }
    return ret;
}

// store right side max number, and traverse from left side, the algoritm is better!
int trap2(vector<int>& height)
{
	int n = height.size();
	if (n == 0) return 0;
	int maxL = 0, maxR = 0, index = 0;

	vector<int> maxR_value(n, 0);
	for (int i = n - 1; i >= 0;i--)
	{
		if (height[i] > maxR)
			maxR = height[i];
		maxR_value[i] = maxR;
	}
	maxL = height[0];
	int res_sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (height[i] > maxL)
			maxL = height[i];
		res_sum += max(min(maxL, maxR_value[i]) - height[i], 0);
	}

	return res_sum;
}

int main()
{
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
    for(auto ele : vec)
    {
        cout << ele << " ";
    }
    cout << ": " << trap(vec) << endl;
    
    return 1;
}