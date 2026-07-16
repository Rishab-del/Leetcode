class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        
        unordered_set<int> st(nums.begin(), nums.end());

        for(int num : st){
            if(st.find(num - 1) == st.end()) { //run when number not in set
                int curr = num;
                int cnt = 1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};