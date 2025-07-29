class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n) , lastPos(30 , -1);
        for(int i=n-1; i>=0; i--){
            for(int bit = 0; bit < 30; bit++){
                if((nums[i] >> bit) & 1) lastPos[bit] = i;
            }
        
        int maxReach = i;
        for(int bit =0; bit < 30 ; bit++){
            if(lastPos[bit] != -1) maxReach = max(maxReach , lastPos[bit]);
        }
        res[i] = maxReach - i + 1;
        }
        return res;
    }
};