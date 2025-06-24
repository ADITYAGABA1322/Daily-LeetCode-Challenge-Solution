class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        vector<int> keyIndices;
        for(int j=0; j<n; j++){
            if(nums[j] == key) keyIndices.push_back(j);
        }
        for(int i=0; i<n; i++){
            for(auto keyIndex: keyIndices){
                if(abs(i - keyIndex) <= k){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};