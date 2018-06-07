// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

// 例如，给出 n = 3，生成结果为：

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> generateParenthesis(int n) {
	vector<string> ret;
	if (n < 1)
	{
		return ret;
	}
	struct Node
	{
		Node(string ss, int l, int r) : str(ss), LNum(l), RNum(r) {}
		string str;
		int LNum;
		int RNum;
	};
	stack<Node*> s;
	s.push(new Node("(", n - 1, n));
	while (!s.empty())
	{
		Node* pOrigin = s.top();
		s.pop();
		if (pOrigin->LNum <= pOrigin->RNum)
		{
			if (pOrigin->LNum == 0 && pOrigin->RNum == 0)
			{
				ret.push_back(pOrigin->str);
			}
			else {
				if (pOrigin->LNum > 0)
				{
					s.push(new Node(pOrigin->str + "(", pOrigin->LNum - 1, pOrigin->RNum));
				}
				if (pOrigin->RNum > 0)
				{
					s.push(new Node(pOrigin->str + ")", pOrigin->LNum, pOrigin->RNum - 1));
				}
			}
		}
		delete pOrigin;
	}

	return ret;
}

int main()
{
	auto ret = generateParenthesis(3);
	for (string ele : ret)
	{
		cout << ele.c_str() << endl;
	}
	return 0;
}