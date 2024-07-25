class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> res;
        for(int i=0; i<nums.size(); i++) res.push_back(nums[i]);
        return res;
    }
};