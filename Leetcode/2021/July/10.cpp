// 981. 基于时间的键值存储
#include <bits/stdc++.h>
using namespace std;
class TimeMap
{
public:
    /** Initialize your data structure here. */
    map<string, map<int, string>> mp;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (mp.size() == 0 || mp[key].upper_bound(timestamp) == mp[key].begin())
            return "";
        else
            return (--mp[key].upper_bound(timestamp))->second;
    }
};
int main()
{
    string i = string({1});
    TimeMap sol;
    sol.set("love", "high", 10);
    sol.set("love", "low", 20);
    cout << sol.get("love", 5) << endl;
    cout << sol.get("love", 10) << endl;
    cout << sol.get("love", 15) << endl;
    cout << sol.get("love", 20) << endl;
    cout << sol.get("love", 25) << endl;
}

// iterator lower_bound( const key_type &key ): 返回一个迭代器，指向键值>= key的第一个元素。
// iterator upper_bound( const key_type &key ):返回一个迭代器，指向键值> key的第一个元素。