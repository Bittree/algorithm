// 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

// 示例 1:

// 输入:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// 输出: [1,2,3,6,9,8,7,4,5]
// 示例 2:

// 输入:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// 输出: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ret;
    int m = matrix.size();
    if (m <= 0)
    {
        return ret;
    }
    int n = matrix[0].size();
    if (n <= 0)
    {
        return ret;
    }
    int left = 0, bottom = m - 1, top = 1, right = n - 1, forward = 0, count = m * n, i = 0, j = 0;
    while (ret.size() < count)
    {
        ret.push_back(matrix[i][j]);
        if (forward == 0)
        {
            if (j == right)
            {
                ++i;
                forward = 1;
                --right;
            }
            else
            {
                ++j;
            }
        }
        else if (forward == 1)
        {
            if (i == bottom)
            {
                --j;
                forward = 2;
                --bottom;
            }
            else
            {
                ++i;
            }
        }
        else if (forward == 2)
        {
            if (j == left)
            {
                --i;
                forward = 3;
                ++left;
            }
            else
            {
                --j;
            }
        }
        else if (forward == 3)
        {
            if (i == top)
            {
                ++j;
                forward = 0;
                ++top;
            }
            else
            {
                --i;
            }
        }
    }
    return ret;
}

int main()
{
    vector<vector<int>> matrix;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    matrix.push_back(vec);
    vec.clear();
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    matrix.push_back(vec);
    vec.clear();
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(12);
    matrix.push_back(vec);
    vec.clear();
    vec.push_back(13);
    vec.push_back(14);
    vec.push_back(15);
    vec.push_back(16);
    matrix.push_back(vec);
    auto result = spiralOrder(matrix);
    cout << "[ ";
    for (auto ele : result)
    {
        cout << ele << " ";
    }
    cout << " ]" << endl;

    return 1;
}