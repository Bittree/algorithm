// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

// 示例:

// 输入: 3
// 输出:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// 解释:
// 以上的输出对应以下 5 种不同结构的二叉搜索树：

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generate(int start, int end)
{
    vector<TreeNode*> result;
    if(start > end)
    {
        result.push_back(NULL);
        return result;
    }

    for(int i = start; i <= end; ++i)
    {
        vector<TreeNode*> leftTreeVec = generate(start, i-1);
        vector<TreeNode*> rightTreeVec = generate(i+1, end);
        for(TreeNode* leftTree : leftTreeVec)
        {
            for(TreeNode* rightTree: rightTreeVec)
            {
                TreeNode* newNode = new TreeNode(i);
                newNode->left = leftTree;
                newNode->right = rightTree;
                result.push_back(newNode);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n) {
    if(n == 0)
    {
        vector<TreeNode*> ret;
        return ret;
    }
    return generate(1, n);
}