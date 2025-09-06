class Solution {
public:
    long long getCnt(long long n){
        long long cnt = 1 + ((n == 0) ? 0 : log2(n)/2);
        long long sum = ((cnt <= 0) ? 0 : (pow(4 , cnt) - 1) / 3);
        return cnt * (n+1) - sum;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto q : queries) ans += (getCnt(q[1]) - getCnt(q[0] -1 ) + 1)/2;
        return ans;
    }
};