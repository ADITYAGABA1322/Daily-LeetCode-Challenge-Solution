class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> positiveNumSet;
        for(auto num : nums){
            if(num > 0) positiveNumSet.emplace(num);
        }

        if(positiveNumSet.empty()){
            return *max_element(nums.begin() , nums.end());
        }
        return accumulate(positiveNumSet.begin() , positiveNumSet.end() , 0);
    }
};