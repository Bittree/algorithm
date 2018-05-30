#include <iostream>
#include <queue>
#include <stack>
#include <functional>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* lChild;
	TreeNode* rChild;
	TreeNode() :data(-1), lChild(nullptr), rChild(nullptr) {}
};

class BinaryTree
{
public:
	BinaryTree()
	{
		m_root = new TreeNode();
		TreeNode* ptmp = m_root;
		int numlimit = 10;
		queue<TreeNode*> s;
		s.push(ptmp);
		int counter = 0;
		while (!s.empty())
		{
			TreeNode* ele = s.front();
			s.pop();
			ele->data = ++counter;
			if (numlimit - counter - s.size() > 1)
			{
				ele->lChild = new TreeNode();
				ele->rChild = new TreeNode();
				s.push(ele->lChild);
				s.push(ele->rChild);
			}
			else if (numlimit - counter - s.size() > 0)
			{
				ele->lChild = new TreeNode();
				s.push(ele->lChild);
			}
		}
	}

	~BinaryTree()
	{
		stack<TreeNode*> s;
		TraverseTree_level(m_root, [&](TreeNode* pnode) {
			s.push(pnode);
		});
		while (!s.empty())
		{
			TreeNode* node = s.top();
			s.pop();
			delete node;
		}
	}

	TreeNode* GetRoot()
	{
		return m_root;
	}

	// 前序遍历，递归方式
	void TraverseTree_forward(TreeNode* node, std::function<void(TreeNode*)> action)
	{
		if (!node)
		{
			return;
		}
		action(node);
		if (node->lChild)
		{
			TraverseTree_forward(node->lChild, action);
		}
		if (node->rChild)
		{
			TraverseTree_forward(node->rChild, action);
		}
	}

	// 中序遍历，递归方式
	void TraverseTree1_middle(TreeNode* node, std::function<void(TreeNode*)> action)
	{
		if (!node)
		{
			return;
		}
		if (node->lChild)
		{
			TraverseTree1_middle(node->lChild, action);
		}
		action(node);
		if (node->rChild)
		{
			TraverseTree1_middle(node->rChild, action);
		}
	}

	// 后序遍历，递归方式
	void TraverseTree1_back(TreeNode* node, std::function<void(TreeNode*)> action)
	{
		if (!node)
		{
			return;
		}
		if (node->lChild)
		{
			TraverseTree1_back(node->lChild, action);
		}
		if (node->rChild)
		{
			TraverseTree1_back(node->rChild, action);
		}
		action(node);
	}

	// 前序遍历,非递归方式
	void TraverseTree_forward2(TreeNode* node, std::function<void(TreeNode*)> action)
	{
		if (!node)
		{
			return;
		}
		stack<TreeNode*> stack;
		TreeNode* pcur = node;
		while (!stack.empty() || pcur)
		{
			while (pcur)
			{
				stack.push(pcur);
				action(pcur);
				pcur = pcur->lChild;
			}
			if (!stack.empty())
			{
				TreeNode* ele = stack.top();
				stack.pop();
				pcur = ele->rChild;
			}
		}
	}

	// 中序遍历,非递归方式
	void TraverseTree_middle2(TreeNode* node, std::function<void(TreeNode*)> action)
	{
		if (!node)
		{
			return;
		}
		stack<TreeNode*> stack;
		TreeNode* pcur = node;
		while (!stack.empty() || pcur)
		{
			while (pcur)
			{
				stack.push(pcur);
				pcur = pcur->lChild;
			}
			if (!stack.empty())
			{
				TreeNode* ele = stack.top();
				stack.pop();
				action(ele);
				pcur = ele->rChild;
			}
		}
	}

	// 后序遍历,非递归方式
	void TraverseTree_back2(TreeNode* node, std::function<void(TreeNode*)> action)
	{
		if (!node)
		{
			return;
		}
		stack<TreeNode*> stack;
		stack.push(node);
		TreeNode* pre = nullptr;
		while (!stack.empty())
		{
			TreeNode* pnode = stack.top();
			if ((!pnode->lChild && !pnode->rChild) || (pre && (pre == pnode->lChild || pre == pnode->rChild)))
			{
				stack.pop();
				action(pnode);
				pre = pnode;
			}
			else 
			{
				if (pnode->rChild)
				{
					stack.push(pnode->rChild);
				}
				if (pnode->lChild)
				{
					stack.push(pnode->lChild);
				}
			}
		}
	}

	// 层序遍历
	void TraverseTree_level(TreeNode* node, std::function<void(TreeNode*)> action)
	{
		if (!node)
		{
			return;
		}
		queue<TreeNode*> stack;
		stack.push(node);
		while (!stack.empty())
		{
			TreeNode* pNode = stack.front();
			stack.pop();
			action(pNode);
			if (pNode->lChild)
			{
				stack.push(pNode->lChild);
			}
			if (pNode->rChild)
			{
				stack.push(pNode->rChild);
			}
		}
	}

private:
	TreeNode* m_root;
};

int main()
{
	BinaryTree tree;
	cout << "TraverseTree_forward: ";
	tree.TraverseTree_forward(tree.GetRoot(), [](TreeNode* pnode) { cout << pnode->data << " "; });
	cout << endl;

	cout << "TraverseTree1_middle: ";
	tree.TraverseTree1_middle(tree.GetRoot(), [](TreeNode* pnode) { cout << pnode->data << " "; });
	cout << endl;

	cout << "TraverseTree1_back: ";
	tree.TraverseTree1_back(tree.GetRoot(), [](TreeNode* pnode) { cout << pnode->data << " "; });
	cout << endl;

	cout << "TraverseTree_forward2: ";
	tree.TraverseTree_forward2(tree.GetRoot(), [](TreeNode* pnode) { cout << pnode->data << " "; });
	cout << endl;

	cout << "TraverseTree_middle2: ";
	tree.TraverseTree_middle2(tree.GetRoot(), [](TreeNode* pnode) { cout << pnode->data << " "; });
	cout << endl;

	cout << "TraverseTree_back2: ";
	tree.TraverseTree_back2(tree.GetRoot(), [](TreeNode* pnode) { cout << pnode->data << " "; });
	cout << endl;
	return 0;
}