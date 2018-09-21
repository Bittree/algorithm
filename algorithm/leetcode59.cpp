// 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

// 示例:

// 输入: 3
// 输出:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ret(n, vector<int>(n, 0));
    int max = n * n, forward = 0, top = 1, bottom = n - 1, right = n - 1, left = 0;
    int i = 0, j = 0, k = 0;
    while (k++ < max)
    {
        ret[i][j] = k;
        if (forward == 0)
        {
            if (j == right)
            {
                forward = 1;
                ++i;
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
                forward = 2;
                --j;
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
                forward = 3;
                --i;
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
                forward = 0;
                ++j;
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
    int n = 4;
    auto result = generateMatrix(n);
    cout << "n:" << n << "[" << endl;
    for (auto vec : result)
    {
        cout << "  [ ";
        for (auto ele : vec)
        {
            cout << ele << " ";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;

    n = 6;
    result = generateMatrix(n);
    cout << "n:" << n << "[" << endl;
    for (auto vec : result)
    {
        cout << "  [ ";
        for (auto ele : vec)
        {
            cout << ele << " ";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;

    return 1;
}