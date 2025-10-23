class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        for(int i=1; i<=n-2; i++){
            for(int j=0; j<=n-1; j++){
                s[j] = ((s[j] - '0') + (s[j+1] - '0')) % 10 + '0';
            }
        }
        return s[0] == s[1];
    }
};