class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int minDis = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        int sum = abs(i - j) + abs(j - k) + abs(k - i);
                        minDis = min(minDis , sum);
                    }
                }
            }
        }
        return minDis == INT_MAX ? -1 : minDis;
    }
};