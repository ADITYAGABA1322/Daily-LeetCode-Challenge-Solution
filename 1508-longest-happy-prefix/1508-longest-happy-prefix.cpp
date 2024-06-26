class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int p = 0;
        vector<int> lps(n , 0);
        for(int i = 1; i < n; i++) {
            while(p > 0 && s[i] != s[p])
                p = lps[p - 1];
            if(s[i] == s[p])
                p++;
            lps[i] = p;
        }
        return s.substr(0, p);
    }
};