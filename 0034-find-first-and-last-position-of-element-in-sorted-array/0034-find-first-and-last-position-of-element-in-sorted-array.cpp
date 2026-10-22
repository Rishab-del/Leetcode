class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int k) {
        vector<int> ans(2,-1);
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==k){
                ans[0]=mid;
                high=mid-1;
            }
            else if(arr[mid]>k) high=mid-1;
            else low=mid+1;
        }
        low=0;
        high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==k){
                ans[1]=mid;
                low=mid+1;
            }
            else if(arr[mid]>k) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};