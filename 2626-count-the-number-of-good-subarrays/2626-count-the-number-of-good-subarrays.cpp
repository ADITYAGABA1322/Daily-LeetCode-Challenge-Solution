class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0 , pairs = 0;
        unordered_map<int , int> mp;
        int n = nums.size() , left = 0;
        for(int right=0; right <n; right++){
            pairs += mp[nums[right]];
            mp[nums[right]]++;
            while(pairs >= k && left < right){
                res += n-right;
                mp[nums[left]]--;
                pairs -= mp[nums[left]];
                left++;
            }

        }
        return res;
    }
};