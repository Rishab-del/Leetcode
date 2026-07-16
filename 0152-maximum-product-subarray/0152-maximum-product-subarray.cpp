class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx=1;
        int minn=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(maxx==0)  maxx=1;
            if(minn==0) minn=1;
            maxx=maxx*nums[i];
            minn=minn*nums[nums.size()-i-1];
            ans=max(ans,max(maxx,minn));
        }
        return ans;
    }
};