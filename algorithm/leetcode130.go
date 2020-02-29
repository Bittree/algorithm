// 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

// 示例:

// X X X X
// X O O X
// X X O X
// X O X X

// 运行你的函数后，矩阵变为：

// X X X X
// X X X X
// X X X X
// X O X X

// 解释:

// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

package main

import "fmt"

func bfs(board [][]byte, x int, y int) {
	if x < 0 || y < 0 || x >= len(board) || y >= len(board[0]) || board[x][y] != 'O' {
		return
	}
	board[x][y] = 'K'
	bfs(board, x-1, y)
	bfs(board, x+1, y)
	bfs(board, x, y-1)
	bfs(board, x, y+1)
}

func solve(board [][]byte) {
	row := len(board)
	if row <= 2 {
		return
	}
	col := len(board[0])
	if col <= 2 {
		return
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if (i == 0 || i == row-1 || j == 0 || j == col-1) && board[i][j] == 'O' {
				bfs(board, i, j)
			}
		}
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if board[i][j] == 'O' {
				board[i][j] = 'X'
			} else if board[i][j] == 'K' {
				board[i][j] = 'O'
			}
		}
	}
}

// ----------------并查集解法------------------------

func solve2(board [][]byte) {
	row := len(board)
	if row <= 2 {
		return
	}
	col := len(board[0])
	if col <= 2 {
		return
	}
	pre := make([]int, row*col+1)
	for i := 0; i < row*col+1; i++ {
		pre[i] = i
	}
	node := func(x, y int) int {
		return x*col + y
	}
	find := func(x int) int {
		for pre[pre[x]] != pre[x] {
			pre[x] = pre[pre[x]]
		}
		return pre[x]
	}
	union := func(x, y int) {
		rootx := find(x)
		rooty := find(y)
		if rootx != rooty {
			pre[x] = pre[y]
		}
	}
	isConnected := func(x, y int) bool {
		return pre[x] == pre[y]
	}
	root := row * col
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if board[i][j] == 'O' {
				if i == 0 || j == 0 || i == row-1 || j == col-1 {
					pre[node(i, j)] = root
				} else {
					if i > 0 && board[i-1][j] == 'O' {
						union(node(i, j), node(i-1, j))
					}
					if i < row-1 && board[i+1][j] == 'O' {
						union(node(i, j), node(i+1, j))
					}
					if j > 0 && board[i][j-1] == 'O' {
						union(node(i, j), node(i, j-1))
					}
					if j < col-1 && board[i][j+1] == 'O' {
						union(node(i, j), node(i, j+1))
					}
				}
			}
		}
	}
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if board[i][j] == 'O' && !isConnected(node(i, j), root) {
				board[i][j] = 'X'
			}
		}
	}
}

// ----------------------------------------

func main() {
	arr := [][]byte{
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
	}
	solve2(arr)
	for _, target := range arr {
		for _, v := range target {
			fmt.Printf("%c ", v)
		}
		fmt.Println(",")
	}
}
