// 给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

// 例如，
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

// 边界情况:

// 你是否考虑了 路径 = "/../" 的情况？
// 在这种情况下，你需返回 "/" 。
// 此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
// 在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path)
{
    vector<string> record;
    int index = 0, len = path.length();
    while (index < len - 1)
    {
        auto found = path.find('/', index + 1);
        if (found == string::npos)
        {
            string substr = path.substr(index + 1);
            if (substr == "..")
            {
                if (!record.empty())
                    record.pop_back();
            }
            else if (!substr.empty() && substr != ".")
            {
                record.push_back(substr);
            }
            break;
        }
        else
        {
            string substr = path.substr(index + 1, found - index - 1);
            if (substr == "..")
            {
                if (!record.empty())
                    record.pop_back();
            }
            else if (!substr.empty() && substr != ".")
            {
                record.push_back(substr);
            }
            index = found;
        }
    }
    string ret;
    if (record.empty())
    {
        ret.append(1, '/');
    }
    for (auto ele : record)
    {
        ret.append(1, '/');
        ret.append(ele);
    }
    return ret;
}

int main()
{
    string path = "/home/";
    cout << path << " : " << simplifyPath(path) << endl;

    path = "/a/./b/../../c/";
    cout << path << " : " << simplifyPath(path) << endl;

    path = "/../";
    cout << path << " : " << simplifyPath(path) << endl;

    path = "/home//foo/";
    cout << path << " : " << simplifyPath(path) << endl;

    path = "/.";
    cout << path << " : " << simplifyPath(path) << endl;

    path = "///eHx/..";
    cout << path << " : " << simplifyPath(path) << endl;

    return 1;
}