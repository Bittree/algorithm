// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

// 输入: [2,1,5,6,2,3]
// 输出: 10

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int size = heights.size();
    if(size == 0)
    {
        return 0;
    }else if(size == 1)
    {
        return heights[0];
    }
    heights.push_back(0);
    int max = 0;
    stack<int> records;
    for(int i = 0; i <= size; ++i)
    {
        if(records.empty() || heights[i] >= heights[records.top()])
        {
            records.push(i);
        }
        else
        {
            // 如果当前高度小于栈顶元素高度，开始处理计算栈内坐标形成的局部递增高度
            int top = records.top(), width = 0, area = 0;
            records.pop();
            if(records.empty())
            {
                width = i;
            }
            else
            {
                width = i - 1 - records.top();
            }
            area = heights[top] * width;
            if(area > max)
            {
                max = area;
            }
            --i;
        }
    }
    return max;
}

int main()
{
    vector<int> heights;
    heights.push_back(1);
    heights.push_back(1);
    int result = largestRectangleArea(heights);
    cout << "result: " << result << endl;

    return 1;
}