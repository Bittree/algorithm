// 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。画 n 条垂直线，使得垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 注意：你不能倾斜容器，n 至少是2。

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int lindex = 0;
    int rindex = height.size() - 1;
    int litor = lindex;
    int ritor = rindex;
    int maxCap = (rindex - lindex) * (height[lindex] < height[rindex]? height[lindex]:height[rindex]);
    while(litor  < ritor)
    {
        if(height[litor] < height[ritor]) 
        {
            litor++;
        }else{
            ritor--;
        }
        
        if(litor < ritor)
        {
            int newMaxCap = (ritor - litor) * (height[litor] < height[ritor]? height[litor]:height[ritor]);
            if(newMaxCap > maxCap)
            {
                maxCap = newMaxCap;
                lindex = litor;
                rindex = ritor;
            }
        }
    }
    
    return maxCap;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(3);
    arr.push_back(9);
    arr.push_back(2);
	cout << maxArea(arr) << endl;

	return 0;
}