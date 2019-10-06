// 对于给定的 n，其格雷编码序列并不唯一。
// 例如，[0,2,3,1] 也是一个有效的格雷编码序列。

// 00 - 0
// 10 - 2
// 11 - 3
// 01 - 1

// 示例 2:

// 输入: 0
// 输出: [0]
// 解释: 我们定义格雷编码序列必须以 0 开头。
//      给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
//      因此，当 n = 0 时，其格雷编码序列为 [0]。

#include<iostream>
#include <string>
#include<vector>
#include<math.h>

using namespace std;

vector<int> grayCode(int n) 
{
    vector<int> ret(0, n);
    for(int i = 0; i < pow(2, n); ++i)
    {
        ret.push_back((i>>1)^i);
    }
    return ret;
}

vector<int> grayCode2(int n)
{
    vector<int> ret;
    if(n == 0)
    {
        ret.push_back(0);
    }
    else if(n == 1)
    {
        ret.push_back(0);
        ret.push_back(1);
    }else if(n != 0)
    {
        vector<int> ans = grayCode2(n-1);
        int num = 1 << (n-1);
        for(int i = ans.size()-1; i >= 0; --i)
        {
            ans.push_back(num + ans[i]);
        }
        return ans;
    }
    return ret;
}

int main()
{
    auto ret = grayCode2(3);
    for(int i = 0; i < ret.size(); ++i)
    {
        cout << ret[i] << endl;
    }
    return 1;
}