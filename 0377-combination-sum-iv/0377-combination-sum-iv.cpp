class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; t++) {
            for (int num : nums) {
                if (num <= t) {
                    if (dp[t] > INT_MAX - dp[t - num])
                        dp[t] = INT_MAX;
                    else
                        dp[t] += dp[t - num];
                }
            }
        }
        return (int)dp[target];
    }
};