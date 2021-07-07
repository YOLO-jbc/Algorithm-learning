// 1711. 大餐计数
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1000000007;
    map<int, int> mptimes;
    int countPairs(vector<int> &deliciousness)
    {
        int maximum = *max_element(deliciousness.begin(), deliciousness.end());
        maximum *= 2;
        int ret = 0;
        int size = deliciousness.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 1; j <= maximum; j *= 2)
            {
                int nums;
                if (nums = mptimes.count(j - deliciousness[i]))
                    nums = mptimes[j - deliciousness[i]];
                ret = (ret + nums) % mod;
            }
            mptimes[deliciousness[i]]++;
        }
        return ret;
    }
};
int main()
{
    Solution sol;
    vector<int>invec = {1,1,1,3,3,3,7};
    cout<<sol.countPairs(invec)<<endl;
}