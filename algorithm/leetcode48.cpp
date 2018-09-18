// 给定一个 n × n 的二维矩阵表示一个图像。

// 将图像顺时针旋转 90 度。

// 说明：

// 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

// 示例 1:

// 给定 matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// 原地旋转输入矩阵，使其变为:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
// 示例 2:

// 给定 matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ], 

// 原地旋转输入矩阵，使其变为:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for(int i = 0; i < n/2; ++i)
    {
        for(int j = i; j < n-i-1; ++j)
        {
            int tmp = matrix[j][n-i-1];
            matrix[j][n-i-1] = matrix[i][j];

            swap(tmp,matrix[n-i-1][n-j-1]);
            swap(tmp, matrix[n-j-1][i]);
            swap(tmp, matrix[i][j]);
        }
    }
}

// void rotate(vector<vector<int>>& matrix)
// {
//     //转置
//     int len = matrix.size();
//     for (size_t i = 0; i < len; i++)
//     {
//         for (size_t j = i+1; j < len; j++)
//         {
//             int temp = matrix[i][j];
//             matrix[i][j] = matrix[j][i];
//             matrix[j][i] = temp;
//         }
//     }
//     //对称
//     for (size_t i = 0; i < len; i++)
//     {
//         for (size_t j = 0; j < len / 2; j++)
//         {
//             int temp = matrix[i][j];
//             matrix[i][j] = matrix[i][len-j-1];
//             matrix[i][len-j-1] = temp;
//         }
//     }
// }

int main()
{
    vector<vector<int>> matrix;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(4);
    tmp.push_back(5);
    tmp.push_back(6);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(7);
    tmp.push_back(8);
    tmp.push_back(9);
    matrix.push_back(tmp);

    cout << "[" << endl;
    for(auto arr: matrix)
    {
        cout << "  [ ";
        for(auto ele: arr)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    rotate(matrix);
    cout << "rotate 90 degrees:" << endl;
    cout << "[" << endl;
    for(auto arr: matrix)
    {
        cout << "  [ ";
        for(auto ele: arr)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    cout << "----------------------" << endl;

    matrix.clear();
    tmp.clear();
    tmp.push_back(5);
    tmp.push_back(1);
    tmp.push_back(9);
    tmp.push_back(11);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(2);
    tmp.push_back(4);
    tmp.push_back(8);
    tmp.push_back(10);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(13);
    tmp.push_back(3);
    tmp.push_back(6);
    tmp.push_back(7);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(15);
    tmp.push_back(14);
    tmp.push_back(12);
    tmp.push_back(16);
    matrix.push_back(tmp);

    cout << "[" << endl;
    for(auto arr: matrix)
    {
        cout << "  [ ";
        for(auto ele: arr)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    rotate(matrix);
    cout << "rotate 90 degrees:" << endl;
    cout << "[" << endl;
    for(auto arr: matrix)
    {
        cout << "  [ ";
        for(auto ele: arr)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 1;
}