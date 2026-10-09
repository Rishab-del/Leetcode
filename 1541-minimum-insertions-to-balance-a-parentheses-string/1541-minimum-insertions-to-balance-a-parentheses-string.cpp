class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                // Need an opening '('
                if (open == 0) {
                    ans++;
                    open++;
                }
                // This ')' is first closing bracket
                open--;
                // Need another ')' immediately
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;  // consume second ')'
                }
                else {
                    ans++; // insert missing ')'
                }
            }
        }
        // Every remaining '(' needs two ')'
        ans += 2 * open;
        return ans;
    }
};