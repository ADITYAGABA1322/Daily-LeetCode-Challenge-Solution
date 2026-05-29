class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto num : nums){
            int rem = 0;
            while(num > 0){
                rem += num % 10;
                num /= 10;
            }
            ans = min(ans , rem);
        }
       return ans;
    }
};