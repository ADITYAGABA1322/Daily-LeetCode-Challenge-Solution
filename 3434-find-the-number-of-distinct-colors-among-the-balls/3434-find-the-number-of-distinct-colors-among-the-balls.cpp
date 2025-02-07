class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // find no of distinct  color balls ok we perform query in each we colr the ball x with color y  ok and distinct olcor among the balls ok like we have wuery contain duplicate things also we map here to make distcint means it.second == 1 not > 1 ok means acc to we find distinct color ok  we first nct the we need to create 2d pair mp i tink
        unordered_map<int , int> ballColor;
        unordered_map<int , int> colorCnt;
        vector<int> res;
        for(auto q : queries){
            int ball = q[0], color = q[1];
            if(ballColor.find(ball) != ballColor.end()){
                int oldBall = ballColor[ball];
                colorCnt[oldBall]--;
                if(colorCnt[oldBall] == 0) colorCnt.erase(oldBall);
            }
            ballColor[ball] = color;
            colorCnt[color]++;
            res.push_back(colorCnt.size());
        }
        return res;    
    }
};