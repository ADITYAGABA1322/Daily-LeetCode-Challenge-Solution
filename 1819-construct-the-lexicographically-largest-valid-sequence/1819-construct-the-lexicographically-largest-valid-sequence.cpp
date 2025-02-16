class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        // given  n int ok  int 1 occurs once in the seq and each int between 2 and n occ twice in the seq ok  we need to fine the lexicographically largest sequence ok. a seq a is lexo lrger than b we  have n int we nend to use backtrackl to go and find largest lexo seq ok. we go with helper funtion and base contion ok and acc to n. we iterate or use backtrack and use the condition ok The integer 1 occurs once in the sequence.
// Each integer between 2 and n occurs twice in the sequence.
// For every integer i between 2 and n, the distance between the two occurrences of i is exactly i approach  seclarre helper vector<int> res and check the in helper n and arr ok. 
        vector<int> res(2*n-1 , 0);
        vector<bool> used(n+1 , false);

        function<bool(int)> backtrack = [&](int pos){
            if(pos == res.size()) return true;
            if(res[pos] != 0) return backtrack(pos+1);
            for(int i=n; i>=1; i--){
                if(used[i]) continue;
                if(i == 1){
                    res[pos] = 1;
                    used[1] = true;
                    if(backtrack(pos +1)) return true;
                    res[pos] = 0;
                    used[1] = false;
                }
                else{
                    if(pos + i < res.size() && res[pos] == 0 && res[pos+ i] == 0){      
                        res[pos] = res[pos+i] = i;
                        used[i] = true;
                        if(backtrack(pos + 1)) return true;
                        res[pos] = res[pos+i] = 0;
                        used[i] = false;
                    }
                }
            }
            return false;
        };
        backtrack(0);
        return res;
    }
};