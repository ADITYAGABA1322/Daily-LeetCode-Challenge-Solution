class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;
        vector<int>lMax(n) , rMax(n);
        for(int i=1; i<n; i++){
            lMax[i] = max(lMax[i-1] , nums[i-1]);
            rMax[n-i-1] = max(rMax[n-i] , nums[n-i]);
        }
        for(int j=1; j<n; j++){
            maxi = max(maxi , (long long) (lMax[j] - nums[j]) * rMax[j]);
        }
        return maxi;
    }
};