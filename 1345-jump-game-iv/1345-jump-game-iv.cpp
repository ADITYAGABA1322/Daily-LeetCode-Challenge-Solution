class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        queue<int> q;
        q.push(0);
        int steps = 0;
        vector<bool> vis(n, false);
        vis[0] = true;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int idx = q.front();
                q.pop();
                if (idx == n - 1)
                    return steps;
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    q.push(idx - 1);
                    vis[idx - 1] = true;
                }
                if (idx + 1 < n && !vis[idx + 1]) {
                    q.push(idx + 1);
                    vis[idx + 1] = true;
                }
                for (int j = 0; j < mp[arr[idx]].size(); j++) {
                    if (!vis[mp[arr[idx]][j]]) {
                        q.push(mp[arr[idx]][j]);
                        vis[mp[arr[idx]][j]] = true;
                    }
                }
                mp[arr[idx]].clear();
            }
            steps++;
        }
        return steps;
    }
};