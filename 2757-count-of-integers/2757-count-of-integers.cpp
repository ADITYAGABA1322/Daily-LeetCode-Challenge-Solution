class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        const int MOD = 1e9+7;
        auto countUpTo = [&](const string& upper , int min_sum , int max_sum) -> int {
            int n = upper.length();
            vector<vector<vector<int>>> memo(n+1 , vector<vector<int>>(2 , vector<int>(401 , -1)));
            function<int (int , bool , int)>dp = [&](int pos , bool tight , int sum) -> int {
                if(pos == n) return (sum >= min_sum && sum<=max_sum) ? 1 : 0;
                if(memo[pos][tight][sum] != -1) return memo[pos][tight][sum];
                int res = 0;
                int limit = tight ? (upper[pos] - '0') : 9;
                for(int digit =0; digit<=limit; digit++){
                    if(sum+digit > max_sum) continue;
                    bool nextTight = tight && (digit == upper[pos] - '0');
                    res = (res + dp(pos+1 , nextTight , sum + digit)) % MOD;
                } 
                return memo[pos][tight][sum] = res;
            };
            return dp(0 , true , 0);
       };
       int low_sum = 0;
       for(auto c : num1) low_sum += c -'0';
       bool includenum1 = (low_sum >= min_sum && low_sum <= max_sum) ? true : false;
       string num1Minus1 = decrementString(num1);
       int res = (countUpTo(num2 , min_sum , max_sum) - countUpTo(num1Minus1 , min_sum , max_sum)) % MOD;
       if(res < 0) res += MOD;
       return res;
    }
    private:
    string decrementString(string &num){
        string res = num;
        int i = res.length()-1;
        while(i>=0 && res[i] == '0'){
            res[i] = '9';
            i--;
        }
        if(i >= 0){
            res[i]--;
        }
        else{
            return "0";
        }
        if(res[0] == '0' && res.length() > 1) return res.substr(1);
        return res;
    }
};