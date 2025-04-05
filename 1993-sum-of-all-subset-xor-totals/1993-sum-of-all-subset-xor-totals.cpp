class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return XORSum(nums, 0, 0); 
    }

private:
    int XORSum(vector<int>& nums, int index, int currentXOR) {
        // Return currentXOR when all elements in nums are already considered
        if (index == nums.size()) return currentXOR;

        // Calculate sum of subset xor with current element
        int withElement = XORSum(nums, index + 1, currentXOR ^ nums[index]);

        // Calculate sum of subset xor without current element
        int withoutElement = XORSum(nums, index + 1, currentXOR);

        // Return sum of xor totals
        return withElement + withoutElement;
    }
};