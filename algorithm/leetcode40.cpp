// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用一次。

// 说明：

// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。 
// 示例 1:

// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// 示例 2:

// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:
// [
//   [1,2,2],
//   [5]
// ]

#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

void sumRecursion(vector<vector<int>>& result, vector<int>& candidates, int target, vector<int> cur, int sum, int start)
{
    if(sum == target)
    {
        return;
    }
    int size = candidates.size(), cur_size = cur.size();
    for(int i = start; i < size; ++i)
    {
        if(cur_size > 0 && candidates[i] < cur[cur_size-1])
        {
            continue;
        }

        if(candidates[i]+sum < target)
        {
            auto tmp = cur;
            tmp.push_back(candidates[i]);
            sumRecursion(result, candidates, target, tmp, candidates[i]+sum, i+1);
        }else if(candidates[i]+sum == target)
        {
            auto tmp = cur;
            tmp.push_back(candidates[i]);
            result.push_back(tmp);
        }else{
            return;
        }

        int count = 1;
        while(i+count < size && candidates[i] == candidates[i+count])
        {
            count++;
        }
        i += (count-1);
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    sumRecursion(result, candidates, target, vector<int>(), 0, 0);
    return result;
}

int main()
{
    int target = 5;
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(5);
    candidates.push_back(2);
    candidates.push_back(1);
    candidates.push_back(2);
    cout << "---------------------------------" << endl;
    cout << "[";
    for(auto ele : candidates)
    {
        cout << ele << " ";
    }
    cout << "], target: " << target << endl;
    auto ret = combinationSum2(candidates, target);
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