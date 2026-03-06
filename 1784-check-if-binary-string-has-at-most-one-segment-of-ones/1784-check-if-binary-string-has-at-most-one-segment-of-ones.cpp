class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool zeroFound = false;
        for(int i=0; i<n; i++){
            if(s[i] == '0') zeroFound = true;
            if(s[i] == '1' && zeroFound) return false;
        }
        return true;
    }
};