// n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

// 示例:

// 输入: 4
// 输出: [
//  [".Q..",  // 解法 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // 解法 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// 解释: 4 皇后问题存在两个不同的解法。

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

void store(vector<vector<string>> &ret, vector<int> &arr)
{
    int size = arr.size();
    vector<string> vec(size, string(size, '.'));
    for (int i = 0; i < size; ++i)
    {
        vec[i][arr[i]] = 'Q';
    }
    ret.push_back(vec);
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ret;
    if (n > 1 && n < 4)
    {
        return ret;
    }
    vector<int> arr(n, -1);
    int i = 0, j = 0;
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
            store(ret, arr);
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
    auto result = solveNQueens(n);
    cout << "n = " << n << ":" << endl;
    cout << "[" << endl;
    for (auto vec : result)
    {
        cout << "  [" << endl;
        for (auto str : vec)
        {
            cout << "    " << str << "," << endl;
        }
        cout << "  ]," << endl;
    }
    cout << "]" << endl;

    return 1;
}