class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add virtual restrictions: building 1 = 0, building n = n-1
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // Left to right pass: cap each building based on left neighbor
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            int capped = restrictions[i - 1][1] + dist;
            restrictions[i][1] = min(restrictions[i][1], capped);
        }
        
        // Right to left pass: cap each building based on right neighbor
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            int capped = restrictions[i + 1][1] + dist;
            restrictions[i][1] = min(restrictions[i][1], capped);
        }
        
        // Now find the max peak between every adjacent pair
        int ans = 0;
        for (int i = 1; i < m; i++) {
            int id1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            int dist = id2 - id1;
            
            // Peak height reachable between these two capped points
            int peak = (h1 + h2 + dist) / 2;
            
            ans = max(ans, max(h1, h2));
            ans = max(ans, peak);
        }
        
        return ans;
    }
};