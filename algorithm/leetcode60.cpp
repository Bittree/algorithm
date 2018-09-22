// 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// 给定 n 和 k，返回第 k 个排列。

// 说明：

// 给定 n 的范围是 [1, 9]。
// 给定 k 的范围是[1,  n!]。
// 示例 1:

// 输入: n = 3, k = 3
// 输出: "213"
// 示例 2:

// 输入: n = 4, k = 9
// 输出: "2314"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getPermutation(int n, int k)
{
	string ret;
	if (n <= 0)
	{
		return ret;
	}
	int mul = 1;
	vector<int> nums;
	for (int i = 1; i <= n; ++i)
	{
		nums.push_back(i);
		mul *= i;
	}
	--k;
	for (int i = n; i > 0; --i)
	{
		mul /= i;
		int index = k / mul;
		k = k % mul;
		int n = nums[index];
		nums.erase(nums.begin()+index);
		ret.append(1, '0'+n);
	}
	return ret;
}

int main()
{
	int n = 3, k = 3;
	cout << "n = " << n << ", k = " << k << ":" << getPermutation(n ,k) << endl;

	n = 4, k = 9;
	cout << "n = " << n << ", k = " << k << ":" << getPermutation(n, k) << endl;
	return 1;
}