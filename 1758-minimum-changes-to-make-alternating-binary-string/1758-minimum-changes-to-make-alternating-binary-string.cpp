class Solution {
public:
    int minOperations(string s) {
        int n = s.size() , cnt = 0;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                if(s[i] == '1') cnt++;
            } else{
                if(s[i] =='0') cnt++;
            }
        }
    return min(cnt , (int)s.size() - cnt);
    }
};