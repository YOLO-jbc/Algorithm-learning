// 面试题 17.10. 主要元素
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size  = nums.size();
        int temp;
        int count = 0;
        for(int i = 0;i<size;i++)
        {
            if(count == 0)
            {
                temp = nums[i];
            }
            if(nums[i]==temp)
            {
                count++;
            }
            else count--;
        }
        count = 0;
        for(int i = 0;i<size;i++)
        {
            if(nums[i]==temp)
                count++;    
        }
        if(count*2>size)
            return temp;
        else 
            return -1;
    }
};