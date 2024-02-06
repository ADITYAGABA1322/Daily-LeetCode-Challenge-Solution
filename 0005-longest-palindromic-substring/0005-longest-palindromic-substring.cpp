class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(s.empty()) return "";
        int start = 0 , len = 0;
        for(int i=0; i<n; i++){
            int l  = i , r = i;
            while(r <n-1 && s[r] == s[r+1]) r++;
            i = r;
            while(l>0 && r<n-1 && s[l-1] == s[r+1]){
                l--;
                r++;
            }
            if(r-l+1 > len){
                len = r-l+1;
                start = l;
            }
        }
        return s.substr(start , len);
    }
};

