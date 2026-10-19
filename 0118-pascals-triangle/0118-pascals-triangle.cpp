class Solution {
public:
    vector<vector<int>> generate(int n) {
       vector<vector<int>> pascal; // Create a 2D vector to hold the rows of Pascal's Triangle
    for(int i = 1; i <= n; i++) {
        vector<int> row(i); // Initialize each row with 1s
        pascal.push_back(row);
    }
    //generate Pascal's Triangle
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j==0 || j==i){// First and last elements of each row are always 1
                pascal[i][j] = 1;
            }
            else{
             pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }
    return pascal;
    }
    
};