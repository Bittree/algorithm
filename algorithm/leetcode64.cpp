// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

// 说明：每次只能向下或者向右移动一步。

// 示例:

// 输入:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// 输出: 7
// 解释: 因为路径 1→3→1→1→1 的总和最小。

#include <iostream>
#include <vector>
#include <array>

using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	if (m <= 0)
	{
		return 0;
	}
	int n = grid[0].size();
	if (n <= 0)
	{
		return 0;
	}
	vector<vector<int>> ret(grid);
	for (int i = m - 1; i >= 0; --i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			if (j < n-1 && i < m-1)
			{
				int right = ret[i][j + 1];
				int down = ret[i + 1][j];
				ret[i][j] += right < down ? right : down;
			}
			else if (j >= n - 1 && i < m - 1)
			{
				ret[i][j] += ret[i+1][j];
			}
			else if (j < n - 1 && i >= m - 1)
			{
				ret[i][j] += ret[i][j+1];
			}
		}
	}
	return ret[0][0];
}

int main()
{
	array<array<int, 3>, 3> arr = {
		1, 3, 1,
		1, 5, 1,
		4, 2, 1,
	};
	int m = 3, n = 3;
	vector<vector<int>> obstacleGrid(m, vector<int>(n, 0));
	cout << "[" << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << "  [ ";
		for (int j = 0; j < n; ++j)
		{
			obstacleGrid[i][j] = arr[i][j];
			cout << arr[i][j] << " ";
		}
		cout << "]," << endl;
	}
	cout << "]" << endl;
	int result = minPathSum(obstacleGrid);
	cout << "result: " << result << endl;

	return 1;
}