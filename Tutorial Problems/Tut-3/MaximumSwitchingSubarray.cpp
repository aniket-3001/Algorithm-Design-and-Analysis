#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> dp;
    
    long long getMax(int ind, vector<int>& nums, bool isEven) {
        if (ind >= nums.size()) {
            return 0;
        }
        
        if (dp[ind][isEven] != -1) {
            return dp[ind][isEven];
        }
        
        long long pick;
        if (isEven) {
            pick = nums[ind] + getMax(ind + 1, nums, false);
        } else {
            pick = getMax(ind + 1, nums, true) - nums[ind];
        }
        
        long long notPick = getMax(ind + 1, nums, isEven);
        return dp[ind][isEven] = max(pick, notPick);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        dp.assign(nums.size(), vector<long long>(2, -1));
        return getMax(0, nums, true);
    }
};