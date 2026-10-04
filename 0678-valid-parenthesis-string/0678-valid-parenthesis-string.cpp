class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;
                high++;
            }
            // Even maximum possible '(' is negative
            if (high < 0)
                return false;
            // Minimum cannot be negative
            low = max(low, 0);
        }
        return low == 0;
    }
};