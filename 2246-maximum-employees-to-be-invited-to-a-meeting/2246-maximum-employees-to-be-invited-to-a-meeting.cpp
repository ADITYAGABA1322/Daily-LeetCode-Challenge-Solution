class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        //we invite max no of emplyee according to given fav[i] and  Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself. acc to that contion means in table a person comes only sit to next their fav person means child and aprent we say like we say in grpah child only enter when parents are sit beside them menas sit  next to parent person ok like wise acc to graph we use bfs and 2nd thing their is a table emans the concept realted to linking and indegree concept we use it ok 
        int n = favorite.size();
        vector<int> inD(n , 0);
        for(int i=0; i<n; i++) inD[favorite[i]]++;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inD[i] == 0) q.push(i);
        }
        vector<int> depth(n , 1);
        while(!q.empty()){
            int currN = q.front();
            q.pop();
            int nextN = favorite[currN];
            depth[nextN] = max(depth[nextN] , depth[currN] + 1);
            if(--inD[nextN] == 0) q.push(nextN);
        }
        int longCycle = 0;
        int twoCycleInv = 0;
        for(int i=0; i<n; i++){
            if(inD[i] == 0) continue;
            int cycleLen = 0;
            int curr = i;
            while(inD[curr] != 0){
                inD[curr] = 0;
                cycleLen++;
                curr = favorite[curr];
            }
            if(cycleLen == 2){
                twoCycleInv += depth[i] + depth[favorite[i]];
            }else{
                longCycle = max(longCycle , cycleLen);
            }
        }
        return max(longCycle , twoCycleInv);
    }
};