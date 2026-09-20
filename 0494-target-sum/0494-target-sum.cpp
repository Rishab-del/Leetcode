class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> dp;
        dp[0]=1;

        for(int num:nums){
            unordered_map<int, int> next;
            for (auto [sum, ways] : dp) {
                next[sum + num] += ways;
                next[sum - num] += ways;
            }
            dp=next;
        }
        return dp[target];
    }
};