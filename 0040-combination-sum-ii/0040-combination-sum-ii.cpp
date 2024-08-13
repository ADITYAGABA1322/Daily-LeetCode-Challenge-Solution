class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin() , candidates.end());
        vector<int> temp;
        helper(temp , candidates , target , 0);
        return res;
    }
    void helper(vector<int>& temp , vector<int>& candidates, int target , int idx){
        if(target == 0){ 
            res.push_back(temp);
        return;
        }
        if(target < 0) return;
        for(int i=idx; i<candidates.size(); i++){
            if(i> idx  && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            helper(temp , candidates ,   target - candidates[i] , i + 1);
            temp.pop_back();
        }
    }

};