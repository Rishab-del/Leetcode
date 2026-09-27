class Solution {
public:
    string rever(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;

            i++;
            j--;
        }

        return s;
    }

    string solve(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {

                int start = i + 1;
                int j = start;
                int count = 1;

                // corresponding ')' find karo
                while(count != 0) {
                    if(s[j] == '(')
                        count++;
                    else if(s[j] == ')')
                        count--;

                    j++;
                }

                // parentheses ke andar ka part
                string word = s.substr(start, j - start - 1);

                // andar ke parentheses pehle solve karo
                word = solve(word);

                // ab current parentheses reverse karo
                ans += rever(word);

                // j ab ')' ke baad hai
                i = j - 1;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }

    string reverseParentheses(string s) {
        return solve(s);
    }
};