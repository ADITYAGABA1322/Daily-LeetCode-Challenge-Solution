class Solution {
public:
    int punishmentNumber(int n) {
        // we need to find punishment no ok go it and for punishment no we nend to perfrom op and then return the sum of sq of these punish no ok and now perform op to find these things  sum of the squares of all integers i , 1 <= i <= n , f i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i. lets build approach what we used here this is a basic math or number problem we need to check sq of those no for find punish we create a function which wokrs like bactrack how it go noe by one one and check this contions wrks store the number sq in sum and before doing this how it perform op first base contion and then start from a first take sq and check first condn 1 <= i <= n and then perform 2nd by takin sum of those sq ok and su of these no like using % and /= 10 ok after we get sum  ok 
        int res = 0;
        auto canPartition = [](string& s , int target){
            int len = s.size();
            function<bool(int , int)> backTrack = [&](int start , int currSum){
                if(start == len) return currSum == target;
                for(int i=start; i<len; i++){
                    string part = s.substr(start , i - start + 1);
                    int  num = stoi(part);
                    if(backTrack(i+1 , currSum + num)) return true;
                }
                return false;
            };
            return backTrack(0 , 0);
        };

        for(int i=1; i<=n ;i++){
            int sq = i*i;
            string sqS = to_string(sq);
            if(canPartition(sqS , i)) res += sq;
        }
        return res;
    }
};