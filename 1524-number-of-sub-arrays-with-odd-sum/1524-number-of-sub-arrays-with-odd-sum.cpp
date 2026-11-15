class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // we for sum w use prefix sum ok only one thing that mf works so what we do now we want to create prefix sum using odd and even concept ok
        const int MOD = 1e9+7;
        int odd = 0 ,even = 1;
        int pre = 0, res = 0;
        for(auto i : arr){ 
            pre +=i;
            if(pre % 2 == 0){
                res = (res + odd) % MOD;
                even++;
            }
            else{
                res = (res + even) % MOD;
                odd++;
            }
        }
        return res;
    }
};