class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;
        for(auto num : nums){
            totalSum = (totalSum + num) % p;
        }
        if(totalSum == 0) return 0;
        unordered_map<int , int> mp;
        mp[0] = -1;
        int prefixSum = 0 , minLen = n;
        for(int i=0; i<n; i++){
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - totalSum + p) % p;
            if(mp.find(target) != mp.end()){
                minLen = min(minLen , i - mp[target]);
            }
            cout<<target<<endl;
            mp[prefixSum] = i;
        }
        return minLen == n ? -1 : minLen;
    }
};