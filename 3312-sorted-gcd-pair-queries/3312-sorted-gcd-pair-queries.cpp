class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int MAXVAL = 50001;
        vector<long long> freq(MAXVAL, 0);
        for(auto x : nums) freq[x]++;
        vector<long long> f(MAXVAL , 0);
        for(int g = MAXVAL-1; g>=1; g--){
            long long cnt = 0;
            for(int mul = g; mul<MAXVAL; mul+=g)  cnt += freq[mul];
            f[g] = cnt * (cnt-1) / 2;
            for(int mul = 2*g; mul<MAXVAL; mul+=g) f[g] -= f[mul];    
        }
        vector<long long> preSum(MAXVAL , 0);
        preSum[1] = f[1];
        for(int g=2; g<MAXVAL; g++){
            preSum[g] = preSum[g-1] + f[g];
        }
        vector<int> res;
        for(auto q: queries){
            int lo = 1 , hi = MAXVAL-1 , ans = -1;
            while(lo <= hi){
                int mid = lo + (hi - lo) / 2;
                if(preSum[mid] > q){
                    ans = mid;
                    hi = mid -1;
                } else lo = mid +1;
            }
            res.push_back(ans);
        }
        return res;
    }
};