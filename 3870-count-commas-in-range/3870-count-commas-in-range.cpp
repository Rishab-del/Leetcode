class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        ans += max(n - 999, 0);
        ans += max(n - 999999, 0);
        ans += max(n - 999999999, 0);

        return ans;
    }
};