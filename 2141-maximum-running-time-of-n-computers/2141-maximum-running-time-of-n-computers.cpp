class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sumPower = 0;
        for(auto b: batteries) sumPower += b;
        long long left = -1 , right = sumPower/n;
        while(left < right){
            long long mid = right - (right - left) / 2;
            long long extra = 0;
            for(auto b : batteries)
                extra += min((long long)b , mid);
            
            if (extra >= (long long)n*mid) left = mid;
            else right = mid -1;
        }
        return left;
    }
};