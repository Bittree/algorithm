// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

// 示例 1:

// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 示例 2:

// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int longestValidParentheses(string s)
{
    int str_len = s.length();
    if(str_len==0||str_len==1)return 0;
    stack<int> left;
    stack<int> right;
    int max_count = 0;
    for(int i = 0; i < str_len; ++i)
    {
        if(s[i] == '(')
        {
            left.push(i);
        }else if(s[i] == ')' && left.size() > right.size())
        {
            right.push(i);
        }else{
            int tmp_count = 0;
            while(left.size()>0 && right.size()>0)
            {
                if(right.top()>left.top())
                {
                    tmp_count+=2;
                    right.pop();
                    left.pop();
                }else{
                    left.pop();
                    max_count = tmp_count>max_count?tmp_count:max_count;
                    tmp_count = 0;
                }
            }
            max_count = tmp_count>max_count?tmp_count:max_count;
            while(left.size() > 0)
            {
                left.pop();
            }
            while(right.size() > 0)
            {
                right.pop();
            }
        }
    }

    int tmp_count = 0;
    while(left.size()>0 && right.size()>0)
    {
        if(right.top()>left.top())
        {
            tmp_count+=2;
            right.pop();
            left.pop();
        }else{
            left.pop();
            max_count = tmp_count>max_count?tmp_count:max_count;
            tmp_count = 0;
        }
    }
    max_count = tmp_count>max_count?tmp_count:max_count;

    return max_count;
}

int longestValidParentheses2(string s) {
    int max = 0,num = s.size();
    if(num==0||num==1)return 0;
    stack<int> sta;
    sta.push(-1);
    for(int i = 0;i<num;i++){
        if(sta.size()==0){
            sta.push(i);
            continue;
        }
        if(s[i] == ')' && s[sta.top()] == '(') sta.pop();
        else sta.push(i);
    }
    int right = num;
    while(!sta.empty()){
        int len = right-sta.top()-1;
        if(len>1)max = max>len?max:len;
        right = sta.top();
        sta.pop();
    }
    return max;
}

int main()
{
    cout << "(() : " << longestValidParentheses("(()") << endl;
    cout << ")()()) : " << longestValidParentheses(")()())") << endl;
    cout << "()(()() : " << longestValidParentheses("()(()()") << endl;
    return 0;
}