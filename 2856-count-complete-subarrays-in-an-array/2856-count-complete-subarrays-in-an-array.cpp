// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//         // Brute force
//         int n = nums.size();
//         int cnt = 0;
//         unordered_set<int> st;
//         for(auto num : nums) st.insert(num);
//         int distinctCnt = st.size();
//         for(int i=0; i<n; i++){
//             unordered_set<int> curr;
//             for(int j=i; j<n; j++){
//                 curr.insert(nums[j]);
//                 if(curr.size() == distinctCnt) cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // Optimized using sliding window
        int n = nums.size();
        unordered_set<int> st;
        for(auto num : nums) st.insert(num);
        int distinctCnt = st.size();
        //if(distinctCnt == 0) return n * (n+1) / 2;
        int cnt = 0;
        unordered_map<int , int> mp;
        int start = 0;
        for(int end = 0; end<n; end++){
            mp[nums[end]]++;
            while(mp.size() == distinctCnt){
                cnt += (n - end);
                mp[nums[start]]--;
                if(mp[nums[start]] == 0) mp.erase(nums[start]);
                start++;
            }
        }
        return cnt;
    }
};