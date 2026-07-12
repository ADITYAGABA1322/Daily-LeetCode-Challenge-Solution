class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int , vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        int rank = 1;
        for(auto it : mp){
            for(auto idx : it.second){
                arr[idx] = rank;
            }
            rank++;
        }
        return arr;
    }
};