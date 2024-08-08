class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // lets build an approach or thought process
        // first what i do like i stroe size of matrix if cols and row;
        // next iteratre the matrix accroding to index of give rstart , cstart
        // but the rule i igo to the only clockiwse dirsction not in revrse wise 
        // rows*cols give matix size also adn if ewe go outsir we reriurnto  
        // just reutn res of 2d vector nd traversal res 
        vector<vector<int>> res;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int total = rows*cols;
        int x = rStart , y = cStart;
        int dir = 0 , steps = 1;
        res.push_back({x , y});
        while(res.size() < total){
            for(int i=0 ; i<2 ; i++){
                for(int j=0; j<steps; j++){
                    x += directions[dir][0];
                    y += directions[dir][1];
                    if(x >= 0 && x< rows && y>=0 && y<cols){
                        res.push_back({x , y});
                    }
                }
                dir = (dir+1)%4;
            }
            steps++;
        }
        return res;
    }
};