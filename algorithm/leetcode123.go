// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 示例 1:

// 输入: [3,3,5,0,0,3,1,4]
// 输出: 6
// 解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//      随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

// 示例 2:

// 输入: [1,2,3,4,5]
// 输出: 4
// 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//      注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
//      因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

// 示例 3:

// 输入: [7,6,4,3,1]
// 输出: 0
// 解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。

package main

import "fmt"

// dp[i][j][k]
// 三种状态：0<=i<len(prices) 第几天；j 还有几次交易次数；k 当前手中是否有股票
// dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]) 今天没有股票，要么昨天就没有股票，或者昨天有然后卖了
// dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]) 今天有股票，要么昨天就有股票，或者昨天没有但是今天买了
// Base case:
// dp[0][j][0] = 0 刚开始还没有买卖，手里不可能有股票，利润为0
// dp[0][j][1] 不可能出现这种情况
// dp[i][0][0] = 0 如果允许次数为0表示不允许买卖，利润为0
// dp[i][0][1] 不可能出现这种情况
func maxProfit(prices []int) int {
	n := len(prices)
	tradeTimes := 2
	dp := make([][][]int, n)
	max := func(a, b int) int {
		if a > b {
			return a
		} else {
			return b
		}
	}
	for i := 0; i < n; i++ {
		dp[i] = make([][]int, tradeTimes+1)
		for j := tradeTimes; j > 0; j-- {
			dp[i][j] = make([]int, tradeTimes)
			//dp[i][j][0] = 0
			if i == 0 {
				// dp[i][j][0] = max(dp[-1][j][0], dp[-1][j][1]+prices[i]) = max(0, impossible) = 0
				dp[i][j][0] = 0
				// dp[i][j][1] = max(dp[-1][j][1], dp[-1][j-1][0]-prices[i]) = max(impossible, -prices[i]) = -prices[i]
				dp[i][j][1] = -prices[i]
			} else {
				//fmt.Println("i: ", i, " j: ", j, " len(dp[i]): ", len(dp[i]), " len(dp[i][j]): ", len(dp[i][j]))
				dp[i][j][0] = 0 //max(dp[i-1][j][0], dp[i-1][j][1]+prices[i])
				dp[i][j][1] = 0 //max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i])
			}
		}
	}
	return dp[n-1][tradeTimes][0]
}

func main() {
	arr := []int{3, 3, 5, 0, 0, 3, 1, 4}
	ret := maxProfit(arr)
	fmt.Println(ret) // 6

	arr = []int{7, 6, 4, 3, 1}
	ret = maxProfit(arr)
	fmt.Println(ret) // 0

	arr = []int{1, 2, 3, 4, 5}
	ret = maxProfit(arr)
	fmt.Println(ret) // 4
}
