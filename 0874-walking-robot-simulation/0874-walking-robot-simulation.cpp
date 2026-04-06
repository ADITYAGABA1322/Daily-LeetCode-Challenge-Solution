class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int dirIdx = 0;
        vector<pair<int , int>> dir = {{0,1} , {1,0} , {0,-1} , {-1,0}};
        unordered_set<string> obsSet;
        for(auto obs : obstacles){
            obsSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        int x = 0 , y = 0 , maxD = 0;
        for(auto com : commands){
            if(com == -2) dirIdx = (dirIdx + 3) % 4 ;
            else if(com == -1) dirIdx =  (dirIdx + 1) % 4;
            else {
                for(int i=0; i<com; i++){
                    int newX = x + dir[dirIdx].first;
                    int newY = y + dir[dirIdx].second;
                    if(obsSet.find(to_string(newX) + "," + to_string(newY)) == obsSet.end()){
                        x = newX;
                        y = newY;
                        maxD = max(maxD , x*x+y*y);
                    }
                    else break;
                }
            }
        }
        return maxD;
    }
};