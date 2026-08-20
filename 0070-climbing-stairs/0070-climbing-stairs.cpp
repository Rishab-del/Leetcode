class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int j = 1;
        int k  = 2;

        for (int i = 3; i <= n; i++) {
           int curr=k+j;
           k=j;
           j=curr;
        }

        return k;
    }
};