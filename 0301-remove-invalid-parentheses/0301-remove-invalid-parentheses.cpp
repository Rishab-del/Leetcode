class Solution {
public:

    bool valid(string &s) {
        int cnt = 0;

        for(char c : s) {
            if(c == '(')
                cnt++;
            else if(c == ')') {
                cnt--;

                if(cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }

    void solve(string &s, int i, int mini,
               string &curr, vector<string> &ans) {

        // End of string
        if(i == s.size()) {

            if(mini == 0 && valid(curr)) {
                ans.push_back(curr);
            }

            return;
        }

        // Remove current parenthesis
        if((s[i] == '(' || s[i] == ')') && mini > 0) {
            solve(s, i + 1, mini - 1, curr, ans);
        }

        // Keep current character
        curr.push_back(s[i]);

        solve(s, i + 1, mini, curr, ans);

        curr.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {

        // Find minimum removals
        stack<char> st;

        for(char c : s) {

            if(c == '(') {
                st.push(c);
            }
            else if(c == ')') {

                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(c);
            }
        }

        int mini = st.size();

        vector<string> ans;
        string curr = "";

        solve(s, 0, mini, curr, ans);

        // Remove duplicate answers
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};