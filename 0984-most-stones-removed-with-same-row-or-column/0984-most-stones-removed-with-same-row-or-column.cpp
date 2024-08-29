class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // lts go throight question and think we go from stomes ok but you see its 2d plane i think graph and we can solve it ussing to create adj and edge on it and check if edges of x01 is quesl to x01 , x12 ir more like iny it remove or puhs and count ++ and ue map also
        unordered_map<int , vector<int>> rows , cols;
        for(auto stone : stones){
            rows[stone[0]].push_back(stone[1]);
            cols[stone[1]].push_back(stone[0]);
        }
        unordered_set<int> vis;
        int numofComp = 0;
        for(auto stone : stones){
            int x = stone[0] , y = stone[1];
            int key = x*1000+y;
            if(vis.find(key) == vis.end()){
                dfs(x , y , rows , cols ,  vis);
                numofComp++;
            }
        }
        return stones.size() - numofComp;
    }
private:
    void dfs(int x , int y , unordered_map<int , vector<int>>& rows , unordered_map<int , vector<int>>& cols , unordered_set<int>& vis){
        int key = x*1000+y;
        if(vis.find(key) != vis.end()) return;
        vis.insert(key);
        for(auto col : rows[x]) dfs(x , col , rows , cols , vis); 
        for(auto row : cols[y]) dfs(row , y , rows , cols , vis);
    }
};