// n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给定一个整数 n，返回 n 皇后不同的解决方案的数量。

// 示例:

// 输入: 4
// 输出: 2
// 解释: 4 皇后问题存在如下两个不同的解法。
// [
//  [".Q..",  // 解法 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // 解法 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool vaild(vector<int> &arr, int i, int j)
{
    for (int k = 0; k < i; ++k)
    {
        if (arr[k] == j || abs(i - k) == abs(j - arr[k]))
        {
            return false;
        }
    }
    return true;
}

int totalNQueens(int n)
{
    if (n <= 0 || n > 1 && n < 4)
    {
        return 0;
    }
    vector<int> arr(n, -1);
    int i = 0, j = 0, ret = 0;
    while (i < n)
    {
        while (j < n)
        {
            if (vaild(arr, i, j))
            {
                arr[i] = j;
                j = 0;
                break;
            }
            else
            {
                ++j;
            }
        }

        // not found
        if (arr[i] == -1)
        {
            if (i == 0)
            {
                break;
            }
            --i;
            j = arr[i] + 1;
            arr[i] = -1;
            continue;
        }

        // last line
        if (i == n - 1)
        {
            ++ret;
            j = arr[i] + 1;
            arr[i] = -1;
            continue;
        }
        ++i;
    }
    return ret;
}

int main()
{
    int n = 4;
    auto result = totalNQueens(n);
    cout << "n = " << n << ":" << result << endl;

    n = 5;
    result = totalNQueens(n);
    cout << "n = " << n << ":" << result << endl;

    return 1;
}