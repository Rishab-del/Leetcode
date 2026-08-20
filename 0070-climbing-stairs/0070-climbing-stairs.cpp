class Solution {
public:
    int climbStairs(int n) {
        int j = 1;
        int k  = 2;

        for (int i = 3; i <= n; i++) {
           int curr=k+j;
           k=j;
           j=curr;
        }

        return n == 1 ? 1 : j + (n == 2 ? 1 : 0);
    }
};