// 给定一个二叉树

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }

// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

// 初始状态下，所有 next 指针都被设置为 NULL。

 

// 进阶：

//     你只能使用常量级额外空间。
//     使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

 

// 示例：

// 输入：root = [1,2,3,4,5,null,7]
// 输出：[1,#,2,3,#,4,5,7,#]
// 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

 

// 提示：

//     树中的节点数小于 6000
//     -100 <= node.val <= 100

#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    Node* cur = root, *prev = NULL, *nextlayerhead = NULL;
    while(cur != NULL) {
        prev = NULL;
        for(Node* target = cur; target; target = target->next) {
            if(target->left != NULL) {
                if(nextlayerhead == NULL) {
                    nextlayerhead = target->left;
                }
                if(prev != NULL) {
                    prev->next = target->left;
                    prev = NULL;
                }
                prev = target->left;
            }
            if(target->right != NULL) {
                if(nextlayerhead == NULL) {
                    nextlayerhead = target->right;
                }
                if(prev != NULL) {
                    prev->next = target->right;
                    prev = NULL;
                }
                prev = target->right;
            }
        }
        cur = nextlayerhead;
        nextlayerhead = NULL;
    }
    return root;        
}

int main() {
    Node* root = (Node*)new Node(-9, 
        (Node*)new Node(-3, NULL, (Node*)new Node(4, (Node*)new Node(-6), NULL, NULL), NULL), 
        (Node*)new Node(2, (Node*)new Node(4, (Node*)new Node(-5), NULL, NULL), (Node*)new Node(0), NULL), 
    NULL);
    root = connect(root);
    while(root) {
        Node* cur = root;
        Node* nextLayerHead = NULL;
        while(cur) {
            cout << cur->val << " -> ";
            if(nextLayerHead == NULL) {
                if(cur->left != NULL) {
                    nextLayerHead = cur->left;
                }else if(cur->right != NULL) {
                    nextLayerHead = cur->right;
                }
            }
            cur = cur->next;
        }
        cout <<endl;
        root = nextLayerHead;
    }
    return 0;
}