class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // For this code, my approach is similar like you wanna go through a trade diagonally by traversing the path if we are traversing the path we know the element coming on diagonally side for that we go to just ate diagonally, but how if I am thinking about there is a old and even indices if I want to talk about the even one goes even an old ones goes old model concept similar kind of thing you are adding it we just two traverse seat according to the role and Colombia and do you want it done with that?
        int m = mat.size() , n = mat[0].size();
        vector<int> res;
        map<int , vector<int>> mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) mp[i+j].push_back(mat[i][j]);
        }
        for(auto [sum  , diag] : mp){
            if(sum % 2 == 0) reverse(diag.begin()  , diag.end());
            for(auto val : diag) res.push_back(val);
        }
        return res;
    }
};