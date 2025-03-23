class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // we have bi dir raods ok and thier is atmost one road in 2 intersection amd you are gievn an int n 2d int array roads acc to given roads we dijkstra why because we have ui vi and time  there is a road between intersections ui and vi that takes time in minutes to travel and we travel from 0 to n-1 in shortest time ok. 
    // what we do in dijkstra algo like we now simple dijkstra find the shortest path ok we know and by find this path we need to find the ttoal no of ways to count the al shorted path simlar to that no whoch we find in first that shorted one ok and we in dijkstra algo approach using priority queue min heap and dist with long max we use long here because answer may be large, return it modulo 109 + 7. and we use u and v and weight as time u+time < v ok we find that and after we cnt the way ok and roads as edges and we declare graph or adj list list also ok and we solve it easily 
        const int MOD  = 1e9+7;
        vector<vector<pair<int , int>>> g(n);
        for(auto r : roads){
            int u = r[0] , v = r[1] , t = r[2];
            g[u].push_back({v , t});
            g[v].push_back({u , t});
        }
        vector<int>ways(n,0);
        ways[0] = 1;
        vector<long long> dist(n , LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;
        pq.push({0  , 0});
        while(!pq.empty()){
            auto [d , node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto [nei , time] : g[node]){
                if(dist[node] + time < dist[nei]){
                    dist[nei] = dist[node] + time;
                    ways[nei] = ways[node];
                    pq.push({dist[nei] , nei});
                }
                else if(dist[node] + time == dist[nei]){
                    ways[nei] = (ways[nei] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};