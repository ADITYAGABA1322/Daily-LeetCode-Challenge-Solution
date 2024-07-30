class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp(nums.begin() , nums.end());
        int curr = 0 , currLen = 0 , maxLen = 0;
        for(auto num : nums){
            if(mp.find(num-1) == mp.end()){
                curr = num;
                currLen = 1;
                while(mp.find(curr+1) != mp.end()){
                    curr++;
                    currLen++;
                }
                maxLen = max(maxLen , currLen);
            }
        }
        return maxLen;
    }
};