// class Solution {
// public:
//     long long numberOfPowerfulInt(long long start, long long finish, int limit,
//                                   string s) {
//         // count no of powerfiul integers
//         // start. finish , limit , 0 indexed string s
//         // x +ve int ok is called powerful if it end s (s is a suffix of x) and
//         // each digit in x at most limit return total powerful int in rnage
//         // [start..finish] intution what we want to do first check finish is of
//         // 10 th place or 1000 or more than ok. acc to that we given limit also
//         // and string s  is suffix part to check lets assume  in first example
//         // we give  s = 1 and finish = 6000 and acc to finish its 3 digit place
//         // no  and we given s = 124 acc to that we want to find that no which
//         // this part s lets take this as starting no 124 and u know another
//         // after comes 3 digit place beacause our finsih is at 3 digit place so
//         // 124+1000 = 1124 , agian 1000 place 2124 , 3124 , 4124 and 5124 is
//         // these are lesss than finish n means for loop done here ok but we want
//         // to now check the limit form above we check each digit is less than or
//         // equal to limit , limit is 4 so 5124 is not in the lsit so reamnig
//         // them are  ans or res
//         // appraoch this genuine shows we want to use recursion from evrytime we
//         // run the funciton and check the no we get contain s as suffix or as a
//         // no start with s and finish at 6000 and we know the game in funciton
//         // we want to check the finsih is 3 digit please or at which digit so
//         // acc to that we easily find those no  after first no we get ok. so how
//         // to buidl the brute force or recusive way to get this we want to
//         // intialize the helper the fuction which take s finish and limit and s
//         // as want to cehck suffix and one more ele which is is no of take  10th
//         // pleace or 100th place acc to that we start calling in
//         // brute force
//     //     long long suffixNum = 0;
//     //     for (auto c : s) {
//     //         suffixNum = suffixNum * 10 + (c - '0');
//     //     }
//     //     int suffixLen = s.size();
//     //     long long minNum = suffixNum;
//     //     long long maxNum = finish;
//     //     long long cnt = 0;
//     //     for(long long i=minNum; i<=maxNum; i++){
//     //         if(hasSuffix(i ,  suffixNum , suffixLen)){
//     //             if(allDigitsWithinLimit(i , limit)){
//     //                 if(i >= start && i<= finish) cnt++;
//     //             }
//     //         }
//     //     }
//     //     return cnt;
//     // }
//     // private:
//     //     bool hasSuffix(long long num , long long suffix , int suffixLen){
//     //         long long mod = 1;
//     //        for(int i=0; i<suffixLen; i++) mod*=10;
//     //         return num%mod == suffix;
//     //     }
//     //     bool allDigitsWithinLimit(long long num , int limit){
//     //         while(num > 0){
//     //             int digit = num%10;
//     //             if(digit > limit) return false;
//     //             num /= 10;
//     //         }
//     //         return true;
//     //     }
//     // efficient brute force
//         // Convert suffix to a number
//         long long suffixNum = stoll(s);
//         int suffixLen = s.length();
        
//         // Calculate the power of 10 for the suffix position
//         long long suffixPos = 1;
//         for (int i = 0; i < suffixLen; i++) {
//             suffixPos *= 10;
//         }
        
//         long long count = 0;
        
//         // Find the first number ending with s that is >= start
//         long long firstNum = start / suffixPos * suffixPos + suffixNum;
//         if (firstNum < start) {
//             firstNum += suffixPos;
//         }
        
//         // Generate all numbers ending with s up to finish
//         for (long long num = firstNum; num <= finish; num += suffixPos) {
//             // Check if all digits are at most limit
//             if (allDigitsWithinLimit(num, limit)) {
//                 count++;
//             }
//         }
        
//         return count;
//     }
    
// private:
//     // Check if all digits in num are at most limit
//     bool allDigitsWithinLimit(long long num, int limit) {
//         while (num > 0) {
//             int digit = num % 10;
//             if (digit > limit) {
//                 return false;
//             }
//             num /= 10;
//         }
//         return true;
//     }

// };

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string low = to_string(start);
        string high = to_string(finish);
        int n = high.size();
        low = string(n - low.size(), '0') + low;  // align digits
        int pre_len = n - s.size();               // prefix length

        vector<long long> memo(n, -1);
        function<long long(int, bool, bool)> dfs =
            [&](int i, bool limit_low, bool limit_high) -> long long {
            // recursive boundary
            if (i == low.size()) {
                return 1;
            }

            if (!limit_low && !limit_high && memo[i] != -1) {
                return memo[i];
            }

            int lo = limit_low ? low[i] - '0' : 0;
            int hi = limit_high ? high[i] - '0' : 9;

            long long res = 0;
            if (i < pre_len) {
                for (int digit = lo; digit <= min(hi, limit); digit++) {
                    res += dfs(i + 1, limit_low && digit == lo,
                               limit_high && digit == hi);
                }
            } else {
                int x = s[i - pre_len] - '0';
                if (lo <= x && x <= min(hi, limit)) {
                    res =
                        dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
                }
            }

            if (!limit_low && !limit_high) {
                memo[i] = res;
            }
            return res;
        };
        return dfs(0, true, true);
    }
};