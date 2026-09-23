class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int c : nums) total+=c;
        int target = total-x;

        if(target<0 ) return -1;
        if(target==x) return nums.size();

        int i=0;
        int summ=0;
        int maxx=-1;

        for(int j=0;j<nums.size();j++){
            summ+=nums[j];

            while(summ>target) {
                summ-=nums[i];
                i++;
            }

            if(summ==target){
                maxx=max(maxx,j-i+1);
            }
        
        }
        if(maxx==-1) return -1;
        return nums.size()-maxx;
    }
};