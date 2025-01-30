class UnionFind{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    UnionFind(int n) : parent(n) , rank(n , 0){
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x , int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // given positive int n. ok. no of nodes again and undirected graph ok 1 to n nodes 2d int edges ok Divide the nodes of the graph into m groups (1-indexed) such that: htis one indicated directly comes in my mind is this is union find ok Each node in the graph belongs to exactly one group. For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.and return max no of gorups ok  now what we take n nodes and go through edges ok 
        UnionFind uf(n+1);
        vector<vector<int>> g(n+1);
        for(auto e : edges){
            int u = e[0] , v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
            uf.unite(u , v);
        }
        // find connnected components
        vector<vector<int>> comp(n+1);
        for(int i=1; i<=n; i++){
            int root = uf.find(i);
            comp[root].push_back(i);
        }
        // Function to perform BFS and find the maximum depth 
        auto bfs = [&](int start){
            vector<int> dis(n+1 , -1);
            queue<int>q;
            q.push(start);
            dis[start] = 0;
            int maxD = 0;
            while(!q.empty()){
                auto curr = q.front();
                q.pop();
                for(auto nei : g[curr]){
                    if(dis[nei] == -1 ){
                        dis[nei] = dis[curr] + 1;
                        maxD = max(maxD , dis[nei]);
                        q.push(nei);
                    } else if(dis[nei] == dis[curr]){
                        return -1; // Not bipartite
                    }
                }
            }
            return maxD + 1;// Number of groups is max depth + 1
        };
        // Calculate the maximum number of groups
        int maxGp = 0;
        for(auto c : comp){
            if(!c.empty()){
                int maxCompGp = 0;
                for(auto n : c){
                    int res = bfs(n);
                    if(res == -1) return -1;
                    maxCompGp = max(maxCompGp , res);
                }
                maxGp += maxCompGp;
            }
        }
        return maxGp;

    }
};