class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        if (amount == 0)
            return 1;

        if (n == 0)
            return 0;

        vector<vector<long long>> dp(
            n, vector<long long>(amount + 1, 0)
        );

        // Base case
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {

                long long notTake = dp[ind - 1][target];

                long long take = 0;

                if (coins[ind] <= target) {
                    take = dp[ind][target - coins[ind]];
                }

                // Prevent long long overflow
                if (take > LLONG_MAX - notTake)
                    dp[ind][target] = LLONG_MAX;
                else
                    dp[ind][target] = take + notTake;
            }
        }

        return (int)dp[n - 1][amount];
    }
};