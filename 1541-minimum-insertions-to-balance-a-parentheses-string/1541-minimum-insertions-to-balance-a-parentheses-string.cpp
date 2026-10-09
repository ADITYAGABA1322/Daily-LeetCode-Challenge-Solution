class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0 , ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            else{
                // first we need  ))
                if(i+1 < n && s[i+1] == ')') i++;
                else ans++;

                if(open > 0) open--;
                else ans++;
            }
        }
        return ans + 2*open;
    }
};