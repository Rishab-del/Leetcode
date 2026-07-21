class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n; j > 0; j--) {
                int paint = dp[max(j - time[i] - 1 , 0)];
                if (paint != INT_MAX) paint += cost[i];
                dp[j] = min(paint, dp[j]);
            }
        }

        return dp[n];
    }
};