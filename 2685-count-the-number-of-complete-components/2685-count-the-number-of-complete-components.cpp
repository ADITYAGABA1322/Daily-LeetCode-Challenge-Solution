class UnionFind{
    private:
    vector<int> parent , rank;
    public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n , 0);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int x){
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x , int y){
        int rootX = find(x) , rootY = find(y);
        if (rootX == rootY) return;
        if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else{
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto e : edges) uf.Union(e[0] , e[1]);
         // Count nodes in each component and edges between nodes in the same component
        unordered_map<int , int> compSize; //comp means components
        unordered_map<int , int> compEdges;
        for(int i=0; i<n; i++){
            int root = uf.find(i);
            compSize[root]++;
        }
        for(auto e : edges){
            int root = uf.find(e[0]);
            compEdges[root]++;
        }
        // Check if each component is complete
        int complete = 0;
        for(auto [root , size] : compSize){
            int reqEdges = size * (size-1)/2;
            if(compEdges[root] == reqEdges) complete++;
        }
        return complete;
    }
};