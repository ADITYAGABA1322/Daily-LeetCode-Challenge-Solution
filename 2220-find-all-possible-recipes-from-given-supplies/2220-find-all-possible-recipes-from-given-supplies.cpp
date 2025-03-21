class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // let me clearly say what they want the ing wroks as edges ok means this one connect to make the path of recipies or not and supplies is talk about weight if i want to reference them  and simple i say this ia genuine graph problme beacuse their is alinking of recipies towards the edges means ing ok so how to solve as you know this is a connected graph and we use topological sort also here using graph bfs here and perfomr indegree beacuse their is linking b/w recipes and ingredients ok and we perfrom the bfs and indegree in the queue using curr and check if that is woking using supplies if yes we retun that recipies if not empty array

        unordered_map<string , vector<string>> g; // ingredient -> recipes that use it
        unordered_map<string , int> inD; // recipe -> number of ingredients needed

        for(int i=0; i<recipes.size(); i++){
            inD[recipes[i]] = ingredients[i].size();
             for (auto ing : ingredients[i]) {
                g[ing].push_back(recipes[i]);
            }
        }

        queue<string> q;
        for(auto s : supplies){
            q.push(s);
        }
        vector<string> res;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(inD.find(curr) != inD.end() && inD[curr] == 0){
                res.push_back(curr);
            }
            for(auto recipie : g[curr]){
                inD[recipie]--;
                if(inD[recipie] == 0){
                    q.push(recipie);
                }
            }
        }
        return res;
    }
};