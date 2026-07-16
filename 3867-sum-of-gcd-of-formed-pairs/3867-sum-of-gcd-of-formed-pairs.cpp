class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx;
        int prefixMax = INT_MIN;
        for(auto n: nums){
            prefixMax = max(prefixMax , n);
            mx.push_back(prefixMax);
        }
        vector<int> preGcd;
        for(int i=0; i<n; i++){
            preGcd.push_back(gcd(nums[i] , mx[i]));
        }

        ranges::sort(preGcd);

        long long ans = 0;
        int left = 0 , right = n-1;
        while(left < right){
            ans += gcd(preGcd[left] , preGcd[right]);
            left++; right--;
        }
        return ans;
    }
};