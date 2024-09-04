class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // solve the problem using hashmap and check for if we commands -2 -1 move left and irhg t 90 degree well quite interesting problem 
        //Approach creating a map  or go through th commands and check srating on 0,0 point just chekc anbother if we find -1  and 02 on next wait we have onstacles also so we take care of this also like we wait map is going for direactions for noth east south and west we go anf find onstacle we stop and find the edulideian distance of the points ok 
        int n = commands.size();
        int dirIdx = 0;
        vector<pair<int , int>> dir = {{0,1} , {1,0} , {0,-1} , {-1,0}};
        unordered_set<string> obstacleSet;
        for(auto obstacle : obstacles){
            obstacleSet.insert(to_string(obstacle[0]) + ","  + to_string(obstacle[1]));
        }
        int x=0, y=0, maxD = 0;
        for(auto com : commands){
            if(com == -2) dirIdx = (dirIdx+3)%4;
            else if(com == -1) dirIdx = (dirIdx+1)%4;
            else{
                for(int i=0; i<com; i++){
                    int newX = x+dir[dirIdx].first;
                    int newY = y+dir[dirIdx].second;
                    if(obstacleSet.find(to_string(newX)  + ","  + to_string(newY)) == obstacleSet.end()){
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