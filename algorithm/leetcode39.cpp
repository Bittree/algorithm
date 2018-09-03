// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的数字可以无限制重复被选取。

// 说明：

// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。 
// 示例 1:

// 输入: candidates = [2,3,6,7], target = 7,
// 所求解集为:
// [
//   [7],
//   [2,2,3]
// ]
// 示例 2:

// 输入: candidates = [2,3,5], target = 8,
// 所求解集为:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

void sumRecursion(vector<vector<int>>& result, vector<int>& candidates, int target, vector<int> cur, int sum)
{
    if(sum == target)
    {
        return;
    }
    int size = candidates.size(), cur_size = cur.size();
    for(int i = 0; i < size; ++i)
    {
        if(cur_size > 0 && candidates[i] < cur[cur_size-1])
        {
            continue;
        }
        if(candidates[i]+sum < target)
        {
            auto tmp = cur;
            tmp.push_back(candidates[i]);
            sumRecursion(result, candidates, target, tmp, candidates[i]+sum);
        }else if(candidates[i]+sum == target)
        {
            auto tmp = cur;
            tmp.push_back(candidates[i]);
            result.push_back(tmp);
            continue;
        }else{
            return;
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    sumRecursion(result, candidates, target, vector<int>(), 0);
    return result;
}

int main()
{
    int target = 8;
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(5);
    cout << "---------------------------------" << endl;
    cout << "[";
    for(auto ele : candidates)
    {
        cout << ele << " ";
    }
    cout << "], target: " << target << endl;
    auto ret = combinationSum(candidates, target);
    cout << "[" << endl;
    for(auto arr: ret)
    {
        cout << "[";
        for(auto ele: arr)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    cout << "---------------------------------" << endl;
}