class Solution {
public:
    int  helper (int i ,int j , string s1, string s2, vector<vector<int>>& dp){
        if(i<0) return j+1; //insert all the remaining characters of s2
        if(j<0) return i+1; //remove all the remaining characters of s1
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = helper(i-1,j-1,s1,s2 ,dp);
        else {
            int replace = 1+ helper(i-1,j-1,s1,s2 ,dp); //replace 
            int remove = 1+ helper(i-1,j,s1,s2 ,dp); //remove
            int insert = 1+ helper(i,j-1,s1,s2 ,dp); //insert
            dp[i][j] = min({replace, remove, insert});
            return dp[i][j];
        }
    }
    
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1,m-1,s1,s2 , dp);
    }
};