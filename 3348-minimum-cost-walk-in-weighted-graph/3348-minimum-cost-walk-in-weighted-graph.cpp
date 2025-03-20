class UnionFind{
    private:
    vector<int> parent , rank , weights;
    public:
    UnionFind(int n){
        parent = vector<int>(n);
        rank = vector<int>(n , 0);
        weights = vector<int>(n , INT_MAX);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int x){
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unions(int x , int y , int weight){
        int rootX = find(x);
        int rootY = find(y);
        if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else parent[rootY] = rootX;
        weights[rootX] = weights[rootY] = weights[rootX] & weights[rootY] & weight;
        //if(rank[rootX] == rank[rootY]) rank[rootX]++;
    }
    int minCost(int x , int y){
        if(x == y) return 0;
        if(find(x) != find(y)) return -1;
        return weights[find(x)];
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n);
        for(auto edge  : edges)  uf.unions(edge[0] , edge[1] , edge[2]);
        vector<int> res;
        for(auto q : query) res.push_back(uf.minCost(q[0] , q[1]));
        return res;
    }
};