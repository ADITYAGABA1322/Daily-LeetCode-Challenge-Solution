class Solution {
public:
    string makeFancyString(string s) {
        int freq = 1;
        char prev = s[0];
        string ans = "";
        ans.push_back(s[0]);
        for(int i=1; i<s.size(); i++){
            if(s[i] == prev) freq++;
            else{
                prev = s[i];
                freq = 1;
            }
            if(freq < 3) ans.push_back(s[i]);
        }
        return ans;
    }
};