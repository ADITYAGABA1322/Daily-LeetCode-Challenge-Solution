class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        priority_queue<pair<int , int>, vector<pair<int , int>> , greater<pair<int , int>>> pq;
        unordered_set<int> st;
        for(int i=0 ; i<n; i++) pq.push({nums[i] , i});
        while(!pq.empty()){
            auto [val , idx] = pq.top();
            pq.pop();

            if(st.count(idx)) continue;
            score += val;
            st.insert(idx);
            if(idx > 0) st.insert(idx - 1);
            if(idx < n-1) st.insert(idx + 1);
        }
        return score;
    }
};