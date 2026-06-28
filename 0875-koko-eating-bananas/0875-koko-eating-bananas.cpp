class Solution {
public:
    bool helper(vector<int>& piles, int h,int mid){
        int count=0;
        for(int i=0;i<piles.size();i++){
            if (piles[i] % mid == 0) count+=(piles[i]/mid);
            else count+=(piles[i]/mid)+1;
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(maxi<piles[i]) maxi=piles[i];
        }
        if (h==piles.size()) return maxi;
        int low=1;
        int high=maxi;
        int ans=maxi;
        while(low<high){
            int mid=low+(high-low)/2;
            if (helper(piles,h,mid)){
                ans=mid;
                high=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};