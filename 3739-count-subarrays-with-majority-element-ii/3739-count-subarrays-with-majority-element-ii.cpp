class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        int cumSum = 0;
        mp[0] = 1;
        long long res = 0 , validLeftPoints = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                validLeftPoints += mp[cumSum];
                cumSum += 1;
            } else {
                cumSum -= 1;
                validLeftPoints -= mp[cumSum];
            }
            mp[cumSum] += 1;
            res += validLeftPoints;
        }
        return res;
    }
};