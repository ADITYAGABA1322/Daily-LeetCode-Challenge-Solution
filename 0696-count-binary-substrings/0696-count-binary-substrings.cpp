class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size() , prevCnt = 0 , currCnt = 1 , res = 0;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) currCnt++;
            else{
                res += min(prevCnt , currCnt);
                prevCnt = currCnt;
                currCnt = 1;
            }
        }
        return res + min(prevCnt , currCnt);
    }
};