class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        for(char ch : s) {
            if(ch == '(') {
                if(!st.empty()) {
                    ans += ch;
                }
                st.push(ch);
            }
            else {
                if(st.size() > 1) {
                    ans += ch;
                }
                st.pop();
            }
        }

        return ans;
    }
};