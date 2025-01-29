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
        if(rank[rootX] < rank[rootY]){
            parent[rootY] = rootX;
        }
        else if(rank[rootX] > rank[rootY]){
              parent[rootX] = rootY;
        }
        else{
             parent[rootY] = rootX;
             rank[rootX]++;
        }
        return true;
    }  
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // given a undirected graph ok is conn and has no cycles ok. gievne started with as a tree n node 1 to n ok withb 1 add edge 2 diff vertices Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input. basicaly which edge we reomve whcih make grpag connencted the simple b=problme solving using with dfs or bfs basically we need to cerate adj lsit and edge putting into that create vecotr res and vis also make that we check that edge and check that the edge is coneected between them or not if that edge edge remove them means push bakc that edge tp rea and then resturn it ok. and for cyle detection we know union find is best as u know ok 
        int n = edges.size();
        UnionFind uf(n+1);
        for(auto e : edges){
            if(!uf.unite(e[0] , e[1])) return e;
        }
        return {};
    }
};