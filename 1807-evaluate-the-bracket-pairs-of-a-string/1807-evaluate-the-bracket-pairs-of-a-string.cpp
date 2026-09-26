class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string res = "";
        unordered_map<string , string> mp;
        for(auto k : knowledge) mp[k[0]] = k[1];
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                string curr;
                for(int j=i+1; j<n; j++){
                    if(s[j] != ')') curr += s[j];
                    else {
                        mp.find(curr) != mp.end() ? res.append(mp[curr]) : res.append("?");
                        i = j;
                        break;
                    }
                }
            } else {
                res += s[i];
            }
        } 
        return res;
    }
};