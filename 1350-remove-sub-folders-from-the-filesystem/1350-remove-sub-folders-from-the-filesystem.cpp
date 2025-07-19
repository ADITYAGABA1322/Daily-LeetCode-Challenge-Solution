class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin() , folder.end());
        vector<string> res;
        string prev = "";
        for(auto f : folder){
            if(prev.empty() || f.find(prev + "/") != 0){
                res.push_back(f);
                prev = f;
            }
        }
        return res;
    }
};