class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans ="";
        unordered_map<string, string> mp;
        // knowledge ko hashmap mein convert karo
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                string word="";
                i++;
                while(s[i]!=')'){
                    word+=s[i];
                    i++;
                }
                if(mp.find(word)!=mp.end()){
                    ans+=mp[word];
                }
                else {
                    ans+='?';
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};