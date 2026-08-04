class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minValue = *min_element(nums.begin() , nums.end());
        int maxValue = *max_element(nums.begin() , nums.end());
        
        vector<bool> present(maxValue+1 , false);
        vector<int> ans;
        for(auto num : nums) present[num] = true;
        for(int i=minValue; i<=maxValue; i++){
            if(!present[i]) ans.push_back(i);
        }
        return ans;
    }
};