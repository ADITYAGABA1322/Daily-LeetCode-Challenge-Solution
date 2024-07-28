class Solution {
public:
    vector<int> generate(int limit){
        vector<bool> isPrime(limit+1 , true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<=limit; i++){
            if(isPrime[i]){
                for(int j= i*i; j<=limit; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> prime;
        for(int i=2; i<=limit; i++) {
        if(isPrime[i]) prime.push_back(i);
        }
        return prime;
    }
    int nonSpecialCount(int l, int r) {
        int total = r-l+1 , limit = sqrt(r) , specialCnt = 0;
        vector<int> primes = generate(limit);
        for(auto prime : primes){
            int special = prime*prime;
            if(special >= l && special <= r) specialCnt++;
        }
        return total - specialCnt;
    }
};