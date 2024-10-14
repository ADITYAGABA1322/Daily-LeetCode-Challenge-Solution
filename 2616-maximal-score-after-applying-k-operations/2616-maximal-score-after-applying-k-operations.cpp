class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin() , nums.end());
        long long score = 0;
        while(k>0 && !pq.empty()){
            int maxEle = pq.top();
            pq.pop();
            score += maxEle;
            int newEle = ceil(maxEle / 3.0);
            pq.push(newEle);
            k--;
        }
        return score;
    }
};