// 给出一个区间的集合，请合并所有重叠的区间。

// 示例 1:

// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:

// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval> &intervals)
{
    int size = intervals.size();
    if (size <= 1)
    {
        return intervals;
    }
    vector<Interval> ret;
    for (auto interval : intervals)
    {
        bool hasInserted = false;
        for (auto itor = ret.begin(); itor != ret.end();)
        {
            if (interval.end < itor->start)
            {
                hasInserted = true;
                ret.insert(itor, interval);
                break;
            }
            else if (interval.start > itor->end)
            {
                itor++;
                continue;
            }

            interval.start = interval.start < itor->start ? interval.start : itor->start;
            interval.end = interval.end > itor->end ? interval.end : itor->end;
            itor = ret.erase(itor);
        }
        if (!hasInserted)
        {
            ret.emplace_back(interval);
        }
    }
    return ret;
}

int main()
{
    vector<Interval> intervals;
    intervals.emplace_back(Interval(1, 3));
    intervals.emplace_back(Interval(2, 6));
    intervals.emplace_back(Interval(8, 10));
    intervals.emplace_back(Interval(15, 18));
    cout << "[ ";
    for (auto ele : intervals)
    {
        cout << "[" << ele.start << "," << ele.end << "]"
             << " ";
    }
    cout << "] : [ ";
    auto result = merge(intervals);
    for (auto ele : result)
    {
        cout << "[" << ele.start << "," << ele.end << "]"
             << " ";
    }
    cout << "]" << endl;

    intervals.clear();
    intervals.emplace_back(Interval(2, 4));
    intervals.emplace_back(Interval(0, 1));
    cout << "[ ";
    for (auto ele : intervals)
    {
        cout << "[" << ele.start << "," << ele.end << "]"
             << " ";
    }
    cout << "] : [ ";
    result = merge(intervals);
    for (auto ele : result)
    {
        cout << "[" << ele.start << "," << ele.end << "]"
             << " ";
    }
    cout << "]" << endl;

    return 1;
}