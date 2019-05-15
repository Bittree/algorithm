// 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

// 示例:

// 输入:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// 输出: 6

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

int maximalRectangle(vector<vector<char>>& matrix)
{
    if(matrix.size() == 0 || matrix[0].size() == 0)
    {
        return 0;
    }
    vector<int> records(matrix[0].size(), 0);
    int max = 0, cur = 0;
    for(int i = 0; i < matrix.size(); ++i)
    {
        for(int j = 0; j < matrix[0].size(); ++j)
        {
            if(matrix[i][j] == '0')
            {
                records[j] = 0;
            }
            else if(matrix[i][j] == '1')
            {
                records[j]+=1;
            }
        }
        cur = largestRectangleArea(records);
        max = max>cur?max:cur;
    }
    return max;
}