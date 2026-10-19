class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr){
        vector<int> ans;
        if (arr.empty()) return ans;
        int m = arr.size(),n = arr[0].size(), minr = 0,minc = 0,maxr = m - 1,maxc = n - 1;
        while (minr <= maxr && minc <= maxc) {
            // left to right
            for (int i = minc; i <= maxc; i++) ans.push_back(arr[minr][i]);
            minr++;
            // top to bottom
            for (int i = minr; i <= maxr; i++)ans.push_back(arr[i][maxc]);
            maxc--;
            // right to left
            if (minr <= maxr) {
                for (int i = maxc; i >= minc; i--) ans.push_back(arr[maxr][i]);
                maxr--;
            }
            // bottom to top
            if (minc <= maxc) {
                for (int i = maxr; i >= minr; i--)ans.push_back(arr[i][minc]);
                minc++;
            }
        }
        return ans;
    }
};