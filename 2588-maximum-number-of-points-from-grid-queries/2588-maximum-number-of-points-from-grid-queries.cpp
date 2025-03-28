class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // you are given m *n mat grid ok. queries of size k. ok  , find an arr ans of size k each int queries[i] start top left repeat the process ok if queries if i is strictly gt val of curr cell then u get 1 point  ok ets talk about the intuion and approach to solve this question ina simpler way first take first we want to check the queries size k we reutn that no of element means queries return but it do some thing first queries i element is greater curr top left elemnt of the mt means start ele of grid. if tha tok then move in 4 dir ok mat as u know we use bfs using queue for traversal and check in four dir create vector<pair<int>> dir -1 , 0 m  0 , -1 , 1 , 0 , 0 , 1 and iterate and cnt ++ acc to iteartion done we did it just follow the ele  if top left is less than quries i ok. 
        vector<pair<int , int>> dir = {{-1, 0}, {1 , 0} , {0,-1} , {0 , 1}};
        int m = grid.size() , n = grid[0].size();
        int k = queries.size();

        vector<int> res(k , 0);

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<>> pq;
        pq.push({grid[0][0] , 0});
        grid[0][0] = -1;
        int points = 0;
        vector<int> sortedQ = queries;
        sort(sortedQ.begin() , sortedQ.end());
        // map to store each res of query
        unordered_map<int , int> resQuery;
        for(auto q : sortedQ){
            while(!pq.empty() && pq.top().first < q){
                auto [val , pos] = pq.top();
                pq.pop();

                int x = pos/n , y = pos%n;
                points++;

                for(auto[dx , dy] : dir){
                    int nx = x+dx , ny = y+dy;
                    if(nx>= 0 && nx<m && ny>=0 && ny<n && grid[nx][ny] != -1){
                        pq.push({grid[nx][ny], nx*n + ny});
                        grid[nx][ny] = -1;
                    }
                }
                
            }
            resQuery[q] = points;
        }
        for(int i=0; i<k; i++){
            res[i] = resQuery[queries[i]];
        }
        return res;
    }
};