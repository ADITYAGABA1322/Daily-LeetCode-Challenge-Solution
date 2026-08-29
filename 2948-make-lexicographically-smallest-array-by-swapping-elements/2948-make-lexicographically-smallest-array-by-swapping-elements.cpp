class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n) , rank(n, 0) {
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int x){
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x]; 
    }
    void unite(int x  , int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        UnionFind uf(n);
        vector<pair<int , int>> sortNums;
        for(int i=0; i<n; i++) sortNums.push_back({nums[i] , i});
        sort(sortNums.begin() , sortNums.end());
        for(int i=0; i<n-1; i++){
            if(abs(sortNums[i].first - sortNums[i+1].first) <= limit){
                uf.unite(sortNums[i].second , sortNums[i+1].second);
            }
        }
        unordered_map<int , vector<int>> gps;
        for(int i=0; i<n; i++){
            int root = uf.find(i);
            gps[root].push_back(nums[i]);
        }
        for(auto& [root , gp] : gps) sort(gp.begin() , gp.end());
        vector<int> res(n);
        unordered_map<int , int> index;
        for(int i=0; i<n; i++){
            int root = uf.find(i);
            res[i] = gps[root][index[root]++];
        }
        return res;
    }
};