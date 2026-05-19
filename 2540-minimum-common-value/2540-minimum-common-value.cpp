class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin() , nums1.end());
        for(auto num : nums2){
            if(st.contains(num)) return num;
        }
        return -1;
    }
};