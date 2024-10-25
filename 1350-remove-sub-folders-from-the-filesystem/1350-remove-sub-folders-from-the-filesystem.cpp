class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin() , folder.end());
        string prev = "";
        vector<string> res;
        for(auto f : folder){
            if(prev.empty() || f.find(prev + '/')){
                res.push_back(f);
                prev = f;
            }
        }
        return res;
    }
};