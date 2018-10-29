// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

// 示例:

// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include<iostream>
#include<vector>

using namespace std;

void combine_step(vector<vector<int>>& ret, vector<int>& tmp, int n, int k)
{
    int start = 1;
    if(!tmp.empty())
    {
        start = tmp[tmp.size()-1]+1;
    }

    for(; start <= n; ++start)
    {
        tmp.push_back(start);
        if(tmp.size() == k)
        {
            ret.push_back(tmp);
        }else{
            combine_step(ret, tmp, n, k);
        }
        tmp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ret;
    vector<int> tmp;
    combine_step(ret, tmp, n, k);
    return ret;
}

int main()
{
    int n = 5, k = 3;
    auto ret = combine(n, k);
    cout << "[" << endl;
    for(auto arr : ret)
    {
        cout << "[";
        for(auto ele : arr)
        {
            cout << ele << " ";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
    return 1;
}