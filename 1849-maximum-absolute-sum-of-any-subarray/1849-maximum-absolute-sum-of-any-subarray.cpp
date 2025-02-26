class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
          int maxSum = INT_MIN, currMaxSum = 0 , currMinSum = 0 , minSum = INT_MAX;

    for (int num : nums) {
        currMaxSum += num;
        maxSum = max(maxSum, currMaxSum);
        if (currMaxSum < 0) currMaxSum = 0; 
        currMinSum += num;
        minSum = min(minSum , currMinSum);
        if(currMinSum > 0) currMinSum = 0;
    }
    return  max(abs(maxSum) , abs(minSum));

    }
};