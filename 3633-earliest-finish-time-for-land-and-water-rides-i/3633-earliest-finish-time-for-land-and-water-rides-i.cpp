class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int m = landStartTime.size() , n = waterStartTime.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int t1 = landStartTime[i] + landDuration[i];
                int t2 = waterStartTime[j] + waterDuration[j];
                int waterFirst = max(t2 , landStartTime[i]) + landDuration[i];
                int landFirst = max(t1 , waterStartTime[j]) + waterDuration[j];
                ans = min(ans , min(landFirst , waterFirst));
            }
        }
        return ans;
    }
};