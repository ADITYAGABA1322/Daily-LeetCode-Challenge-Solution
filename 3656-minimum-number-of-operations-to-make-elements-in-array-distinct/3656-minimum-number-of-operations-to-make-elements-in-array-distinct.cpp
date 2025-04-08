class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int n  = nums.size();
        int cnt = 0;
    
        while(true){
            unordered_set<int> st;
            bool allDis = true;
            for(int i=3*cnt; i<n; i++){
                if(st.count(nums[i])){
                    allDis = false;
                    break;
                }
                st.insert(nums[i]);
            }
            if(allDis) return cnt;
            cnt++;
        }
        return cnt;
    }
};