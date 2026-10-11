class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0;
        int n =nums.size();
        for (int j = 0; j < n; j++) {
            int i = j + 1;
            if (n % i == 0) {
                sum += nums[j] * nums[j];
            }
        }
    return sum;
    }
};