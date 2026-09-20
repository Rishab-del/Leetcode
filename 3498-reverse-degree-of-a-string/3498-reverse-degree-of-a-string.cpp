class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            int position = i + 1;
            int reversePosition = 'z' - s[i] + 1;
            ans += position * reversePosition;
        }

        return ans;
    }
};