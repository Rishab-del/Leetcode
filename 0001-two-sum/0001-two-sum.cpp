class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (um.find(remain)!= um.end()) {
                return {um[remain], i};
            }
            um[nums[i]] = i;
        }
        return {};
    }
};