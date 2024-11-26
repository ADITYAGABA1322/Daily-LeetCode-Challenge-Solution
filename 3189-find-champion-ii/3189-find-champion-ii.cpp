class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n , 0);
        for(auto e : edges){
            indegree[e[1]]++;
        }
        int ans = -1;
        for(int i=0; i<n; i++){
             if(indegree[i] == 0){
             if(ans != -1) return -1;
             ans = i;           
        }
        }
        return ans;
    }
};