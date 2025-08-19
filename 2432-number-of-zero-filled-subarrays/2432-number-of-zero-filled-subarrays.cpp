class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0 , subArr = 0;
        for(auto num : nums){
            if(num == 0) subArr++;
            else{
                subArr = 0;
            }
            ans += subArr;
        }
        return ans;
    }
};