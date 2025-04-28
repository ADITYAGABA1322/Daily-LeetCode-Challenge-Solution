class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        if(n<10) return 0;
        string s = to_string(n);
        int len = s.size();
        vector<vector<vector<vector<int>>>>memo(len , vector<vector<vector<int>>>(2 , vector<vector<int>>(1 << 10 , vector<int>(2 , -1))));
        function<int (int , bool , int , bool)> dp = [&](int pos , bool tight , int mask , bool started) -> int {
            if(pos == len) return started ? 1 : 0;
            if(memo[pos][tight][mask][started] != -1) return memo[pos][tight][mask][started];
            int count = 0;
            if(!started) count+= dp(pos+1 , false , mask , false);
            int limit = tight ? (s[pos] - '0') : 9;
            int start = started ? 0 : 1;
            for(int digit = start; digit<=limit; digit++){
                if((mask & (1<<digit)) > 0) continue;
                int newMask = mask | (1<<digit);
                bool nextTight = tight && (digit == limit);
                count += dp(pos+1 , nextTight , newMask , true);
            }
            return memo[pos][tight][mask][started] = count;
        };
        int numbersWithoutRep = dp(0 , true , 0 , false);
        return  n - numbersWithoutRep;
    }
};