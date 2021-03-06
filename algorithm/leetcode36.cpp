// 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

// 数独部分空格内已填入了数字，空白格用 '.' 表示。

// 示例 1:

// 输入:
// [
//   ['5','3','.','.','7','.','.','.','.'],
//   ['6','.','.','1','9','5','.','.','.'],
//   ['.','9','8','.','.','.','.','6','.'],
//   ['8','.','.','.','6','.','.','.','3'],
//   ['4','.','.','8','.','3','.','.','1'],
//   ['7','.','.','.','2','.','.','.','6'],
//   ['.','6','.','.','.','.','2','8','.'],
//   ['.','.','.','4','1','9','.','.','5'],
//   ['.','.','.','.','8','.','.','7','9']
// ]
// 输出: true
// 示例 2:

// 输入:
// [
//   ['8','3','.','.','7','.','.','.','.'],
//   ['6','.','.','1','9','5','.','.','.'],
//   ['.','9','8','.','.','.','.','6','.'],
//   ['8','.','.','.','6','.','.','.','3'],
//   ['4','.','.','8','.','3','.','.','1'],
//   ['7','.','.','.','2','.','.','.','6'],
//   ['.','6','.','.','.','.','2','8','.'],
//   ['.','.','.','4','1','9','.','.','5'],
//   ['.','.','.','.','8','.','.','7','9']
// ]
// 输出: false
// 解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//      但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
// 说明:

// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
// 给定数独序列只包含数字 1-9 和字符 '.' 。
// 给定数独永远是 9x9 形式的。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct hashfunc {
	template<typename T, typename U>
	size_t operator()(const pair<T, U> &x) const {
		return hash<T>()(x.first) ^ hash<U>()(x.second);
	}
};

bool isValidSudoku(vector<vector<char>>& board)
{
    unordered_map<pair<int, int>, int, hashfunc> hor, ver, chunk;
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(board[i][j] != '.')
            {
                if(++hor[make_pair(j, board[i][j])] > 1) return false;
                if(++ver[make_pair(i, board[i][j])] > 1) return false;
                if(++chunk[make_pair(i/3*3+j/3, board[i][j])] > 1) return false;
            }
        }
    }
    return true;
}

bool isValidSudoku2(vector<vector<char>> &board)
{
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (used1[i][num] || used2[j][num] || used3[k][num])
                    return false;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }
        }
    }
    return true;
}

int main()
{
    char data1[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> vec1;
    for(int i = 0; i < 9; ++i)
    {
        vector<char> vec_tmp1(data1[i], data1[i]+9);
        vec1.push_back(vec_tmp1);
    }
    cout << boolalpha << isValidSudoku(vec1) << endl;

    char data2[9][9] = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> vec2;
    for(int i = 0; i < 9; ++i)
    {
        vector<char> vec_tmp2(data2[i], data2[i]+9);
        vec2.push_back(vec_tmp2);
    }
    cout << boolalpha << isValidSudoku(vec2) << endl;

    return 1;
}