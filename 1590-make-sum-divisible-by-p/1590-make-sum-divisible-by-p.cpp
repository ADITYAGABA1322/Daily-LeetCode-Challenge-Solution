class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;
        for(auto num : nums) totalSum = (totalSum + num) % p;
        if(totalSum == 0) return 0;
        unordered_map<int , int > mp;
        mp[0] = -1;
        int prefixSum = 0 , minLen = n;
        for(int i=0; i<n; i++){
            // now what we do find that 2 consition when full sum of array divisble by p its 0 and it s imposble reutn -1
            // now what o do i store the preic sum according to that so its divsible by ok and we need remobe the samlles subaarray len its just simple to rmeove the lement and lenth of sub mean the we put el in res and return the len ok 
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - totalSum + p) % p;
            if(mp.find(target) != mp.end()){
                minLen = min(minLen , i  - mp[target]);
            }
            mp[prefixSum] = i;
        }
        return minLen == n ? -1 : minLen;
    }
};