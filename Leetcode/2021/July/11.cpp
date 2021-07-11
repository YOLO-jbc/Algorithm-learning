#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size(), tot = 0;
        vector<int> counter(n + 1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                counter[n]++;
            } else {
                counter[citations[i]]++;
            }
        }
        for (int i = n; i >= 0; i--) {
            tot += counter[i];  //!counter[i] 表示引用次数为i的论文有几篇
            if (tot >= i) {     //!对于每个0 <= i <= n在数组 counter 中得到大于或等于当前引用次数 i 的总论文数
                return i;
            }
        }
        return 0;
    }
};