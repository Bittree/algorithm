// 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

// 示例:

// 输入: 3
// 输出: 5
// 解释:
// 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include<iostream>
#include<vector>

using namespace std;

// 1、G(n) = F(1,n)+...+F(i,n) (1<=i<=n))
// 2、F(i, n) = G(i-1)*G(n-i)
// 3、G(0) = 1; G(1) = 1;

int numTrees(int n) 
{
    vector<int> vec(n+1, 0);
    vec[0] = 1;
    vec[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            vec[i] += (vec[j-1]*vec[i-j]);
        }
    }
    return vec[n];
}

int main()
{
    int ret = numTrees(3);
    cout << ret << endl;
    return 1;
}