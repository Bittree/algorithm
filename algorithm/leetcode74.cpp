// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

//     每行中的整数从左到右按升序排列。
//     每行的第一个整数大于前一行的最后一个整数。

// 示例 1:

// 输入:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// 输出: true

// 示例 2:

// 输入:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// 输出: false

#include<iostream>
#include<vector>
#include <assert.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row_size = matrix.size();
    if(row_size <= 0)
    {
        return false;
    }
    int col_size = matrix[0].size(), total_size = row_size*col_size;
    int left = 0, right = total_size-1;
    while(left<=right)
    {
        int mid = left+(right-left)/2, mid_value = matrix[mid/col_size][mid%col_size];
        if(mid_value == target)
        {
            return true;
        }
        else if (mid_value < target)
        {
            left = mid+1;
        }
        else if (mid_value > target)
        {
            right = mid-1;
        }
    }

    return false;
}

int main()
{
    int data1[3][4] = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};
    int target = 3;
	vector<vector<int>> matrix;
	for (int i = 0; i < 3; ++i)
	{
		vector<int> vec_tmp1;
		for (int j = 0; j < 4; ++j)
		{
			vec_tmp1.push_back(data1[i][j]);
		}
		matrix.push_back(vec_tmp1);
	}
    auto ret = searchMatrix(matrix, target);
    assert(ret == true);

    target = 13;
    ret = searchMatrix(matrix, target);
    assert(ret == false);

    return 1;
}