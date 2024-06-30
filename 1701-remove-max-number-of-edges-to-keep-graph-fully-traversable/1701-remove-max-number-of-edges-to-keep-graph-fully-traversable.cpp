class UnionFind{
    vector<int> parent;
    vector<int> rank;

    int size = 0;

    public:
    UnionFind(int n){
       size = n;
        for(int i=0; i<=n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    int performUnion(int x , int y){
        x = find(x); y = find(y);
        
        if (x == y) {
            return 0;
        }
        
        if (rank[x] > rank[y]) {
         rank[x] += rank[y];
            parent[y] = x;
        } else {
            rank[y] += rank[x];
            parent[x] = y;
        }
        size--;
        return 1;
    }
     bool connected(){
        return size == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Different objects for Alice and Bob.
        UnionFind Alice(n), Bob(n);

        int edgesRequired = 0;
        // Perform union for edges of type = 3, for both Alice and Bob.
        for (vector<int>& edge : edges) {
            if (edge[0] == 3) {
                edgesRequired += (Alice.performUnion(edge[1], edge[2]) | Bob.performUnion(edge[1], edge[2]));
            }
        }

        // Perform union for Alice if type = 1 and for Bob if type = 2.
        for (vector<int>& edge : edges) {
            if (edge[0] == 1) {
                edgesRequired += Alice.performUnion(edge[1], edge[2]);
            } else if (edge[0] == 2) {
                edgesRequired += Bob.performUnion(edge[1], edge[2]);
            }
        }

        // Check if the Graphs for Alice and Bob have n - 1 edges or is a single component.
        if (Alice.connected() && Bob.connected()) {
            return edges.size() - edgesRequired;
        }
        
        return -1;
    }
};

