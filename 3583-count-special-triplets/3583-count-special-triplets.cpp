class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int mod = 1e9+7;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(nums[i] == nums[j]*2 && nums[k] == nums[j]*2) cnt++;
        //         }
        //     }
        // }
        // return cnt % mod;
        unordered_map<int , int> r , l;
        for(auto num : nums) r[num]++;
        for(int i=0; i<n; i++){
            int mid = nums[i];
            r[mid]--;
            int left = l[2*mid] , right = r[2*mid];
            res = (res + 1LL * left * right) % mod;
            l[mid]++;
        }
        return res;
    }
};