class Solution {
public:
    typedef long long ll;
    typedef pair<long long , int> P;
    bool check(int mid , int n , ll k , unordered_map<int , vector<vector<int>>> &adj){
        vector<ll> res(n , LLONG_MAX);
        priority_queue<P , vector<P> , greater<P>> pq;
        res[0] = 0;
        pq.push({0 , 0});
        while(!pq.empty()){
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(d > k) return false;
            if(node == n-1) return true;
            // total cost reach from source to d
            if(res[node] < d) continue;
            for(auto &vec: adj[node]){
                int nei = vec[0] , cost = vec[1];
                if(cost < mid) continue;
                if(d+cost < res[nei]){
                    res[nei] = d+cost;
                    pq.push({d+cost , nei});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        // adj u -> {(v,cost) , (v', cost')}
        unordered_map<int , vector<vector<int>>> adj;
        int l = INT_MAX , r = 0;
        for(auto e: edges){
            int u = e[0] , v = e[1] , cost = e[2];
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v , cost});
            l = min(l , cost);
            r = max(r , cost);
        }
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(mid , n , k , adj)){
                ans = mid;
                l = mid+1;
            } else r = mid - 1;
        }
        return ans;
    }
};