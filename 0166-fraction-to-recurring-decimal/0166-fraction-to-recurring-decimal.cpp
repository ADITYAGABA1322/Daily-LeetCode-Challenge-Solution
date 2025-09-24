class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string res;
        if((numerator < 0) ^ (denominator < 0)) res+='-';
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);
        res +=  to_string(num / den);
        long long  rem = (num % den);
        if(rem == 0) return res;
        res += '.';
        unordered_map<long long , int> remIdx;
        while(rem != 0){
            if(remIdx.count(rem)){
                res.insert(remIdx[rem]  , "(");
                res += ")";
                break;
            }
            remIdx[rem] = res.size();
            rem *= 10;
            res += to_string(rem /den);
            rem %= den;
        }
        return res;
    }
};