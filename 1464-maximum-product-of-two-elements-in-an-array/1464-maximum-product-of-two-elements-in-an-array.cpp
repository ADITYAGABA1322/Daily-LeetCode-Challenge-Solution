class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int prod1 =  nums[(n-1)]-1;
        int prod2 = nums[(n-2)] -1;
        return prod1*prod2;
    }
};