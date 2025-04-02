class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             maxi = max(maxi , (long long)(nums[i] - nums[j]) * nums[k]); 
        //         }
        //     }
        // }
        // for(int k=2; k<n; k++){
        //     int maxPre = nums[0];
        //     for(int j=1; j<k; j++){
        //         maxi = max(maxi , (long long)(maxPre - nums[j]) * nums[k]);
        //         maxPre = max(maxPre , nums[j]);
        //     }
        // }
        vector<int> lMax(n),  rMax(n);
        for(int i=1; i<n; i++){
            lMax[i] = max(lMax[i-1] , nums[i-1]);
            rMax[n-1-i] = max(rMax[n-i], nums[n-i]);
        }
        for(int j=1; j<n; j++){
             maxi = max(maxi , (long long)(lMax[j] - nums[j]) * rMax[j]);
        }
        return maxi;
    }
};