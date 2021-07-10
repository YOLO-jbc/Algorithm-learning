// 930. 和相同的二元子数组
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,int>count;
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int size = nums.size();
        int tempsum = 0;
        int ret = 0;
        for(int i = 0;i<size;i++)
        {
            count[tempsum]++;
            tempsum+=nums[i];
            ret+=count[tempsum-goal];
        }
        return ret;
    }
};
