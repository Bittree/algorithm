// 编写一个程序，通过已填充的空格来解决数独问题。

// 一个数独的解法需遵循如下规则：

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
// 空白格用 '.' 表示。

// Note:

// 给定的数独序列只包含数字 1-9 和字符 '.' 。
// 你可以假设给定的数独只有唯一解。
// 给定数独永远是 9x9 形式的。

#include<iostream>
#include<vector>
#include<array>

using namespace std;

bool solve(vector<vector<char>>& board, int pos, array<array<bool, 9>, 9>& hoz, array<array<bool, 9>, 9>& ver, array<array<bool, 9>, 9>& block)
{
    if(pos > 80) return true;
    int row = pos/9;
    int col = pos%9;
    int block_num = row/3*3+col/3;
    if(board[row][col] != '.')return solve(board, pos+1, hoz, ver, block);
    for(int i = 1; i < 10; ++i)
    {
        if(hoz[row][i] || ver[col][i] || block[block_num][i])
        {
            continue;
        }
        hoz[row][i] = true;
        ver[col][i] = true;
        block[block_num][i] = true;
        board[row][col] = i + '0';
        if(solve(board, pos+1, hoz, ver, block))
        {
            return true;
        }else{
            board[row][col] = '.';
            hoz[row][i] = false;
            ver[col][i] = false;
            block[block_num][i] = false;
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board)
{
    array<array<bool, 9>, 9> hoz = {{false}};
    array<array<bool ,9>, 9> ver = {{false}};
    array<array<bool ,9>, 9> block {{false}};
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(board[i][j] == '.')continue;
            int cur = board[i][j] - '0';
            hoz[i][cur] = true;
            ver[j][cur] = true;
            block[i/3*3+j/3][cur] = true;
        }
    }
    solve(board, 0, hoz, ver, block);
}

int main()
{
    // char data1[9][9] = {
    //     {'5','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','.','.','8','.','.','7','9'}
    // };
    // char data1[9][9] = {
    //     {'.','.','.','2','.','.','.','6','3'},
    //     {'3','.','.','.','.','5','4','.','1'},
    //     {'.','.','1','.','.','3','9','8','.'},
    //     {'.','.','.','.','.','.','.','9','.'},
    //     {'.','.','.','5','3','8','.','.','.'},
    //     {'.','3','.','.','.','.','.','.','.'},
    //     {'.','2','6','3','.','.','5','.','.'},
    //     {'5','.','3','7','.','.','.','.','8'},
    //     {'4','7','.','.','.','1','.','.','.'}
    // };
    char data1[9][9] = {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };
    vector<vector<char>> vec1;
    for(int i = 0; i < 9; ++i)
    {
        vector<char> vec_tmp1(data1[i], data1[i]+9);
        vec1.push_back(vec_tmp1);
    }
    solveSudoku(vec1);
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cout << vec1[i][j] << " ";
        }
        cout << endl;
    }

    return 1;
}