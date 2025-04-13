#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    ll power(long long x , long long y){
        long long res = 1;
        x  = x%mod;
        if(x == 0) return 0;
        while(y>0){
            if(y&1) res = (res*x) % mod;
            y = y>>1;
            x = (x*x)%mod;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll count_of_4s = n/2;
        ll count_of_5s = n - count_of_4s;
        ll ans = ((power(4LL , count_of_4s) % mod * power(5LL , count_of_5s)%mod)%mod);
        return (int)ans;
    }
};