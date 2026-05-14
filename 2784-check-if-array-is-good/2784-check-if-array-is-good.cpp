class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto num : nums)  mp[num]++;
        int maxEle = *max_element(nums.begin() , nums.end());
        if(maxEle != n-1) return false;
        for(int i=1; i<maxEle; i++){
            if(mp[i] != 1) return false;
        }
        if(mp[maxEle] != 2) return false;
        return true;
    }
};