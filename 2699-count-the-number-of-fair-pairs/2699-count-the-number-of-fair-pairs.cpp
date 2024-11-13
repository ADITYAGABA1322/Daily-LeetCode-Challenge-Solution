class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        long long res = 0;
        int low = n-1 , high = n-1;
        for(int i=0; i<nums.size(); i++){
            while(high >=0 && nums[i] + nums[high] > upper) high--;
            while(low>=0 && nums[i] + nums[low] >= lower) low--;
            res += high - low;
            if(low <i && i<=high) res--;
        }
        return res/2;
    }
};