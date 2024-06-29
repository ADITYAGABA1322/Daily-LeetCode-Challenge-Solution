class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> freq(n, 0);
        for (auto road : roads){
            freq[road[0]]++;
            freq[road[1]]++;
        }
        sort(freq.begin(), freq.end());
        long long maxI = 0, val = 1;
        for (long long f : freq) {
            maxI +=  f*val++;
            
        }
        return maxI;
    }
};