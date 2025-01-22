class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // now ok according to the problme we follow these condtions ok and must assign each cell a height in a way that follows these rules:

// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching). the given matrix follow the approach by using traverse the met by bfs means level order and check that givem mat isWater if strating is 0 means land 1 means water accrding to we follw the baove contion also give diff of height atmost 1 we using queue and traverse it and check the contion of neighbor and child if we say according that we get the output ok 
    int m = isWater.size() , n = isWater[0].size();
    vector<vector<int>> res(m , vector<int>(n , -1));
    vector<pair<int , int>> dir = {{1 , 0} , {0 , 1} , {-1 , 0}, {0 , -1}} ;
    queue<pair<int , int>> q;
    for(int i=0; i<m ;i++){
        for(int j=0; j<n; j++){
            if(isWater[i][j] == 1){
                res[i][j] = 0;
                q.push({i , j});
            }   
        }
    }
    while(!q.empty()){
        auto [x , y] = q.front();
        q.pop();
        for(auto [dx , dy] : dir){
            int nx = x + dx;
            int ny = y + dy;
            if(nx>=0 && nx<m && ny>=0 && ny<n && res[nx][ny] == -1){
                res[nx][ny] = res[x][y] + 1;
                q.push({nx , ny});
            }
        }   
    }
    return res;
    }
};