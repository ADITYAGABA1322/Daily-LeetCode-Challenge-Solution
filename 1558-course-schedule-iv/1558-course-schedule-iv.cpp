class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //same problme like we do in couse schedule 1 like what we ue the topological same like suing indegree concept and check that but listen their is min game change what the game is numCourses ok 0 n - 1 an preq arr ok ai and bi [0 , 1] 0 couse before 1 ok like in course schedule 1 now u see the game is that take the size of numcourses simple now waht we want to take prerequistes to check that whatis give n acc to that we want to check in queries ok so how tosolve this lets start first apporach waht we built like we want to start with n size of numcousreses and we dont want to create aj list we wna tot create vector<int>indegree ok we want to check in preq array and using queue we want to check in queue sotre curr of fornt and then it trough queries or we sotre query : qureies and take first start arr ok. ui and vi if we say or first and second and then check constion of ind and reutn it ok 
        vector<vector<bool>> reach( numCourses , vector<bool>(numCourses , false));
        for(auto pre : prerequisites) reach[pre[0]][pre[1]] = true;
        for(int k =0; k<numCourses; k++){
            for(int i=0; i<numCourses; i++){
                for(int j=0; j<numCourses; j++){
                    reach[i][j] = reach[i][j] || reach[i][k] && reach[k][j];
                }
            }
        }
        vector<bool> res;
        for(auto q : queries){
            res.push_back(reach[q[0]][q[1]]);
        }
        return res;
    }
};