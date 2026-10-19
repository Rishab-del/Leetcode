class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            // Duplicate i skip karo
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                // Duplicate j skip karo
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                long long rem = (long long)target - nums[i] - nums[j];
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = (long long)nums[k] + nums[l];
                    if (sum == rem) {
                        ans.push_back({
                            nums[i], nums[j], nums[k], nums[l]
                        });
                        k++;
                        l--;
                        // Duplicate k skip karo
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        // Duplicate l skip karo
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < rem) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};