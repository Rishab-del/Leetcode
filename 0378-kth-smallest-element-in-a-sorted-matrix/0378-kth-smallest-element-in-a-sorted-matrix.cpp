class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int r = 0; r < n; r++) {
            pq.push({matrix[r][0], r, 0});
            }

        while(--k) {
            auto curr = pq.top();
            pq.pop();
            int val = curr[0];
            int row = curr[1];
            int col = curr[2];

            if(col + 1 < n) {
                pq.push({matrix[row][col + 1], row, col + 1});
            }
        }
        return pq.top()[0];
    }
};