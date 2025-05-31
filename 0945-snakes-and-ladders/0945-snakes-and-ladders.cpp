class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> moves(n*n+1);
        int i = n-1 , j = 0 , even;
        for(int k=1 ; k<=n*n; k++){
            moves[k] = board[i][j];
            if(even%2 == 0){
                j++;
            }
            else{
                j--;
            }
            if(j == n){
                i--;
                j--;
                even++;
            }
            if(j == -1){
                i--;
                j++;
                even++;
            }
        }
        queue<int> q;
        q.push(1);
        vector<bool> visited(n*n+1);
        visited[1] = true;
        int count = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int k=0 ; k<sz; k++){
                int curr = q.front();
                q.pop();
                if(curr == n*n){
                    return count;
                }
                for(int i=1; i<=6; i++){
                    int next = curr+i;
                    if(next > n*n){
                        break;
                    }
                    if(moves[next] != -1){
                        next = moves[next];
                    }
                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            count++;
        }
    return -1;
    }
};