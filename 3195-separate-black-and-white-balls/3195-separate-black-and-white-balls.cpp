class Solution {
public:
    long long minimumSteps(string s) {
        // long long count = 0;
        // for(auto c : s){
        //     if(c == '1') count++;
        // }
        int onesofar = 0;
        long long swap = 0;
        for(auto c : s){
            if(c == '1') onesofar++;
            else swap += onesofar;
        }
        return swap;
    }
};