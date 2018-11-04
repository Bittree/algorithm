// 给定一个二维网格和一个单词，找出该单词是否存在于网格中。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

// 示例:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// 给定 word = "ABCCED", 返回 true.
// 给定 word = "SEE", 返回 true.
// 给定 word = "ABCB", 返回 false.

#include<iostream>
#include<vector>
#include <string>

using namespace std;

bool exist_dfs(vector<vector<char>>& board, string& word, int i, int j, int word_index)
{
    if(board[i][j] == word[word_index] && word_index == word.size()-1)
    {
        return true;
    }

    board[i][j] = 0;
    bool ret = false;
    if(j > 0 && board[i][j-1] == word[word_index+1] && exist_dp(board, word, i, j-1, word_index+1)
    || j < board[0].size()-1 && board[i][j+1] == word[word_index+1] && exist_dp(board, word, i, j+1, word_index+1)
    || i > 0 && board[i-1][j] == word[word_index+1] && exist_dp(board, word, i-1, j, word_index+1)
    || i < board.size()-1 && board[i+1][j] == word[word_index+1] && exist_dp(board, word, i+1, j, word_index+1))
    {
        ret = true;
    }

    board[i][j] = word[word_index];
    return ret;
}

bool exist(vector<vector<char>>& board, string word)
{
    if((board.empty() || board[0].empty()) && word.empty())
    {
        return false;
    }
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(board[i][j] == word[0] && exist_dp(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    char data1[3][4] = {
		{ 'A', 'B', 'C', 'E' },
		{ 'S', 'F', 'C', 'S' },
		{ 'A', 'D', 'E', 'E' }
	};
    string word = "ABCCED";
	vector<vector<char>> matrix;
	for (int i = 0; i < 3; ++i)
	{
		vector<char> vec_tmp1;
		for (int j = 0; j < 4; ++j)
		{
			vec_tmp1.push_back(data1[i][j]);
		}
		matrix.push_back(vec_tmp1);
	}
    cout << boolalpha << exist(matrix, word) << endl;

    word = "SEE";
    cout << boolalpha << exist(matrix, word) << endl;

    word = "ABCB";
    cout << boolalpha << exist(matrix, word) << endl;

    return 1;
}