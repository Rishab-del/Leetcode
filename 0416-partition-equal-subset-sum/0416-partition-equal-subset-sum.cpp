class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) {
            total += x;
        }
        // Odd total cannot be divided equally
        if (total % 2 != 0)
            return false;

        int target = total / 2;

        // dp[s] = can we make sum s?
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int x : nums) {
            // Go backwards so each element is used only once
            for (int s = target; s >= x; s--) {
                dp[s] = dp[s] || dp[s - x];
            }
        }
        return dp[target];
    }
};