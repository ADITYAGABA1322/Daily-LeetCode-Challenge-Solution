class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++){
            unordered_map<char , int> mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                if(mp[s[j]] > 2) break;
                res = max(res , j-i+1);
            }
        }
        return res;
    }
};