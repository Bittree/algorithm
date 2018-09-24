// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

// 网格中的障碍物和空位置分别用 1 和 0 来表示。

// 说明：m 和 n 的值均不超过 100。

// 示例 1:

// 输入:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// 输出: 2
// 解释:
// 3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
// 1. 向右 -> 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右 -> 向右

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    if(m <= 1)
    {
        return 1;
    }
    int n = obstacleGrid[0].size();
    if(n <= 1)
    {
        return 1;
    }
    vector<vector<int>> steps(m, vector<int>(n, 0));
    steps[m-1][n-1] = 1;
    for(int i = m-1; i >= 0; --i)
    {
        for(int j = n-1; j >= 0; --j)
        {
            int right = j < n-1? steps[i][j+1]: 0;
            int down = i < m-1? steps[i+1][j]: 0;
            steps[i][j] = obstacleGrid[i][j]==1? 0: right + down;
        }
    }
    return steps[0][0];
}

int main()
{
    array<array<int, 3>, 3> arr = {
		0, 0, 0,
		0, 1, 0,
		0, 0, 0,
	};
	int m = 3, n = 3;
	vector<vector<int>> obstacleGrid(m, vector<int>(n, 0));
    cout << "[" << endl;
    for(int i = 0; i < m; ++i)
    {
        cout << "  [ ";
        for(int j = 0; j < n; ++j)
        {
            obstacleGrid.push_back(arr[i][j]);
            cout << arr[i][j] << " ";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
    int result = uniquePathsWithObstacles(obstacleGrid);
    cout << "result: " << result << endl;

    return 1;
}