class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // WE NEED TO RETURN SMALLEST GAP PRIME NO IN THE LEFT AND RIGHT FIRST WE KNOW WAHT IS PRIME NO WE USE SIEVE OF ETHASNOSIS OK AND NOTHER WE TAKE FIRST 2 PRIME NO AND RETURN IT IF THE LIST CONTIN ONLY ONE OR ZERO RETURN IN PAIR -1 , -1 OK. THAT SOLVE 
        vector<bool> isPrime(right+1 , true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<=right; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=right;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for(int i=max(2 , left); i<=right; i++){
            if(isPrime[i]) primes.push_back(i);
        }
        if(primes.size() < 2) return {-1 , -1};

        int min_gap = INT_MAX;
        vector<int> res = {-1 , -1};
        for(int i =1; i<primes.size() ; i++){
            int gap = primes[i] - primes[i-1];
            if(gap < min_gap){
                min_gap = gap;
                res[0] = primes[i-1];
                res[1] = primes[i];
            }
        }
        return res;
    }
};