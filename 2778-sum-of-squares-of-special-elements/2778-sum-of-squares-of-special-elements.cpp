class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0;
        for (int j = 0; j < nums.size(); j++) {
            int i = j + 1;
            if (nums.size() % i == 0) {
                sum += nums[j] * nums[j];
            }
        }
    return sum;
    }
};