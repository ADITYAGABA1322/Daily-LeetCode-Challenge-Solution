class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operation = 0;
        for(auto num : nums){
            int rem = num%3;
            operation += min(rem , 3  - rem);
        
        }
        return operation;
    }
};