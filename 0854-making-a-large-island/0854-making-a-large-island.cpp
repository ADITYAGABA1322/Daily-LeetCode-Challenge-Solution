class UnionFind{
    private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    public:
    UnionFind(int n) : parent(n) , rank(n, 0) , size(n , 1){
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
        if(parent[rootX] > parent[rootY]){
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else if(parent[rootY] < rootX){
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else{
            parent[rootY] = rootX;
            rank[rootX]++;
            size[rootX] += size[rootY];
        }
        return true;
    }
    int getSize(int x){
        return size[find(x)];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        // given n*n grid ok. alow to change 0 to 1 ok return size of the largest island in grid ok simpoe find the 0 and reolace with 1 and connect them and return the cnt ok coonected graph  just follow the union find the n find the using union find and replace to unite them 
        int m = grid.size() , n = grid[0].size();
        UnionFind uf(m*n);
         // Directions for moving up, down, left, right
        vector<pair<int , int>> dir = {{-1, 0} , {1 , 0} , {0 , 1} , {0 , -1}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(auto [dx , dy] : dir){
                        int ni = i + dx;
                        int nj = j + dy;
                        if(ni >= 0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == 1){
                            uf.unite(i*n + j , ni*n + nj);
                        }
                    }
                }
                
            }
        }

        // Calculate the size of each island
        unordered_map<int , int> islandSz;
        int maxSz = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int root = uf.find(i*n+j);
                    islandSz[root] = uf.getSize(root);
                    maxSz= max(maxSz , islandSz[root]);
                }
            }
        }

        // Evaluate changing 0 to 1
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> neiIsland;
                    int potentialIslandSize = 1; // Changing this 0 to 1
                    for(auto[dx , dy] : dir){
                        int ni = i+dx;
                        int nj = j+dy;
                        if(ni >= 0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == 1){
                            int root = uf.find(ni*n + nj);
                            if(neiIsland.find(root) == neiIsland.end()){
                                neiIsland.insert(root);
                                potentialIslandSize += islandSz[root];
                            }
                        }
                    }
                    maxSz = max(maxSz , potentialIslandSize);

                }
            }
        }
    return maxSz;

    }
};