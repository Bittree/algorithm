// 二叉搜索树中的两个节点被错误地交换。

// 请在不改变其结构的情况下，恢复这棵树。

// 示例 1:

// 输入: [1,3,null,null,2]

//    1
//   /
//  3
//   \
//    2

// 输出: [3,1,null,null,2]

//    3
//   /
//  1
//   \
//    2

// 示例 2:

// 输入: [3,1,4,null,null,2]

//   3
//  / \
// 1   4
//    /
//   2

// 输出: [2,1,4,null,null,3]

//   2
//  / \
// 1   4
//    /
//   3

// 进阶:

//     使用 O(n) 空间复杂度的解法很容易实现。
//     你能想出一个只使用常数空间的解决方案吗？

#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode* root) 
{
    // morris 遍历
    TreeNode* cur = root, *node1 = NULL, *node2 = NULL, *lastNode = NULL;
    while(cur)
    {
        if(cur->left)
        {
            TreeNode* preNode = cur->left;
            while(preNode->right && preNode->right != cur)
            {
                preNode = preNode->right;
            }
            if(preNode->right && preNode->right == cur)
            {
                // cur
                if(lastNode && lastNode->val > cur->val)
                {
                    if(node1)
                    {
                        node2 = cur;
                    }
                    else
                    {
                        node1 = lastNode;
                        node2 = cur;
                    }
                }

                preNode->right = NULL;
                lastNode = cur;
                cur = cur->right;
            }
            else
            {
                preNode->right = cur;
                cur = cur->left;
            }
        }
        else
        {
            // cur
            if(lastNode && lastNode->val > cur->val)
            {
                if(node1)
                {
                    node2 = cur;
                }
                else
                {
                    node1 = lastNode;
                    node2 = cur;
                }
            }

            lastNode = cur;
            cur = cur->right;
        }
    }
    node1->val = node1->val ^ node2->val;
    node2->val = node1->val ^ node2->val;
    node1->val = node1->val ^ node2->val;
}

int main()
{
    TreeNode* v1 = new TreeNode(1);
    TreeNode* v2 = new TreeNode(2);
    TreeNode* v3 = new TreeNode(3);
    v1->right = v2;
    v2->left = v3;
    recoverTree(v1);
    return 1;
}