// 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

// 示例 1:

// 输入: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// 输出: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// 示例 2:

// 输入: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// 输出: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
// 进阶:

// 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
// 你能想出一个常数空间的解决方案吗？

#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
	int row = matrix.size(), col = matrix[0].size();
	int col0flag = 1;
	for (int i = 0; i < row; ++i)
	{
		if (matrix[i][0] == 0)
		{
			col0flag = 0;
		}
		for (int j = 1; j < col; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for (int i = row - 1; i >= 0; --i)
	{
		for (int j = col - 1; j >= 1; --j)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
			{
				matrix[i][j] = 0;
			}
		}
		if (col0flag == 0)
		{
			matrix[i][0] = 0;
		}
	}
}

int main()
{
	int data1[3][5] = {
		{ -4, -2147483648, 6, -7, 0 },
		{ -8, 6, -8, -6, 0 },
		{ 2147483647, 2,-9, -6, -10 }
	};
	vector<vector<int>> matrix;
	for (int i = 0; i < 3; ++i)
	{
		vector<int> vec_tmp1;
		for (int j = 0; j < 5; ++j)
		{
			vec_tmp1.push_back(data1[i][j]);
		}
		matrix.push_back(vec_tmp1);
	}
	setZeroes(matrix);

	return 1;
}