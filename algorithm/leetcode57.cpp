// 给出一个无重叠的 ，按照区间起始端点排序的区间列表。

// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

// 示例 1:

// 输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
// 输出: [[1,5],[6,9]]
// 示例 2:

// 输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// 输出: [[1,2],[3,10],[12,16]]
// 解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

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

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
    intervals.emplace_back(newInterval);
    return merge(intervals);
}

int main()
{
    vector<Interval> intervals;
    intervals.emplace_back(Interval(1, 3));
    intervals.emplace_back(Interval(6, 9));
    cout << "[ ";
    for (auto ele : intervals)
    {
        cout << "[" << ele.start << "," << ele.end << "]"
             << " ";
    }
    cout << "] : [ ";
    auto result = insert(intervals, Interval(2, 5));
    for (auto ele : result)
    {
        cout << "[" << ele.start << "," << ele.end << "]"
             << " ";
    }
    cout << "]" << endl;

    intervals.clear();
    intervals.emplace_back(Interval(1, 2));
    intervals.emplace_back(Interval(3, 5));
    intervals.emplace_back(Interval(6, 7));
    intervals.emplace_back(Interval(8, 10));
    intervals.emplace_back(Interval(12, 16));
    cout << "[ ";
    for (auto ele : intervals)
    {
        cout << "[" << ele.start << "," << ele.end << "]"
             << " ";
    }
    cout << "] : [ ";
    result = insert(intervals, Interval(4, 8));
    for (auto ele : result)
    {
        cout << "[" << ele.start << "," << ele.end << "]"
             << " ";
    }
    cout << "]" << endl;

    return 1;
}