class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size() , ans = 0 , sum = accumulate(nums.begin() , nums.end() , 0);
        int leftS = 0 , rightS = sum;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                if(leftS - rightS >= 0 && leftS - rightS <= 1) ans++;
                if(rightS - leftS >=0 && rightS - leftS <=1 ) ans++;
            } else{
                leftS += nums[i];
                rightS -= nums[i];
            }
            
        }
        return ans;
    }
};