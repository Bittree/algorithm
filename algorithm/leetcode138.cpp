// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

// 要求返回这个链表的 深拷贝。 

// 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

//     val：一个表示 Node.val 的整数。
//     random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。

 

// 示例 1：

// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

// 示例 2：

// 输入：head = [[1,1],[2,1]]
// 输出：[[1,1],[2,1]]

// 示例 3：

// 输入：head = [[3,null],[3,0],[3,null]]
// 输出：[[3,null],[3,0],[3,null]]

// 示例 4：

// 输入：head = []
// 输出：[]
// 解释：给定的链表为空（空指针），因此返回 null。

 

// 提示：

//     -10000 <= Node.val <= 10000
//     Node.random 为空（null）或指向链表中的节点。
//     节点数目不超过 1000 。

#include<iostream>
#include<unordered_map>
#include<exception>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(!head) {
        return NULL;
    }
    Node* last = NULL;
    Node* cur = head;
    Node* ret = NULL;
    unordered_map<Node*, Node*> records;
    int index = 0;
    while(cur) {
        Node* newNode = NULL;
        auto it = records.find(cur);
        if(it == records.end()) {
            newNode = new Node(cur->val);
            records[cur] = newNode;
        }else{
            newNode = it->second;
        }
        if(last == NULL) {
            ret = newNode;
        }else{
            last->next = newNode;
        }

        if(cur->random) {
            Node* newRandom = NULL;
            it = records.find(cur->random);
            if(it == records.end()) {
                newRandom = new Node(cur->random->val);
                records[cur->random] = newRandom;
            }else{
                newRandom = it->second;
            }
            newNode->random = newRandom;
        }

        last = newNode;
        cur = cur->next;
    }
    return ret;
}

int main() {
    Node* node7 = new Node(7);
    Node* node13 = new Node(13);
    Node* node11 = new Node(11);
    Node* node10 = new Node(10);
    Node* node1 = new Node(1);
    node7->next = node13;
    node13->next = node11;
    node11->next = node10;
    node10->next = node1;
    node13->random = node7;
    node11->random = node1;
    node10->random = node11;
    node1->random = node7;

    Node* ret = copyRandomList(node7);
    cout << "[" << endl;
    while(ret) {
        cout << "ret: " << ret << " ret->next: " << ret->next << "[" << ret->val << "," << ret->random << "]," << endl;
        ret = ret->next;
    }
    cout << "]" << endl;
    return 0;
}