class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxEle = *max_element(nums.begin() , nums.end());
        vector<int> sieve(maxEle + 1 , 1);
        sieve[1] = 0;
        for(int i=2; i<=sqrt(maxEle +1); i++){
            if(sieve[i]  == 1){
                for(int j=i*i ; j<=maxEle; j+=i) sieve[j] = 0;
            }
        }
        int currVal = 1 , i = 0;
        while(i<nums.size()){
            int diff = nums[i] - currVal;
            if(diff < 0) return 0;

            if(sieve[diff] == 1 or diff == 0){
                i++;
                currVal++;
            }
            else{
                currVal++;
            }
        }
        return 1;
    }
};