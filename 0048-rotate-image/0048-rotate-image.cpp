class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){     // Start from j=i+1 to avoid swapping back
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int i=0;i<n;i++){
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        swap(arr[i][left], arr[i][right]);
        left++;
        right--;
    }
    }

        
    }
};