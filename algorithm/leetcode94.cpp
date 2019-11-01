// 给定一个二叉树，返回它的中序 遍历。

// 示例:

// 输入: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// 输出: [1,3,2]

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> ret;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(cur != NULL)
    {
        if(cur->left != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else if(cur->right != NULL)
        {
            ret.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            ret.push_back(cur->val);
            if(!st.empty())
            {
                cur = st.top();
                cur->left = NULL;
                st.pop();
            }
            else
            {
                cur = NULL;
            }
        }
        
    }
    return ret;
}

int main()
{
    TreeNode* v1 = new TreeNode(1);
    TreeNode* v2 = new TreeNode(2);
    TreeNode* v3 = new TreeNode(3);
    v1->right = v2;
    v2->left = v3;
    vector<int> ret = inorderTraversal(v1);
    for(int i = 0; i < ret.size(); ++i)
    {
        cout << ret[i] << endl;
    }
    return 1;
}