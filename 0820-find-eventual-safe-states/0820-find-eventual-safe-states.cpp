class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        // given directed graph of n nodes ok node form 0 to n-1 2d int arr g node aj i a node is terminal node ok no outgoing edges  node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node). return an arr safe nodes of the graph. The answer should be sorted in ascending order. the problem is solve with indegree and outdegree concept why beacuse we need to find no outgoing edges is terminal and safe node end with terminal node means lead to temrinal node ok. so using the graph bfs we use the concept of topological sorting like how should we connect the grpah first we need to adj list or 2d vector graph and iterate and cal indegree ot outddegree ok and using the queue and create node or child or cutt for  q.front() ele ok and then iterate curr or node or child or neighbor with g[curr] and check outdegree or indegree ok same like course schedule 1 and 2 ok 
        int n = g.size();
        vector<vector<int>> rg(n); // rg means reverse graph ok
        vector<int> indegree(n , 0);
        for(int u=0; u<n; u++){
            for(auto v : g[u]){
                rg[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> safeNodes; // this is a res vector which return it ok 
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            safeNodes.push_back(node); // nei for neighbor node ok
            for(auto nei : rg[node]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        sort(safeNodes.begin() , safeNodes.end());
        return safeNodes;
    }
};