class DSU{
public:
    vector<int> parent , rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n , 1);

        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x , int y){
        int x_parent = find(x); 
        int y_parent = find(y);

        if(x_parent == y_parent) return false;
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        } else{ 
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        return true;
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // m == 1 edges if they form cycle its not mst 
        // Binary Search on ans + DSU
        DSU dsu(n);
        for(auto e: edges){
            int u = e[0] , v = e[1] , s = e[2] , m = e[3];
            if(m == 1){
                if(dsu.find(u) == dsu.find(v)) return -1;
                dsu.Union(u , v);
            }
        }
        int l = 0; int r = 2*1e5 , res = -1;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(check(n , edges , k ,mid)){
                res = mid;
                l = mid+1;
            }else{
                r = mid -1;
            }
        }
        return res;
    }

    bool check(int n, vector<vector<int>>& edges, int k , int mid){
        DSU dsu(n);
        vector<vector<int>> upgradeCandidates;
           for(auto e: edges){
            int u = e[0] , v = e[1] , s = e[2] , m = e[3];
            if(m == 1){
                if(s < mid) return false;
                dsu.Union(u,v);
            } else {
                if(s>=mid){
                    dsu.Union(u , v);
                } else if(2*s >= mid){
                    upgradeCandidates.push_back({u , v});
                }
            }
        }

        for(auto e:  upgradeCandidates){
            int u = e[0] , v = e[1];
            if(dsu.find(u) != dsu.find(v)){
                if(k<=0) return false;
                dsu.Union(u , v);
                k--;
            }
        }

        int root = dsu.find(0);
        for(int node = 1; node < n; node++){
            if(dsu.find(node) != root) return false;
        }
        return true;
    }
};