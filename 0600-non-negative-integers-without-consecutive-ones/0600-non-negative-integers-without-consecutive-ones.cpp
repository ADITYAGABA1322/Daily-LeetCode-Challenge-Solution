class Solution {
public:
    string decimalToBinary(int n){
        if(n == 0) return "0";
        string binary = "";
        while(n>0){
            binary = to_string(n%2) + binary;
            n /= 2;
        }
        return binary;
    }
    int findIntegers(int n) {
        if(n == 0) return 1;
        string binary = decimalToBinary(n);
        int len = binary.length();
        vector<vector<vector<int>>> memo(len , vector<vector<int>>(2 , vector<int>(2 , -1)));
        function<int (int , bool , bool)> dp = [&](int pos , bool tight , bool prev) -> int{
            if(pos == len) return 1;
            if(memo[pos][tight][prev] != -1) return memo[pos][tight][prev];
            int cnt = 0;
            int limit = tight ? binary[pos]-'0' : 1;
            for(int digit = 0; digit<=limit; digit++){
                if(prev && digit == 1) continue;
                bool nextTight = tight && (digit == binary[pos]-'0');
                cnt += dp(pos + 1 , nextTight , digit == 1);
            }
            return memo[pos][tight][prev] = cnt;
        };
       return  dp(0 , true , false);
    }
};