class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] != x) parent[x]= find(parent[x]);
        return parent[x];
    }
    void Union(int x , int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY) return;
        if(rank[rootX] < rank[rootY]) swap(rootX , rootY);
        parent[rootY] = rootX;
        if(rank[rootX] == rank[rootY]) rank[rootX]++;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank.resize(n , 0);

        for(int i=0; i<n; i++) parent[i] = i;
        for(auto &vec : allowedSwaps) Union(vec[0] , vec[1]);
        unordered_map<int , unordered_map<int , int>> groupFreq;
        for(int i=0; i<n; i++){
            int curr = source[i];
            int parent = find(i);
            groupFreq[parent][curr]++;
        }
        int hammingDistance = 0;
        for(int i=0; i<n; i++){
            int parent = find(i);
            if(groupFreq[parent][target[i]] > 0){
                groupFreq[parent][target[i]]--;
            }else {
                hammingDistance++;
            }
        }
        return hammingDistance;
    }
};